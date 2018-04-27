/*
 * memutil.c
 *
 *  Created on: Jun 3, 2013
  *      Author: Francis Giraldeau <francis.giraldeau@polymtl.ca>
 */

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include "memutil.h"

memutil_opts_t opts;

char *units_iec[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB" };

static memutil_chunk_t chunk_def[] = {
    { .type = CHUNK_BYTE, .name = "byte", .bytes = 1 },
    { .type = CHUNK_WORD, .name = "word", .bytes = sizeof(long) },
    { .type = CHUNK_PAGE, .name = "page", .bytes = PAGE_SIZE },
    { .type = CHUNK_HUGE, .name = "huge", .bytes = (1 << 20) },
};

void human_size(size_t size, char **str) {
    int unit = 0;
    size_t s = size;
    while(s > (1 << 10)) {
        s = s >> 10;
        unit++;
    }
    // 10 chars is always enough: number (4) + space (1)+ unit (3) + \0 (1)
    *str = malloc(10);
    sprintf(*str, "%lu %s", s, units_iec[unit]);
}

void print_stack_limit(char *msg) {
    struct rlimit limit;
    char *cur, *max;
    getrlimit(RLIMIT_STACK, &limit);
    human_size(limit.rlim_cur, &cur);
    human_size(limit.rlim_max, &max);
    printf("stack limit %-10s soft=%-10s hard=%-10s\n", msg, cur, max);
    free(cur);
    free(max);
}

void set_stack_limit(size_t size) {
    struct rlimit limit;
    getrlimit(RLIMIT_STACK, &limit);
    limit.rlim_cur = size;
    print_stack_limit("before");
    setrlimit(RLIMIT_STACK, &limit);
    print_stack_limit("after");
}

void fill(char *buf, int size) {
    volatile int i;
    for (i = 0; i < size; i++) {
        buf[i] = i;
    }
}

void do_sleep(memutil_opts_t *opts) {
    if (opts->delay.tv_nsec > 0)
        nanosleep(&opts->delay, NULL);
}

void memutil_init(memutil_opts_t *opts) {
    // allocate buffer to save references to chunks
    int n = opts->max / opts->chunk_type->bytes;
    opts->data = malloc(n * sizeof(char *));
    opts->data_len = n;

    // Set malloc option for trim threshold
    mallopt(M_TRIM_THRESHOLD, opts->trim);

    // if stack experiment, make sure the stack is big enough
    if (!opts->on_heap) {
        int depth = opts->max / opts->chunk_type->bytes;
        set_stack_limit(opts->max * 2 + 128 * depth + PAGE_SIZE * 10);
    }
}

void memutil_destroy(memutil_opts_t *opts) {
    free(opts->data);
}

memutil_chunk_t *memutil_chunk_from_name(char *name) {
    int i;
    for (i = 0; i < CHUNK_LAST; i++) {
        if (strcmp(chunk_def[i].name, name) == 0) {
            return &chunk_def[i];
        }
    }
    return CHUNK_BYTE;
}

void memutil_grow_heap(memutil_opts_t *opts) {
    int i;
    int size = opts->chunk_type->bytes;

    if (opts->verbose)
        DEBUG("grow_heap_%s %d * %d malloc", opts->chunk_type->name, opts->data_len, size);
    for (i = 0; i < opts->data_len; i++) {
        opts->data[i] = malloc(size);
        do_sleep(opts);
    }

    if (opts->fill) {
        if (opts->verbose)
            DEBUG("grow_heap_%s %d * %d fill", opts->chunk_type->name, opts->data_len, size);
        for (i = 0; i < opts->data_len; i++) {
            fill(opts->data[i], size);
            do_sleep(opts);
        }
    }

    if (opts->verbose)
        DEBUG("grow_heap_%s %d * %d free", opts->chunk_type->name, opts->data_len, size);
    for (i = 0; i < opts->data_len; i++) {
        free(opts->data[i]);
        do_sleep(opts);
    }
}

static unsigned long tos;

#define grow_stack_generic(name, size) \
void _grow_stack_##name(memutil_opts_t *opts, int depth) { \
    do_sleep(opts); \
    char buf[size]; \
    opts->data[depth - 1] = buf; \
    --depth; \
    if (depth > 0) { \
    _grow_stack_##name(opts, depth); \
    } else { \
        if (opts->verbose) { \
            register unsigned long rsp asm("rsp"); \
            DEBUG("grow_stack_" #name" %10ld %10d", \
                    tos - rsp, depth); \
        } \
        if (opts->fill) { \
            int i; \
            for (i = 0; i < opts->data_len; i++) { \
                fill(opts->data[i], size); \
                do_sleep(opts); \
            } \
        } \
    } \
    do_sleep(opts); \
}

/* keep in sync with chunk_def */
grow_stack_generic(byte, 1)
grow_stack_generic(word, sizeof(long))
grow_stack_generic(page, PAGE_SIZE)
grow_stack_generic(huge, 1 << 20)

void memutil_grow_stack(memutil_opts_t *opts) {
    register unsigned long rsp asm("rsp");
    tos = rsp;
    int depth = opts->data_len;
    if (opts->verbose)
        DEBUG("grow_stack_%s %10ld %10d", opts->chunk_type->name, tos - rsp, depth);
    switch(opts->chunk_type->type) {
    case CHUNK_BYTE:
        _grow_stack_byte(opts, depth);
        break;
    case CHUNK_WORD:
        _grow_stack_word(opts, depth);
        break;
    case CHUNK_PAGE:
        _grow_stack_page(opts, depth);
        break;
    case CHUNK_HUGE:
        _grow_stack_huge(opts, depth);
        break;
    default:
        break;
    }
}
