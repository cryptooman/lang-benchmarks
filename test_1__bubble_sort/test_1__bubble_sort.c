/*
    gcc -std=c11 -Wall -O3 test_1__bubble_sort.c -o test_1__bubble_sort__c
    time ./test_1__bubble_sort__c
    ...    
    repeats: 100000000
    arr[0]: 0 2 2 3 3 6 7 7 9 9
    arr[1]: 1 2 3 5 5 6 6 8 9 9
    swaps: 2024975854

    real    0m33.312s
    user    0m33.260s
    sys     0m0.028s    
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define REPEATS_MAX 100000000 // 100M
#define SORT_SIZE 10

int bubbleSort(int* arr, int size) {
    int swaps = 0;
    int tmp;        
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swaps++;
            }
        }
    }    
    return swaps;
}

int main() {        
    srand(time(NULL));
    
    int unsorted[2][SORT_SIZE];
    long long int swaps = 0; 
    
    for (long long int repeats = 0; repeats < REPEATS_MAX; repeats++) {     
        // Make array to sort: {
        //     {x1, ..., x10},
        //     {y1, ..., y10}
        // };
        for (int i = 0; i < SORT_SIZE; i++) {
            unsorted[0][i] = rand() % 10;
            unsorted[1][i] = rand() % 10;
        }
        
        int n = rand() % 2;        
        swaps += bubbleSort(unsorted[n], SORT_SIZE);
                    
        if ((repeats + 1) % 1000000 == 0) {
            printf("repeats: %lld\n", repeats + 1);
        }
    }
    
    // Result sort
    bubbleSort(unsorted[0], SORT_SIZE);
    bubbleSort(unsorted[1], SORT_SIZE);
        
    printf("arr[0]:");
    for (int i = 0; i < SORT_SIZE; i++) {
        printf(" %d", unsorted[0][i]);
    }
    
    printf("\narr[1]:");
    for (int i = 0; i < SORT_SIZE; i++) {
        printf(" %d", unsorted[1][i]);
    }

    printf("\nswaps: %lld\n", swaps);
    
    return 0;
}
