/*************************************************************
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 ************************************************************/

# include "stdio.h"
# include "stdlib.h"
# include "time.h"

# include "sorting.h"

int main(){
    printf("*********************************************************\n");
    printf("*\tTesting Sorting algorithms with 1000 elements\t*\n");
    printf("*********************************************************\n");
    Run_Sorting_Algorithms(1000);

    printf("\n");

    printf("*********************************************************\n");
    printf("*\tTesting Sorting algorithms with 60000 elements\t*\n");
    printf("*********************************************************\n");
    Run_Sorting_Algorithms(60000);

    printf("\n");

    printf("*********************************************************\n");
    printf("*\tTesting Sorting algorithms with 100000 elements\t*\n");
    printf("*********************************************************\n");
    Run_Sorting_Algorithms(100000);
    
    printf("\n");

    return 0;
}
 