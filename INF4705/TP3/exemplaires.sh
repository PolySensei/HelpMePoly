#!/bin/bash
for n in {100,500,1000,5000,10000,50000,100000}; do
    for i in {1..10}; do
        # Génération d'une permutation de 1 à 3n
        shuf -i 1-$((3*$n)) |
        # Regroupement par bloc de 3
        awk 'BEGIN {i=0} {printf $1; if (++i%3==0) printf "\n"; else printf " "}' |
    # On génère trois orientations différentes
        awk '{
        printf $1; if ($2 < $3) print " "$2" "$3; else print " "$3" "$2;
        printf $2; if ($1 < $3) print " "$1" "$3; else print " "$3" "$1;
        printf $3; if ($1 < $2) print " "$1" "$2; else print " "$2" "$1;
    }' > b${n}_${i}.txt
    done
done
