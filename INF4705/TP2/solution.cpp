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
std::cout << "Hauteur maximale : " << blocs.size() << std::endl;
std::cout << "Hauteur maximale : " << solution.size() << std::endl;
	for (int i = solution.size() - 1; i >= 0 ; i-- ) {
		blocs.push_back(solution[i]);
	}
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int i = 0 ; i < blocs.size(); i++ ) {
         	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	}
	std::cout << "Hauteur maximale : " << hauteur << std::endl;
}

//---------------------------------------------------------------------------------------
// 				Algorithme progdyn
//---------------------------------------------------------------------------------------

/*
// A utility function to get minimum of two intgers
int min (int x, int y)
{ return (x < y)? x : y; }
 
// A utility function to get maximum of two intgers
int max (int x, int y)
{ return (x > y)? x : y; }



void progdyn(std::vector<Bloc>& blocs)
{
   std::sort (blocs.begin(), blocs.end(), sortByLxP);
   std::vector<int> msh;

   //int msh[blocs.size()];
   for (int i = 0; i < blocs.size(); i++ )
      msh.push_back(blocs[i].h);
 
   // Compute optimized msh values in bottom up manner 
   	for (int i = 1; i < blocs.size(); i++ ) {
      		for (int j = 0; j < i; j++ ) {
         		if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (msh[i] < (msh[j] + blocs[i].h)) )
         		{
                		msh[i] = msh[j] + blocs[i].h;
         		}
		}
	}

   // Pick maximum of all msh values 
   int max = -1;
   for ( int i = 0; i < blocs.size(); i++ ) {
	//std::cout << msh[i] << std::endl;
	//std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
	//std::cout << blocs.size() << std::endl;
      	if ( max < msh[i] )
         	max = msh[i];
   }

   	int first = blocs.size() - 1;
	int second = blocs.size() - 2;
	std::vector<int> indexToBeSkiped;
   	while(second > 0) {
		if((blocs[first].w >= blocs[second].w) || (blocs[first].d >= blocs[second].d)) {
			indexToBeSkiped.push_back(second);
			second--;
		} else {
			first = second;
			second--;
		}
	}
int h = 0;
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int i = blocs.size() -1; i >= 0; i-- ) 
	{
      		if (std::find(indexToBeSkiped.begin(), indexToBeSkiped.end(), i) == indexToBeSkiped.end()) {
         		std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
h+=blocs[i].h;
}
   	}

   std::cout << "Hauteur real maximale : " << max << std::endl;
 std::cout << "Hauteur maximale blocs: " << h << std::endl;

}
 */
/*
//---------------------------------------------------------------------------------------
// 				Algorithme progdyn
//---------------------------------------------------------------------------------------

// A utility function to get minimum of two intgers
int min (int x, int y)
{ return (x < y)? x : y; }
 
// A utility function to get maximum of two intgers
int max (int x, int y)
{ return (x > y)? x : y; }



void progdyn(std::vector<Bloc>& blocs)
{
	std::sort (blocs.begin(), blocs.end(), sortByLxP);
   	std::vector<int> msh;

   	for ( int i = 0; i < blocs.size(); i++ ) {

		std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
	}
   	//int msh[blocs.size()];
   	for (int i = 0; i < blocs.size(); i++ )
      		msh.push_back(blocs[i].h);
 
   	// Compute optimized msh values in bottom up manner 
   	for (int i = 1; i < blocs.size(); i++ ) {
      		for (int j = 0; j < i; j++ ) {
         		if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (msh[i] < (msh[j] + blocs[i].h)) )
         		{
                		msh[i] = msh[j] + blocs[i].h;
         		}
		}
	}

   	// Pick maximum of all msh values 
   	int max = -1;
   	for ( int i = 0; i < blocs.size(); i++ ) {
		//std::cout << "msh = " << msh[i] << std::endl;
		//std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
      		if ( max < msh[i] )
         		max = msh[i];
   	}
	int i = blocs.size() - 1;
   	while( i > 0 ) {
		
		//std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
		if((blocs[i].w >= blocs[i-1].w) || (blocs[i].d >= blocs[i-1].d)) {
//std::cout << i << std::endl;
			blocs.erase(blocs.begin() + i-1);

		} 
		//else {
			i--;
		//}
   	}
	//std::cout << "Ordre des blocs : " << std::endl;
   	//for ( int i = 0; i < blocs.size(); i++ ) {
       //  	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	//}

  	//std::cout << "Hauteur maximale : " << max << std::endl;
}
*/

//---------------------------------------------------------------------------------------
// 				Algorithme progdyn
//---------------------------------------------------------------------------------------
int getBlocsHeight(std::vector<Bloc>& blocs) {
	int height = 0;
	for (int i = 0; i < blocs.size(); i++ ) {
		height += blocs[i].h;
	}
	return height;
}
// A utility function to get minimum of two intgers
int min (int x, int y)
{ return (x < y)? x : y; }
 
// A utility function to get maximum of two intgers
int max (int x, int y)
{ return (x > y)? x : y; }



void progdyn(std::vector<Bloc>& blocs)
{
	std::sort (blocs.begin(), blocs.end(), sortByLxP);
   	std::vector<int> msh;

   	//int msh[blocs.size()];
   	for (int i = 0; i < blocs.size(); i++ )
      		msh.push_back(blocs[i].h);
 
   	// Compute optimized msh values in bottom up manner 
   	for (int i = 1; i < blocs.size(); i++ ) {
      		for (int j = 0; j < i; j++ ) {
         		if ( (blocs[i].w < blocs[j].w) && (blocs[i].d < blocs[j].d) && (msh[i] < (msh[j] + blocs[i].h)) )
         		{
                		msh[i] = msh[j] + blocs[i].h;
         		}
		}
	}

   	// Pick maximum of all msh values 
   	int max = -1;
	int indexMaxHeight = 0;
   	for ( int i = 0; i < blocs.size(); i++ ) {
		std::cout << "msh = " << msh[i] << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
      		if ( max < msh[i] ) {
         		max = msh[i];
			indexMaxHeight = i;
		}
   	}
	std::vector<Bloc> solution;
	int currentHeight = max - blocs[indexMaxHeight].h;
	solution.push_back(blocs[indexMaxHeight]);
   	for (int i = indexMaxHeight - 1 ; i >= 0 ; i--) {
		if(currentHeight == msh[i]) {
			solution.push_back(blocs[i]);
			currentHeight -= blocs[i].h;
		} 
   	}
	blocs = solution;
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int i = 0; i < blocs.size(); i++ ) {
         	std::cout << blocs[i].h << " : " << blocs[i].w  << " : " << blocs[i].d  << std::endl;
   	}

  	std::cout << "Hauteur real maximale : " << max << std::endl;
	std::cout << "Hauteur blocs maximale : " << getBlocsHeight(blocs) << std::endl;

}
/* Driver program to test above function */

//---------------------------------------------------------------------------------------
// 				Algorithme tabou
//---------------------------------------------------------------------------------------

void swipeData(std::vector<int>& tour, std::map<unsigned int, int>& tabou, std::vector<Bloc>& blocs, int index) {
//std::cout << "----------------------------------BEGIN-------------------------------"  << std::endl;
//std::cout << "index = "<< index  << std::endl;
  //       	std::cout << blocs[tour[index]].h << " : " << blocs[tour[index]].w  << " : " << blocs[tour[index]].d  << std::endl;
//std::cout << "--------------------------------BEFORE MODIF-----------------------------------------------"  << std::endl;
 //  	for ( int i = 0; i < tour.size(); i++ ) {
 //        	std::cout << blocs[tour[i]].h << " : " << blocs[tour[i]].w  << " : " << blocs[tour[i]].d  << std::endl;
 //  	}
//std::cout << "-------------------------------------------------------------------------------"  << std::endl;

	if(index < (tour.size() - 1)) {
    		const int range_from  = 7;
    		const int range_to    = 10;
    		std::random_device rand_dev;
    		std::mt19937 generator(rand_dev());
    		std::uniform_int_distribution<int>  distr(range_from, range_to);

		int iterationTabou = distr(generator);
//std::cout << "iterationTabou ------ = "<< iterationTabou  << std::endl;
		int k = index + 1;
//std::cout << "-------------------------------------------------------------------------------"  << std::endl;
//std::cout << blocs[tour[index]].h << " : " << blocs[tour[index]].w  << " : " << blocs[tour[index]].d  << std::endl;
		 while((k < tour.size()) && (tour.size() > 0)) {
//std::cout << blocs[tour[k]].h << " : " << blocs[tour[k]].w  << " : " << blocs[tour[k]].d  << std::endl;
			if((blocs[tour[k]].w >= blocs[tour[index]].w) || (blocs[tour[k]].d >= blocs[tour[index]].d)) {
//std::cout <<  " tour[k] " << tour[k]  << std::endl;
				//tabou[tour[k]] = iterationTabou;
				tabou.insert ( std::pair<unsigned int,int>(tour[0],iterationTabou) );
				tour.erase(tour.begin() + k);
			} else {
				break;
			}
		}
//std::cout << "-------------------------------------------------------------------------------"  << std::endl;
	}
//std::cout << "--------------------------------AFTER MODIF-----------------------------------------------"  << std::endl;
   //	for ( int i = 0; i < tour.size(); i++ ) {
    //     	std::cout << blocs[tour[i]].h << " : " << blocs[tour[i]].w  << " : " << blocs[tour[i]].d  << std::endl;
   //	}
//std::cout << "--------------------------------END-----------------------------------------------"  << std::endl;
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

	//std::sort (blocs.begin(), blocs.end(), sortByLxP);
  	srand (time(NULL));
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
						//std::cout << "tempTour size ------ = "<< tempTour.size()  << std::endl;
						swipeData(tempTour, tempTabou, blocs, 0);
					}
				}

			} //else {
				//continue;
			//}
			int newHeight = getHeight(tempTour, blocs);
			if(newHeight > bestTempHeight) {
				bestTempHeight = newHeight;
				bestTempTour = tempTour;
				bestTempTabou = tempTabou;

			}
		}
		if (getHeight(finalTour, blocs) < getHeight(bestTempTour, blocs)) {
			iteration = 0;
			finalTour = bestTempTour;	

//std::cout << "solutionTour size = "<< solutionTour.size()  << std::endl;
		}
		solutionTour = bestTempTour;
		solutionTabou = bestTempTabou;
		bestTempTour.clear();
		bestTempTabou.clear();
		decrementIteration(solutionTabou);
//std::cout << "solutionTour size = "<< solutionTour.size()  << std::endl;
	}
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int j = 0; j < finalTour.size(); j++ ) {
         	std::cout << blocs[finalTour[j]].h << " : " << blocs[finalTour[j]].w  << " : " << blocs[finalTour[j]].d  << std::endl;
   	}
   	std::cout << "Hauteur maximale : " << getHeight(finalTour, blocs) << std::endl;
}


/*
void tabou(std::vector<Bloc>& blocs)
{
//std::sort (blocs.begin(), blocs.end(), sortByLxP);
  	// initialize random seed: 
  	srand (time(NULL));
	std::vector<int> solutionTour;
	std::vector<int> tempTour;
	std::vector<int> bestTempTour;
	std::map<int,int> solutionTabou;
	std::map<int,int> tempTabou;
	std::map<int,int> bestTempTabou;
	solutionTour.push_back(0);
	for (int iteration = 0; iteration < 100; iteration++ ) {
		for (int index = 0; index < blocs.size(); index++ ) {
			tempTour = solutionTour;
			tempTabou = solutionTabou;
			bestTempTour = solutionTour;
			bestTempTabou = solutionTabou;
			if (((std::find(tempTour.begin(), tempTour.end(), index) == tempTour.end()) && (tempTabou.find(index) == tempTabou.end()))) {
				int i = tempTour.size() - 1;
				for (; i >= 0; i-- ) {
					if((blocs[tempTour[i]].w > blocs[index].w) && (blocs[tempTour[i]].d > blocs[index].d)) {
						tempTour.insert(tempTour.begin() + i + 1, index);
						swipeData(tempTour, tempTabou, blocs, i + 1);
						//std::cout << "tempTabou size = "<< tempTabou.size()  << std::endl;
						break;
					}
				}
				if(i < 0) {
					tempTour.insert(tempTour.begin(), index);
					swipeData(tempTour, tempTabou, blocs, 0);
				}
			}
			if(getHeight(tempTour, blocs) > getHeight(bestTempTour, blocs)) {
std::cout << "best " << std::endl;
				bestTempTour = tempTour;
				bestTempTabou = tempTabou;
			}
		}
		if(getHeight(bestTempTour, blocs) > getHeight(solutionTour, blocs)) {
			solutionTour = bestTempTour;
			solutionTabou = bestTempTabou;
			iteration = 0;
		}
		decrementIteration(solutionTabou);
	}
	std::cout << "Ordre des blocs : " << std::endl;
   	for ( int k = 0; k < solutionTour.size(); k++ ) {
         	std::cout << blocs[solutionTour[k]].h << " : " << blocs[solutionTour[k]].w  << " : " << blocs[solutionTour[k]].d  << std::endl;
   	}
   	std::cout << "Hauteur maximale : " << getHeight(solutionTour, blocs) << std::endl;
}*/
//---------------------------------------------------------------------------------------
// 				HELPERS
//---------------------------------------------------------------------------------------

void fillData(std::vector<Bloc>& blocs, const string& filename) {
        std::fstream ex_file(filename);
        int height, width, depth;
        while (ex_file >> height >> width >> depth) {
		Bloc newBloc = Bloc(height, width, depth);
            	blocs.push_back(newBloc);
	}
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
// 				MAIN
//---------------------------------------------------------------------------------------

int main()
{
	std::vector<Bloc> blocs;
	fillData(blocs, "b10000_10.txt");
//std::cout << blocs.size() << std::endl;
       // progdyn (blocs);
	//vorace(blocs);
	tabou(blocs);
  	return 0;
}

/*
int main(int argc, char *argv[]) {
	std::vector<Bloc> blocs;
	fillData(blocs, "b100_1.txt");


    	struct {
        	std::string algo;
        	std::string file_path;
        	bool print_res{false};
        	bool print_time{false};
    	} prog_args;

	run(progdyn, blocs, prog_args.print_res, prog_args.print_time);
/*
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

}*/


