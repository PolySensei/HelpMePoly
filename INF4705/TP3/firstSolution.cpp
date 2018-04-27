#include <stdio.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <functional>
#include <chrono>
#include <iostream>
#include <algorithm>
#include<string>
#include <stdlib.h>     
#include <time.h>    
#include <map>
#include <random>

using namespace std;

//---------------------------------------------------------------------------------------
// 				Structures and globals
//---------------------------------------------------------------------------------------

// h w d
struct Bloc {
	Bloc(int in_h, int in_w, int in_d) {
		h = in_h;
		w = in_w;
		d = in_d;
	}
    	int h;
	int w;
	int d;
};

using Int = long long;
using Algo = const std::function<void(std::vector<Bloc>&)>&;

unsigned int numberOfBlocs;
unsigned int maxHeight;

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

void run(Algo algo, std::vector<Bloc>& blocs, bool print_res, bool print_time) {
    using namespace std::chrono;
    auto start = steady_clock::now();
    algo(blocs);
    auto end = steady_clock::now();

    if (print_time) {
        duration<double> s = end-start;
        std::cout << std::fixed << s.count() << std::endl;
    }

    if (print_res) {
        std::cout << std::fixed;
        for (auto bloc : blocs)
            std::cout << bloc.h << "" << bloc.w  << "" << bloc.d  << std::endl;
    }
}

//---------------------------------------------------------------------------------------
// 				HELPERS
//---------------------------------------------------------------------------------------
bool sortByLxP (Bloc first, Bloc second) { 
	return ((second.w*second.d) < (first.w*first.d)); 
}

void fillData(std::vector<Bloc>& blocs, const string& filename) {
        std::fstream ex_file(filename);
        int height, width, depth;

	ex_file >> numberOfBlocs;
	std::cout << "numberOfBlocs " << numberOfBlocs << std::endl;
	ex_file >> maxHeight;
	std::cout << "maxHeight " << maxHeight << std::endl;

        while (ex_file >> height >> width >> depth) {
		Bloc newBloc = Bloc(height, width, depth);
            	blocs.push_back(newBloc);
	}
   	for ( int i = 0; i < blocs.size(); i++ ) {
         	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	}
}

int getBlocsHeight(std::vector<Bloc>& blocs) {
	int height = 0;
	for (int i = 0; i < blocs.size(); i++ ) {
		height += blocs[i].h;
	}
	return height;
}

int pushTower(std::vector<Bloc>& blocs, std::vector<std::vector<Bloc>>& towers, int index, int height) {
	std::vector<Bloc> solution;
	int currentHeight = heightCandidate - blocs[indexHeightCandidate].h;
	solution.push_back(blocs[indexHeightCandidate]);
   	for (int i = indexHeightCandidate - 1 ; i >= 0 ; i--)
	{
		if(currentHeight == optimizedValues[i]) 
		{
			solution.push_back(blocs[i]);
			currentHeight -= blocs[i].h;
		}
   	}
}

//---------------------------------------------------------------------------------------
// 				Algorithme winner
//---------------------------------------------------------------------------------------

void winner(std::vector<Bloc>& blocs)
{
	std::sort(blocs.begin(), blocs.end(), sortByLxP);
   	std::vector<int> optimizedValues;
	std::vector<std::vector<Bloc>> towers;
   	for (int i = 0; i < blocs.size(); i++ )
	{
      		optimizedValues.push_back(blocs[i].h);
	}
 
	while(blocs.size() > 0) 
	{
		int heightCandidate = 0;
		int indexHeightCandidate = 0;
   		for (int i = 1; i < blocs.size(); i++ ) 
		{
      			for (int j = 0; j < i; j++ ) 
			{
         			if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (optimizedValues[i] < (optimizedValues[j] + blocs[i].h)) )
         			{
                			optimizedValues[i] = optimizedValues[j] + blocs[i].h;
					if(optimizedValues[i] == maxHeight) 
					{
						heightCandidate = maxHeight;
						indexHeightCandidate = i;
						break;
					}
				}
         		}
		}
/*
   	int max = -1;
	int indexMaxHeight = 0;
   	for ( int i = 0; i < blocs.size(); i++ ) {
		std::cout << "optimizedValues = " << optimizedValues[i] << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
      		if ( max < optimizedValues[i] ) {
         		max = optimizedValues[i];
			indexMaxHeight = i;
		}
   	}
*/


		
		towers.push_back(solution);
	}
/*	blocs = solution;
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int i = 0; i < blocs.size(); i++ ) {
         	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	}

  	std::cout << "Hauteur real maximale : " << max << std::endl;
	std::cout << "Hauteur blocs maximale : " << getBlocsHeight(blocs) << std::endl;
*/
}

//---------------------------------------------------------------------------------------
// 				MAIN
//---------------------------------------------------------------------------------------

int main()
{
	std::vector<Bloc> blocs;
	fillData(blocs, "b200_100000_0");
	winner(blocs);
  	return 0;
}

