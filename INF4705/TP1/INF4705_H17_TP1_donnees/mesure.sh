# Vérifions que nos algorithmes fonctionnent correctement
ex_folder="INF4705_H17_TP1_donnees"
#for algo in {"stdsort","insertion"}; do
 #   for ex in $(find $ex_folder -type f); do
        # sort -n -c permet de regarder si notre output est trié
  #      ./tp.sh -e ./${ex} -a $algo -p | sort -n -c
   # done
#done

# Mettons toutes nos mesures dans un fichier format csv
echo "algo,serie,taille,temps" > ./results.csv
# "stdsort","insertion",,"mergeSeuil"
for algo in {"insertion","stdsort"}; do
    for testset_folder in $(ls $ex_folder); do
        for ex in $(ls ${ex_folder}/${testset_folder}); do
            size=$(echo $ex | cut -d_ -f2)
            t=$(./tp.sh -e ./${ex_folder}/${testset_folder}/${ex} -a $algo -t)
            echo $algo,$testset_folder,$size,$t
        done
    done
done >> results.csv
