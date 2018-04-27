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

// h l p
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

bool sortByLxP (Bloc first, Bloc second) { return ((second.w*second.d) < (first.w*first.d)); }
//---------------------------------------------------------------------------------------
// 				Algorithme vorace
//---------------------------------------------------------------------------------------
void vorace(std::vector<Bloc>& blocs)
{
  	/* initialize random seed: */
  	srand (time(NULL));
	std::sort (blocs.begin(), blocs.end(), sortByLxP);
	std::vector<Bloc> solution;
	int hauteur = 0;
	for (int i = 0; i < blocs.size(); i++ ) {

		int probability = rand() % 100 + 1;
		if(probability < 80) {
			if(solution.size() == 0 || ((blocs[i].w < solution.back().w) && (blocs[i].d < solution.back().d))) {
				solution.push_back(blocs[i]);
				hauteur += blocs[i].h;
				
			}
		} 
	}
	blocs.clear();
	for (int i = solution.size() - 1; i >= 0 ; i-- ) {
		blocs.push_back(solution[i]);
	}

}

//---------------------------------------------------------------------------------------
// 				Algorithme progdyn
//---------------------------------------------------------------------------------------
void progdyn(std::vector<Bloc>& blocs)
{
	std::sort (blocs.begin(), blocs.end(), sortByLxP);
   	std::vector<int> optimizedValues;

   	for (int i = 0; i < blocs.size(); i++ )
      		optimizedValues.push_back(blocs[i].h);
 

   	for (int i = 1; i < blocs.size(); i++ ) {
      		for (int j = 0; j < i; j++ ) {
         		if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (optimizedValues[i] < (optimizedValues[j] + blocs[i].h)) )
         		{
                		optimizedValues[i] = optimizedValues[j] + blocs[i].h;
         		}
		}
	}

   	int max = -1;
	int indexMaxHeight = 0;
   	for ( int i = 0; i < blocs.size(); i++ ) {
      		if ( max < optimizedValues[i] ) {
         		max = optimizedValues[i];
			indexMaxHeight = i;
		}
   	}
	std::vector<Bloc> solution;
	int currentHeight = max - blocs[indexMaxHeight].h;
	solution.push_back(blocs[indexMaxHeight]);
   	for (int i = indexMaxHeight - 1 ; i >= 0 ; i--) {
		if(currentHeight == optimizedValues[i]) {
			solution.push_back(blocs[i]);
			currentHeight -= blocs[i].h;
		} 
   	}
	blocs = solution;
}

//---------------------------------------------------------------------------------------
// 				Algorithme tabou
//---------------------------------------------------------------------------------------

void swipeData(std::vector<int>& tour, std::map<unsigned int, int>& tabou, std::vector<Bloc>& blocs, int index) {
	if(index < (tour.size() - 1)) {
    		const int range_from  = 7;
    		const int range_to    = 10;
    		std::random_device rand_dev;
    		std::mt19937 generator(rand_dev());
    		std::uniform_int_distribution<int>  distr(range_from, range_to);
		int iterationTabou = distr(generator);
		int k = index + 1;
		 while((k < tour.size()) && (tour.size() > 0)) {
			if((blocs[tour[k]].w >= blocs[tour[index]].w) || (blocs[tour[k]].d >= blocs[tour[index]].d)) {
				tabou.insert ( std::pair<unsigned int,int>(tour[0],iterationTabou) );
				tour.erase(tour.begin() + k);
			} else {
				break;
			}
		}
	}
}

void decrementIteration(std::map<unsigned int, int>& tabou) {
	std::map<unsigned int, int>::iterator it = tabou.begin();
	while(it != tabou.end()) {
		it->second = it->second - 1;
		if(it->second <= 0) {
			tabou.erase(it);
		} else {
			it++;
		}
	}
}

int getHeight(std::vector<int>& tour, std::vector<Bloc>& blocs) {
	int height = 0;
	for (int i = 0; i < tour.size(); i++ ) {
		height += blocs[tour[i]].h;
	}
	return height;
}

void tabou(std::vector<Bloc>& blocs)
{
	std::vector<int> solutionTour;
	std::vector<int> tempTour;
	std::vector<int> bestTempTour;
	std::vector<int> finalTour;	
	std::map<unsigned int,int> solutionTabou;
	std::map<unsigned int,int> tempTabou;
	std::map<unsigned int,int> bestTempTabou;
	for (int iteration = 0; iteration < 100; iteration++ ) {
		int bestTempHeight = 0;
		for (int index = 0; index < blocs.size(); index++ ) {
			tempTour = solutionTour;
			tempTabou = solutionTabou;
			if (((std::find(tempTour.begin(), tempTour.end(), index) == tempTour.end()) && (tempTabou.find(index) == tempTabou.end()))) {
				int i = tempTour.size() - 1;
				for (; i >= 0; i-- ) {
					if((blocs[tempTour[i]].w > blocs[index].w) && (blocs[tempTour[i]].d > blocs[index].d)) {
						tempTour.insert(tempTour.begin() + i + 1, index);
						swipeData(tempTour, tempTabou, blocs, i + 1);
						break;
					}
				}
				if(i < 0) {
					tempTour.insert(tempTour.begin(), index);
					if(tempTour.size() > 1) {
						swipeData(tempTour, tempTabou, blocs, 0);
					}
				}

			}
			int newHeight = getHeight(tempTour, blocs);
			if(newHeight > bestTempHeight) {
				bestTempHeight = newHeight;
				bestTempTour = tempTour;
				bestTempTabou = tempTabou;
			}
		}
		if (getHeight(solutionTour, blocs) < getHeight(bestTempTour, blocs)) {
			iteration = 0;
			finalTour = bestTempTour;
		}
		solutionTour = bestTempTour;
		solutionTabou = bestTempTabou;
		bestTempTour.clear();
		bestTempTabou.clear();
		decrementIteration(solutionTabou);
	}

	std::vector<Bloc> solution;
	for (int l = finalTour.size() - 1; l >= 0 ; l-- ) {
		solution.push_back(blocs[finalTour[l]]);
	}
	blocs = solution;
}

//---------------------------------------------------------------------------------------
// 				UTILS
//---------------------------------------------------------------------------------------

int getBlocsHeight(std::vector<Bloc>& blocs) {
	int height = 0;
	for (int i = 0; i < blocs.size(); i++ ) {
		height += blocs[i].h;
	}
	return height;
}

void run(Algo algo, std::vector<Bloc>& blocs, bool print_res, bool print_time, bool print_height) {
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
        for ( int i = blocs.size() -1; i >= 0; i-- ) {	
            	std::cout << "h : " << blocs[i].h << " w : " << blocs[i].w << " d : " << blocs[i].d << std::endl;
	}
    }
    if (print_height) {
	std::cout << std::fixed << getBlocsHeight(blocs) << std::endl;
    }
}

int main(int argc, char *argv[]) {
    struct {
        std::string algo;
        std::string file_path;
        bool print_res{false};
        bool print_time{false};
	bool print_height{false};
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
        } else if (arg == "-h") {
            prog_args.print_height = true;
        }
    }

    // Read blocs into vector
    std::vector<Bloc> blocs;
    {
        std::fstream ex_file(prog_args.file_path);
        int h,w,d;
        while (ex_file >> h >> w >> d)
            blocs.push_back(Bloc(h,w,d));
    }

    // Apply correct algorithm
    if (prog_args.algo == "vorace")
        run(vorace, blocs, prog_args.print_res, prog_args.print_time, prog_args.print_height);
    else if(prog_args.algo == "progdyn")
        run(progdyn, blocs, prog_args.print_res, prog_args.print_time, prog_args.print_height);
    else if(prog_args.algo == "tabou")
	run(tabou, blocs, prog_args.print_res, prog_args.print_time, prog_args.print_height);
}


