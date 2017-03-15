//--------------------------------------------------------------------
// Title: Algorithm Analysis and Sorting Program
// Author: Orkun ALPAR
// Description: Compares sorting algorithms for different scenarios.
//--------------------------------------------------------------------

//compCount is the number of comparisons made through the sorting
//moveCount, in a similar fashion, is the number of moves made through the sorting

#include "sorting.h"
#include <iostream>
using namespace std;

	sorting::sorting() {}

	void sorting::insertionSort( int *arr, int size,unsigned int &compCount,unsigned int &moveCount) {
		//for every element, compare until arr[0] and move it until the correct spot is found
		int key = 0;
		int i = 0;
		moveCount += 3; //two from above, one from the assignment inside for loop
		for (int j = 1; j < size; j++) {
			compCount += 1; //because, j is being compared with size for "size" times
			key = arr[j]; 
			moveCount+=2;
			i = j - 1; 
			moveCount++;
			while ( i>= 0 && arr[i] > key) { 
				compCount += 2;
				arr[i+1] = arr[i];
				i--; 
				moveCount += 2;
  			}	
  			arr[i+1] = key;
  			moveCount++;
		}

	}

	void sorting::mergeSortHelp( int* arr, int size, int first, int last,unsigned int &compCount,unsigned int &moveCount) {
   
		if (first < last) {
		   compCount++;
   		   int mid = (first + last) / 2; 	// index of midpoint
   		   moveCount++;
      	   mergeSortHelp(arr, size, first, mid, compCount, moveCount);
      	   mergeSortHelp(arr, size, mid+1, last, compCount, moveCount);
     	   merge(arr, size, first, mid, last, compCount, moveCount);
  		}
  		else {
  			compCount++;
  		}

	}  // end mergeSortHelp

	void sorting::merge( int* arr, int size,  int first,  int mid, int last,unsigned int &compCount,unsigned int &moveCount) {
   
		int tempArray [size]; 	// temporary array  (counting "size" times move) 
		moveCount += size;
		int first1 = first; 	// beginning of first subarray
   		int last1 = mid; 		// end of first subarray
   		int first2 = mid + 1;	// beginning of second subarray
   		int last2 = last;		// end of second subarray
   		int index = first1;     // next available location in tempArray
   		moveCount += 5;

    	for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
    		moveCount++; //caused by index++
    		compCount += 2; //in loop check conditions
     	  	if (arr[first1] < arr[first2]) { 
     	  		 compCount++; 
        		 tempArray[index] = arr[first1];
        		 ++first1;
        		 moveCount += 2;
     		}
     		else {  
     			compCount++;
          		tempArray[index] = arr[first2];
          		++first2;
          		moveCount += 2;
      		}
 		}

 		// finish off the first subarray, if necessary
   		for (; first1 <= last1; ++first1, ++index) {
   			 compCount += 2;
   	   		 tempArray[index] = arr[first1];
   	   		 moveCount += 2; //one from array move, one from index increment
   		}

  		// finish off the second subarray, if necessary
  		for (; first2 <= last2; ++first2, ++index) {
  			compCount += 2;
    		tempArray[index] = arr[first2];
    		moveCount += 2; //one from array move, one from index increment

    	}

  		// copy the result back into the original array
   		for (index = first; index <= last; ++index) {
   			compCount += 2;
      		arr[index] = tempArray[index];
      		moveCount += 2; //one from array move, one from index increment

        }

}  // end merge
 

	void sorting::mergeSort( int* arr, int size,unsigned int &compCount,unsigned int &moveCount) {
		mergeSortHelp( arr, size, 0, size, compCount, moveCount);
	}


	void sorting::quickSortHelp(int* arr, int first, int last,unsigned int &compCount,unsigned int &moveCount) {

		int pivotIndex;
		moveCount++;
 	    if (first < last) {
 	       moveCount++;
    	   partition(arr, first, last, pivotIndex, compCount, moveCount);
      	   quickSortHelp(arr, first, pivotIndex-1, compCount, moveCount);
     	   quickSortHelp(arr, pivotIndex+1, last,  compCount, moveCount);
   		}
   		else {
   		   moveCount++;
   		}
	}


	void sorting::partition(int* arr, int first, int last, int &pivotIndex,unsigned int &compCount,unsigned int &moveCount) {

		int index = first;
		pivotIndex = first;
		moveCount+=2;

		while(index<last) {
			compCount++;
			if(arr[index] <= arr[last]) {
				compCount++;
				swap(arr[pivotIndex], arr[index], compCount, moveCount);			
				pivotIndex++;
			}
			else {
				compCount++;
			}
			index++;
		}
		swap(arr[pivotIndex], arr[last], compCount, moveCount);
	}

	void sorting::quickSort( int* arr, int size,unsigned int &compCount,unsigned int &moveCount) {
		quickSortHelp(arr, 0, size, compCount, moveCount);
	}

	void sorting::swap(int &a, int &b,unsigned int &compCount,unsigned int &moveCount) {
		int temp;
		temp = b;
		b = a;
		a = temp;
		moveCount += 4;
	}