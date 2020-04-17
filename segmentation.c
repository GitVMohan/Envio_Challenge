#include <stdio.h>

#include "segmentation.h"

/* FUNCTION: swap
 * DESCRIPTION: Function to swap the values of two integers.
 * PARAMETERS:
 *          Type         Name      Description
 *
 *     1.   int*          a         Integer Pointer
 *     2.   int*          b         Integer Pointer  
 * RETURN:
 *     1.   void
 *
 *   */
void swap(sint* a,sint* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

/* FUNCTION: threeWaySegmentation
 * DESCRIPTION: Sorting an array of three different integers with multiple entries, in 
 * linear time complexity.
 * PARAMETERS:
 *          Type         Name      Description
 *
 *     1.   int          A           Integer Array
 *     2.   int          end         Size of Integer array 
 *     3.   int          midSegment  Mid segement value 
 * RETURN:
 *     1.   int pointer            Sorted array address
 *
 *   */
int* threeWaySegmentation(sint A[], sint end, sint midSegment)
{
	int begin = 0, mid = 0;

	while (mid <= end)
	{
		if (A[mid] < midSegment)		    // current element is 0
		{
			swap(&A[begin], &A[mid]);
			++begin, ++mid;
		}
		else if (A[mid] > midSegment)	   // current element is 2
		{
			swap(&A[mid], &A[end]);
			--end;
		}
		else						           // current element is 1
		{
			++mid;
		}
	}

	return(&A[0]);
}

