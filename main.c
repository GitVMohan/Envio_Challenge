#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>
#include "segmentation.h"


/* Description: Sorting of an Integer array with three different Values.
Rule1: Enter three different integer values multiple times, extra integers will not store/sort.
Rule2: Characters other than integer will not store/sort.
Rule3: Each integers should be separated by one space bar and after entering all the integers please press enter.*/
int main()
{

    sint size_of_array = 0,low = 0,mid = 0,high = 0, count =0,wrongInCnt = 0, m, temp;
    sint intValueMin = (pow(2,sizeof(sint)*BYTE_LENGTH) /2) * -1;
    sint intValueMax = (pow(2,sizeof(sint)*BYTE_LENGTH) /2) - 1;
    byte consume; //to consume the scanned character
    byte wrongEntry = 0;
    
    //creating a large enough integer array to store user inputs
    sint *A = malloc(sizeof(sint) * ARRAY_MAX_SIZE); 
    
    //check if memory was allocated or not    
    if(A == NULL)
    {
        printf("memory allocation problem with malloc! \n");
        exit(1);
    }
    
    
    printf("Please enter the integer values for sorting : \n"); 
    printf("Rule1: Enter three different integer values multiple times, extra integers will not store/sort : \n");
    printf("Rule2: Characters other than integer will not store/sort: \n");
    printf("Rule3: Each integers should be separated by one space bar and after entering all the integers please press enter: \n");
    printf("================================================================\n");
    
    for (sint i = 0; i < ARRAY_MAX_SIZE; i++)
    {
        if(scanf("%d", &m) != 1) //check for scanf return value
        {   
            printf("Wrong input, Input is not integer, skipping the entry... \n");
            wrongInCnt++;
            wrongEntry = 1;
            i--;
        }
        
        if (m >=intValueMin || m <=intValueMin ) //Integer bound check
        {
            // Find out three segment values(low,mid,high) and skip all other values beyond the three segments.
            if(!wrongEntry)
            {
                if(count == 0)
                {
                    low = m;
                    count++;
                }
                else if(count ==1 && low != m)
                {
                    mid = m;
                    count++;
                }
                else if(count ==2 && low != m && mid != m )
                {
                    high = m;
                    count++;
                }
                else if(count ==3 && low != m && mid != m && high != m)
                {
                    printf("Wrong input, only three different integers should allow !! \n");
                    wrongInCnt++;
                    wrongEntry = 1;
                    i--;
                }
            }
        }
        else       
        {
            printf("Wrong input, Integer value exceeded the limit!!! \n");
            wrongInCnt++;
            wrongEntry = 1;
            i--;
        }
        // Store the value of integers to the array if the integers are valid
        if(wrongEntry != 1)
        {
            A[i] = m;
            size_of_array++;
        }
        else
        {
            wrongEntry = 0;
        }
        
        scanf("%c", &consume);
        if(consume == 0x0A)
            break;
    }
    
    // Find out the middle segment value
    if(low > mid)
    {
        swap(&low, &mid);
    }
    if(mid > high)
    {
       swap(&mid, &high);
    }
    
    // resize the array size, since the number of elements are known at this point
    A = realloc(A,size_of_array*sizeof(int));
    
    printf("================================================================\n");
    printf("================================================================\n");
    printf("================================================================\n");
    printf("Total number of entries from user = %d \n",size_of_array+wrongInCnt);
    printf("Number of valid integer values entered by user = %d \n",size_of_array);
    printf("Total wrong inputs skipped = %d \n",wrongInCnt);
    printf("Middle value of the three differnet valid integers from user = %d \n",mid);

	//Sort the array in ascending order
	A=threeWaySegmentation(A,size_of_array-1,mid); 
	
	printf("Sorted integer array:\n");
	
	//printing the sorted array
	for(int j=0;j<size_of_array;j++) {
		printf("%d ",A[j]);	
	}
	
    // Free used memory for integer array
	free(A);  

	return 0;

}