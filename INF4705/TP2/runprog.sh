# Vérifions que nos algorithmes fonctionnent correctement
ex_folder="INF4705_H17_TP2_donnees"

# Mettons toutes nos mesures dans un fichier format csv
echo "algo,taille,temps,hauteur" > ./results.csv
# "vorace","progdyn",,"tabou"
    for ex in $(ls ${ex_folder}); do
            size=$(echo $ex | cut -d_ -f1 | cut -db -f2)
            str=$(./tp.sh -e ./${ex_folder}/${testset_folder}/${ex} -a vorace -t -h)
			set -- "$str" 
			IFS=; declare -a arr=($*) 
			arr=($str)
				t=${arr[0]}
				h=${arr[1]}
            echo vorace,$size,$t,$h
    done >> results.csv

#tr=$(./tp.sh -a $algo -e ./${ex_folder}/${ex} -p -t) 

