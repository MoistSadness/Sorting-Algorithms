# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "sorting.h"
# include "time.h"

/****
 * Calculates the amount of time it takes to run a function
****/
float Calculate_Runtime(clock_t end, clock_t start){
    return (double)(end - start) / CLOCKS_PER_SEC;
}


/****
 * Prints the array
****/
void printArr(int arr[], int ARRSIZE){
    for(int x = 0; x <= ARRSIZE; x++){
        printf("%d\t%d\n", x, arr[x]);
    }
}


void Run_Sorting_Algorithms(int ARRSIZE){
    // Creating a massive array of random integers between 0 and 300
    //int ARRSIZE = 60000;
    int intArr[ARRSIZE];

    for(int x = 0; x <= ARRSIZE; x++){
        intArr[x] = rand() % 300;
        // printf("%d\t%d\n", x, intArr[x]);
    }



    /*** COMMENTING OUT WORKING SORTING ALGORITHMS

    /*** INSERTION SORT STUFF
    int insertionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        insertionArr[x] = intArr[x];
        // printf("%d\t%d\n", x, intArr[x]);
    }
    insertionsort(insertionArr, ARRSIZE);

    /***    SELECTION SORT STUFF
    int selectionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        selectionArr[x] = intArr[x];
    }
    selectionSort(selectionArr, ARRSIZE);

    /***    BUBBLE SORT STUFF   ***/
    /*
    int bubbleArr[ARRSIZE];
    for(int x = 0; x <= ARRSIZE; x++){
        bubbleArr[x] = intArr[x];
    }
    bubbleSort(bubbleArr, ARRSIZE);

    */

    /***    MERGE SORT STUFF    ***/
    int mergeArr[ARRSIZE];
    for(int x = 0; x <= ARRSIZE; x++){
        mergeArr[x] = intArr[x];
    }
    time_t start = clock();                             // Benchmarking done in driver code because
    mergeSort(mergeArr, 0, ARRSIZE - 1);                // sorting algorithm is recursive
    time_t end = clock();

    // printArr(mergeArr, ARRSIZE);

    double runtime = Calculate_Runtime(end, start);
    printf("\nMerge Sort completed:\t%f seconds\n", runtime);


    /***    QUICK SORT STUFF    ***/
    int quickArr[ARRSIZE];
    for(int x = 0; x <= ARRSIZE; x++){
        quickArr[x] = intArr[x];
    }
    quickSort(quickArr, 0, ARRSIZE)
}


/****
 * Insertion Sort
****/
void insertionsort(int insertionArr[], int ARRSIZE){
    clock_t start = clock();        // Start timer

    //int i;
    int j;
    int key;

    for(int i = 1; i <= ARRSIZE; i++){
        key = insertionArr[i];          // The value that is being compared
        j = i - 1;                      // The value that is one element to the left of the key value
        // Iterate through the array leftwards until the key is in the right order
        while(j >= 0 && insertionArr[j] > key){
            insertionArr[j + 1] = insertionArr[j];
            j = j - 1;
        }
        insertionArr[j + 1] = key;
    }

    clock_t end = clock();      // End timer

    // printArr(insertionArr, ARRSIZE);     // Prints the array

    double runtime = Calculate_Runtime(end, start);
    printf("\nInsertion Sort completed:\t%f seconds\n", runtime);
}


/****
 * Selection Sort
****/
void selectionSort(int selectionArr[], int ARRSIZE){
    clock_t start = clock();        // Start timer

    int i, j, minimumIndex;

    // Iterate through the array
    for(i = 0; i <= ARRSIZE; i++){      // Goes to the next element in the unsorted part of the array
        minimumIndex = i;
        for (j = i + 1; j < ARRSIZE + 1; j++){
            if(selectionArr[j] < selectionArr[minimumIndex]) minimumIndex = j;
        }
        int temp = selectionArr[minimumIndex];
        selectionArr[minimumIndex] = selectionArr[i];
        selectionArr[i] = temp;
    }

    clock_t end = clock();      // End timer

    //printArr(selectionArr, ARRSIZE);     // Prints the array

    double runtime = Calculate_Runtime(end, start);
    printf("\nSelection Sort completed:\t%f seconds\n", runtime);
}


/****
 * Bubble Sort
****/
void bubbleSort(int bubbleArr[], int ARRSIZE){
    clock_t start = clock();

    // For ARRSIZE - 1 number of passes
    for(int i = 0; i < ARRSIZE; i++){
        // All the items less than i are already sorted so we iterate past them
        for (int j = 0; j <= ARRSIZE - 1 - i; j++){
            if(bubbleArr[j] > bubbleArr[j + 1]){
                // Swap the two elements if true
                int temp = bubbleArr[j + 1];
                bubbleArr[j + 1] = bubbleArr[j];
                bubbleArr[j] = temp;
            }
        }
    }

    clock_t end = clock();

    //printArr(bubbleArr, ARRSIZE);

    double runtime = Calculate_Runtime(end, start);
    printf("\nBubble Sort completed:\t\t%f seconds\n", runtime);
}


/****
 * Merge Sort
****/
void merge(int mergeSubArr[], int left, int middle, int right){
    int tempLeftSize = middle - left + 1;       // Size of the left sub array
    int tempRightSize = right - middle;         // Size of the right sub array

    int tempLeftArr[tempLeftSize], tempRightArr[tempRightSize];         // Creating Sub arrays

    // Copying data from mergeSubArr and splitting it into the two sub arrays
    for (int i = 0; i < tempLeftSize; i++){
        tempLeftArr[i] = mergeSubArr[left + i];
        }
    for (int j = 0; j < tempRightSize; j++){
        tempRightArr[j] = mergeSubArr[middle + 1 + j];
        }

    // Sorting and then merging the two temp arrays back into the original mergeSubArr
    int tempLeftInit = 0;            // Initial index of left subarray
    int tempRightInit = 0;           // Initial index of right subarray
    int mergeArrInit = left;         // Initial index of the merged subarray

    /***
     * Compare the elements between the temp subarrays at a specific index against each other
     * The smallest one gets added into the original aray and its index incremented
     * The larger one is left unchanged
     * Increment the main counter 
    ***/
    while (tempLeftInit < tempLeftSize && tempRightInit < tempRightSize){
       if (tempLeftArr[tempLeftInit] < tempRightArr[tempRightInit]) {
           mergeSubArr[mergeArrInit] = tempLeftArr[tempLeftInit];
           tempLeftInit++;
       }
       else {
           mergeSubArr[mergeArrInit] = tempRightArr[tempRightInit];
           tempRightInit++;
       }
        mergeArrInit++;
   }

   // Copy any leftover elements from the subarrays into the original 
   while (tempLeftInit < tempLeftSize) {
       mergeSubArr[mergeArrInit] = tempLeftArr[tempLeftInit];
       tempLeftInit++;
       mergeArrInit++;
   }
   while (tempRightInit < tempRightSize) {
       mergeSubArr[mergeArrInit] = tempRightArr[tempRightInit];
       tempRightInit++;
       mergeArrInit++;
   }
}

void mergeSort(int mergeArr[], int leftIndex, int rightIndex){
    printf("begin mergesort\n");

    if (leftIndex >= rightIndex) return;        // End recursion

    // Accounts for overflow in case the mergeArr has an odd number of elements
    int middleIndex = (leftIndex + rightIndex) /2;

    // Sort the left side subArray
    mergeSort(mergeArr, leftIndex, middleIndex);

    // Sort the right side subArray
    mergeSort(mergeArr, middleIndex + 1, rightIndex);

    // Merge the two subarrays together
    merge(mergeArr, leftIndex, middleIndex, rightIndex);
}


/****
 * Quick Sort
****/
int partition(int quickArr[], int left, int right){
    int pivot = quickArr[right];
    int pivotIndex = (left -1);

    for (int j = left; j <= right - 1; j++){
        // If the current element is smaller than the pivot, increment index of smaller element
        // and swap the two elements
        if (quickArr[j] < pivot){
            pivotIndex++;

            // Swaping
            int temp;
            
        }
    }
}

void quickSort(int quickArr[], int left, int right){
    if (left < right){
        int partitionIndex = partition(quickArr, left, right);

        quickSort(quickArr, left, partitionIndex - 1);      // Separately sort elements before 
        quickSort(quickArr, partitionIndex + 1, right);     // partition and after partition
    }

}

/****
 * Counting Sort
****/

