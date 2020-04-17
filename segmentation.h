#ifndef _SEGMENTATION_H_
#define _SEGMENTATION_H_

#include "types.h"
/*
 * segmentation.h
 *
 *  Created on: 16.04.2020
 *  Author: Vineesh Mohan
 */


/*******************************************************************************
MACROS
*******************************************************************************/

#define ARRAY_MAX_SIZE 1024 // Maximum Array Size, change the size as per the requirements.

/*******************************************************************************
FUNCTION PROTOTYPES
*******************************************************************************/

VOID swap(sint* a,sint* b); // To swap the values of two intgers
sint* threeWaySegmentation(sint A[], sint end, sint midSegment);//Sorting an array of three 
                        //different integers with multiple entries, in linear time complexity.

#endif /*_SEGMENTATION_H_ */


