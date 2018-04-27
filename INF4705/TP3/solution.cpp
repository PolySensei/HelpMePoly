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
	Bloc(int in_h, int in_w, int in_d) 
	{
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
std::vector<std::vector<Bloc>> finalTowers;

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

void run(Algo algo, std::vector<Bloc>& blocs, bool print_res, bool print_time) 
{
    	using namespace std::chrono;
    	auto start = steady_clock::now();
    	algo(blocs);
	auto end = steady_clock::now();

    	if (print_time) 
	{
        	duration<double> s = end-start;
        	std::cout << std::fixed << s.count() << std::endl;
    	}

    	if (print_res) 
	{
        	std::cout << std::fixed;
        	for (auto bloc : blocs)
            		std::cout << bloc.h << "" << bloc.w  << "" << bloc.d  << std::endl;
    	}
}

//---------------------------------------------------------------------------------------
// 				HELPERS
//---------------------------------------------------------------------------------------
int getBlocsHeight(std::vector<Bloc>& blocs) 
{
	int height = 0;
	for (int i = 0; i < blocs.size(); i++ ) 
	{
		height += blocs[i].h;
	}
	return height;
}

bool sortByLxP (Bloc first, Bloc second) { 
	return ((second.w*second.d) < (first.w*first.d)); 
}

bool sortByHeight (std::vector<Bloc>& first, std::vector<Bloc>& second) { 
	return (getBlocsHeight(second) < getBlocsHeight(first)); 
}

void fillData(std::vector<Bloc>& blocs, const string& filename) {
        std::fstream ex_file(filename);
        int height, width, depth;

	ex_file >> numberOfBlocs;
	//std::cout << "numberOfBlocs " << numberOfBlocs << std::endl;
	ex_file >> maxHeight;
	//std::cout << "maxHeight " << maxHeight << std::endl;

        while (ex_file >> height >> width >> depth) 
	{
		Bloc newBloc = Bloc(height, width, depth);
            	blocs.push_back(newBloc);
	}
/*   	for ( int i = 0; i < blocs.size(); i++ ) 
	{
         	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	}*/
}

void splitTowers(std::vector<Bloc>& solution) 
{
	std::vector<Bloc> tower;
	int height = 0;
	int push = 0;
   	for (int i = 0 ; i < solution.size() ; i++)
	{
		height += solution[i].h;
		if(height <= maxHeight) 
		{
			tower.push_back(solution[i]);

		} 
		else 
		{
			finalTowers.push_back(tower);
			height = solution[i].h;
			tower.clear();
			tower.push_back(solution[i]);
		}
   	}
	if(tower.size() > 0) {
		finalTowers.push_back(tower);
	}
}

void removeBlocs(std::vector<Bloc>& blocs, std::vector<int>& indexToBeRemoved) 
{
   	for (int i = 0 ; i < indexToBeRemoved.size() ; i++)
	{
		blocs.erase(blocs.begin() + indexToBeRemoved[i]);
   	}
}

void printTower(std::vector<Bloc>& tower) 
{
	numberOfBlocs += tower.size();
	std::cout << "---- Size --- " << tower.size() << "---- Height --- " << getBlocsHeight(tower) <<std::endl;
        for (int i = 0; i < tower.size(); i++) 
	{	
            	std::cout << tower[i].h << " " << tower[i].w << " " << tower[i].d << std::endl;
	}
}

void printTowers() 
{
	numberOfBlocs = 0;
   	for (int i = 0 ; i < finalTowers.size() ; i++)
	{
		printTower(finalTowers[i]);
   	}
	std::cout << "---- finalTowers size --- " << finalTowers.size() << std::endl;
	std::cout << "---- numberOfBlocs --- " << numberOfBlocs << std::endl;
	std::cout << "---- maxHeight --- " << maxHeight << std::endl;

	std::cout << "fin" << std::endl;
}

bool tryInsertBloc(std::vector<Bloc>& tower, Bloc bloc) 
{
	if((tower[tower.size()-1].w < bloc.w) && (tower[tower.size()-1].d < bloc.d)) 
	{
		tower.push_back(bloc);
		return true;
	}
	for (int i = 0 ; i < tower.size() ; i++) 
	{
		if((tower[i].w > bloc.w) && (tower[i].d > bloc.d)) 
		{
			if (i == 0) 
			{
				tower.insert(tower.begin(), bloc);
				return true;
			} 
			else if ((tower[i-1].w < bloc.w) && (tower[i-1].d < bloc.d)) 
			{
				tower.insert(tower.begin() + i, bloc);
				return true;
			}
		}
	}
	return false;
}

void optimiseSolution()
{
	for (int i = finalTowers.size() - 1 ; i >= 1 ; i--) 
	{
		for (int j = finalTowers[i].size() - 1 ; j >= 0  ; j--) 
		{	
			bool isBlocInserted = false;
			for (int k = 0 ; k < i ; k++) 
			{	
				if((finalTowers[i][j].h + getBlocsHeight(finalTowers[k])) <= maxHeight) 
				{
					isBlocInserted = tryInsertBloc(finalTowers[k], finalTowers[i][j]);
					if (isBlocInserted) 
					{
						finalTowers[i].erase(finalTowers[i].begin() + j);
						break;
					}
				}
			}
			if (finalTowers[i].empty()) 
			{
				finalTowers.erase(finalTowers.begin() + i);

			}
		}
	}
}

//---------------------------------------------------------------------------------------
// 				Algorithme winner
//---------------------------------------------------------------------------------------
void winner(std::vector<Bloc>& blocs)
{
	
	std::sort (blocs.begin(), blocs.end(), sortByLxP);
	while(!blocs.empty()) {
   		std::vector<int> optimizedValues;
   		for (int i = 0; i < blocs.size(); i++)
      			optimizedValues.push_back(blocs[i].h);
 

   		for (int i = 1; i < blocs.size(); i++) 
		{
      			for (int j = 0; j < i; j++) 
			{
         			if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (optimizedValues[i] < (optimizedValues[j] + blocs[i].h)) )
         			{
                			optimizedValues[i] = optimizedValues[j] + blocs[i].h;
         			}
			}
		}

   		int max = -1;
		int indexMaxHeight = 0;
   		for (int i = 0; i < blocs.size(); i++) 
		{
      			if (max < optimizedValues[i]) 
			{
         			max = optimizedValues[i];
				indexMaxHeight = i;
			}
   		}

		std::vector<Bloc> solution;
		std::vector<int> indexToBeRemoved;
		int currentHeight = max - blocs[indexMaxHeight].h;
		solution.push_back(blocs[indexMaxHeight]);
		indexToBeRemoved.push_back(indexMaxHeight);
   		for (int i = indexMaxHeight - 1 ; i >= 0 ; i--) 
		{
			if(currentHeight == optimizedValues[i]) 
			{
				solution.push_back(blocs[i]);
				currentHeight -= blocs[i].h;
				indexToBeRemoved.push_back(i);
			} 
   		}
		splitTowers(solution);
		//cout << "solution size " << solution.size() << std::endl;
		//cout << "indexToBeRemoved size " << indexToBeRemoved.size() << std::endl;
		//cout << "blocs size before remove " << blocs.size() << std::endl;
		removeBlocs(blocs,indexToBeRemoved);
		//cout << "blocs size after remove " << blocs.size() << std::endl;
		//cout << "indexToBeRemoved" << indexToBeRemoved.size() << std::endl;
		//printTower(solution);
	}
	std::sort (finalTowers.begin(), finalTowers.end(), sortByHeight);
	optimiseSolution();
}

//---------------------------------------------------------------------------------------
// 				MAIN
//---------------------------------------------------------------------------------------

int main()
{
	std::vector<Bloc> blocs;
	fillData(blocs, "b200_100000_0");
	winner(blocs);
	printTowers();
  	return 0;
}


