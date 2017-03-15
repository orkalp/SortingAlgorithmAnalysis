//--------------------------------------------------------------------
// Title: Algorithm Analysis and Sorting Program
// Author: Orkun ALPAR
// Description: Compares sorting algorithms for different scenarios.
//--------------------------------------------------------------------
#include "sorting.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#include <ctime>
using namespace std;

int main() {

	//change array sizes, random (or non-random) numbers and loop constants as you'd like
	//compCount is the number of comparisons made through the sorting
	//moveCount, in a similar fashion, is the number of moves made through the sorting
	
	sorting s;

    int R20K1 [100000];
    int R20K2 [100000];
    int R20K3 [100000];

	int random;
	clock_t startTime;
	double duration;

	unsigned int compCount = 0;
	unsigned int moveCount = 0;


	for(int i=100000; i>0; i--) {

		R20K1[i] = i;
		R20K2[i] = i;
		R20K3[i] = i;

	}


	startTime = clock();
	s.insertionSort (R20K1,100000, compCount, moveCount);
	duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;

	cout<<"First array sorted : "<<endl<<endl;

	cout << "insertionSort took " << duration << " milliseconds." << endl;


	cout << "compCount = "<< compCount<<endl;
	cout << "moveCount = " << moveCount <<endl;

	compCount = 0;
	moveCount = 0;

	startTime = clock();
	s.mergeSort (R20K2,100000, compCount, moveCount);
	duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


	cout<<"Second array sorted : "<<endl<<endl;

	cout << "mergeSort took " << duration << " milliseconds." << endl;


	cout << "compCount = "<< compCount<<endl;
	cout << "moveCount = " << moveCount <<endl;
	compCount = 0;
	moveCount = 0;

	startTime = clock();
	s.quickSort (R20K3,100000, compCount, moveCount);
	duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;


	cout<<"Third array sorted : "<<endl<<endl;

	cout << "quickSort took " << duration << " milliseconds." << endl;


	cout << "compCount = "<< compCount<<endl;
	cout << "moveCount = " << moveCount <<endl;
	compCount = 0;
	moveCount = 0;


	return 0;
}