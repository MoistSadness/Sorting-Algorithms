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
    printf("*\tDriver code for sorting algorithm practice\t*\n");
    printf("*********************************************************\n");

    // Creating a massive array of random integers between 0 and 300
    int ARRSIZE = 60000;
    int intArr[ARRSIZE];

    for(int x = 0; x <= ARRSIZE; x++){
        intArr[x] = rand() % 300;
        // printf("%d\t%d\n", x, intArr[x]);
    }

    // Insetion sort stuff
    int insertionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        insertionArr[x] = intArr[x];
        // printf("%d\t%d\n", x, intArr[x]);
    }
    insertionsort(insertionArr, ARRSIZE);

    // Selection sort stuff
    int selectionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        selectionArr[x] = intArr[x];
    }
    selectionSort(selectionArr, ARRSIZE);


    return 0;
}
 