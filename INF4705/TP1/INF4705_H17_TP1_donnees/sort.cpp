// C program for insertion sort
#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <functional>
#include <chrono>
#include <iostream>
#include <algorithm>

using Int = long long;
using Algo = const std::function<void(std::vector<Int>&)>&;
//---------------------------------------------------------------------------------------
// 				Algorithme de stdsort
//---------------------------------------------------------------------------------------
void stdsort(std::vector<Int>& numbers) {
    std::sort(numbers.begin(), numbers.end());
}

//---------------------------------------------------------------------------------------
// 				Algorithme de insertionSort
//---------------------------------------------------------------------------------------
void insertion(std::vector<Int>& numbers)
{
   int i, key, j;
   for (i = 1; i < numbers.size(); i++)
   {
       key = numbers[i];
       j = i-1;
 
       /* Move elements of numbers[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && numbers[j] > key)
       {
           numbers[j+1] = numbers[j];
           j = j-1;
       }
       numbers[j+1] = key;
   }
}

//---------------------------------------------------------------------------------------
// Algorithme mergeSort
//---------------------------------------------------------------------------------------

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void mergeAlgorithm(std::vector<Int>& numbers, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = numbers[l + i];
    for (j = 0; j < n2; j++)
        R[j] = numbers[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            numbers[k] = L[i];
            i++;
        }
        else
        {
            numbers[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        numbers[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        numbers[k] = R[j];
        j++;
        k++;
    }
}


/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(std::vector<Int>& numbers, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(numbers, l, m);
        mergeSort(numbers, m+1, r);
 
        mergeAlgorithm(numbers, l, m, r);
    }
}

void merge(std::vector<Int>& numbers)
{
    mergeSort(numbers, 0, numbers.size() - 1);
}

//---------------------------------------------------------------------------------------
// Algorithme mergeSort avec seuil
//---------------------------------------------------------------------------------------



/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSortSeuil(std::vector<Int>& numbers, int l, int r)
{
    if ((l < r) && (numbers.size() > 19))
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(numbers, l, m);
        mergeSort(numbers, m+1, r);
 
        mergeAlgorithm(numbers, l, m, r);
    } 
    else 
    { 
	insertion(numbers);
    } 
}


void mergeSeuil(std::vector<Int>& numbers)
{
    mergeSortSeuil(numbers, 0, numbers.size() - 1);
}

//---------------------------------------------------------------------------------------
// 				UTILS
//---------------------------------------------------------------------------------------

int cmpfunc (const void * a, const void * b) {
    // cmpfunc doit renvoyer un int. On ne peut pas renvoyer directement
    // res puisqu'il pourrait y avoir un overflow. Nous devons faire
    // un traitement de plus qui ralentira le tri.
    auto res = *(Int*)a - *(Int*)b;
    if (res < 0) return -1;
    else if (res > 0) return 1;
    else return 0;
}

void c_qsort(std::vector<Int>& numbers) {
    qsort(&numbers[0], numbers.size(), sizeof(Int), cmpfunc);
}

void run(Algo algo, std::vector<Int>& numbers, bool print_res, bool print_time) {
    using namespace std::chrono;
    auto start = steady_clock::now();
    algo(numbers);
    auto end = steady_clock::now();

    if (print_time) {
        duration<double> s = end-start;
        std::cout << std::fixed << s.count() << std::endl;
    }

    if (print_res) {
        std::cout << std::fixed;
        for (auto n : numbers)
            std::cout << n << std::endl;
    }
}

int main(int argc, char *argv[]) {
    struct {
        std::string algo;
        std::string file_path;
        bool print_res{false};
        bool print_time{false};
    } prog_args;

    // Read program arguments
    for (int i=1; i<argc; i++) {
        std::string arg(argv[i]);
        if (arg == "-a") {
            prog_args.algo = argv[i+1]; i++;
        } else if (arg == "-e") {
            prog_args.file_path = argv[i+1]; i++;
        } else if (arg == "-p") {
            prog_args.print_res = true;
        } else if (arg == "-t") {
            prog_args.print_time = true;
        }
    }

    // Read numbers into vector
    std::vector<Int> numbers;
    {
        std::fstream ex_file(prog_args.file_path);
        Int n;
        while (ex_file >> n)
            numbers.push_back(n);
    }

    // Apply correct algorithm
    if (prog_args.algo == "stdsort")
        run(stdsort, numbers, prog_args.print_res, prog_args.print_time);
    else if(prog_args.algo == "insertion")
        run(insertion, numbers, prog_args.print_res, prog_args.print_time);
    else if(prog_args.algo == "merge")
        run(merge, numbers, prog_args.print_res, prog_args.print_time);
    else if(prog_args.algo == "mergeSeuil")
        run(mergeSeuil, numbers, prog_args.print_res, prog_args.print_time);

}


