//--------------------------------------------------------------------
// Title: Algorithm Complexity Analysis and Sorting Program
// Author: Orkun ALPAR
// Description: Header file for the sorting program. 
//--------------------------------------------------------------------

//compCount is the number of comparisons made through the sorting
//moveCount, in a similar fashion, is the number of moves made through the sorting

#include <iostream>
using namespace std;

class sorting {

public:

	sorting(); //constructor

	void swap (int &a, int &b, unsigned int &compCount, unsigned int &moveCount); //general purpose auxillary method




	void insertionSort( int *arr, int size, unsigned int &compCount, unsigned int &moveCount); 



	void mergeSort( int *arr, int size,unsigned int &compCount,unsigned int &moveCount);

	void merge( int* arr, int size, int first, int mid, int last,unsigned int &compCount,unsigned int &moveCount);

	void mergeSortHelp( int* arr, int size, int first, int last,unsigned int &compCount,unsigned int &moveCount);




	void partition(int* arr, int first, int last, int &pivotIndex,unsigned int &compCount,unsigned int &moveCount); //partition method for quick sort algorithm, selects last element of the array as the pivot

	void quickSortHelp(int* arr, int first, int last,unsigned int &compCount,unsigned int &moveCount);

	void quickSort( int *arr, int size,unsigned int &compCount,unsigned int &moveCount);



};