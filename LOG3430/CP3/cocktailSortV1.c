//
// MiniTest 3
// compile:
// gcc -o main  cocktailSortV1.c
//
// run:
//
// ./main  7 12 3 5
//

#include <stdlib.h>
#include <stdio.h>



void  swap(int  *i, int *j) {  // line 1 
  int t = *i; // line 2
  *i = *j; // line 3
  *j = t; // line 4
}


void cocktailShakerSort(int *  A, int size){ // line 5
int swapped, i; // line 6
  do{  // line 7
    swapped = 0; // line 8
    for (i =0 ; i < size - 2; i++) // line 9
      if (A[ i ] > A[ i + 1 ]){  // line 10
        swap( A + i , A + i + 1  ); // line 11 
	swapped =1; // line 12
      }
    
    if (swapped ==0) // finish if no swaps occurred. -- line 13
      break; // line 14

    swapped = 0; // line 15
    for (i = size  - 2 ; i> 0; i--)  // line 16
      if (A[ i ] > A[ i + 1 ]) { // line 17
        swap(A + i , A+ i + 1  ); // line 18
	swapped = 1; // line 19
      }
    
  }while (swapped); // if no elements have been swapped, then it is sorted -- line 20
}

//
// main just to run
//
int main(int argc, char** argv) {

int *v=(int *) malloc((argc-1)*sizeof(int));
printf("In data:\n");

for (int k=0;k<argc-1;k++){
   v[k]=atoi(argv[k+1]);
   printf("[%d] ==  %d\n",k,v[k]);
}

cocktailShakerSort(v, argc-1);
printf("Sorted data:\n");
for (int k=0;k<argc-1;k++)
    printf("[%d] ==  %d\n",k,v[k]);
    
return 0;
}
