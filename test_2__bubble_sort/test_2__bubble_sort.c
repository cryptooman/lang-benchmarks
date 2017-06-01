/*
    gcc -std=c11 -Wall -O3 test_2__bubble_sort.c  -o test_2__bubble_sort__c
    ./test_2__bubble_sort__c
    Doing unsorted_list_100.txt
    sorting time, sec: 0.000034
    result slice [1, 10]:   0 0 0 0 0 0 0 1 1 1
    result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9
    swaps: 2619

    Doing unsorted_list_1k.txt
    sorting time, sec: 0.002008
    result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0
    result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9
    swaps: 226375

    Doing unsorted_list_10k.txt
    sorting time, sec: 0.167851
    result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0
    result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9
    swaps: 22698501

    Doing unsorted_list_100k.txt
    sorting time, sec: 15.722146
    result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0
    result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9
    swaps: 2247498217
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TESTS_COUNT 4
const char TESTS[TESTS_COUNT][255] = {
    "unsorted_list_100.txt",
    "unsorted_list_1k.txt",
    "unsorted_list_10k.txt",
    "unsorted_list_100k.txt"
};

long long int bubbleSort(int* arr, int size) {
    long long int swaps = 0;
    int i, j;
    int tmp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                ++swaps;
            }
        }
    }    
    return swaps;
}

void runSortTest(const char* unsortedListFile) {
    const int readBuffSize = 255;
    
    FILE* fp;
    fp = fopen(unsortedListFile, "r");
    if (fp == NULL) {
        printf("Failed to open file: %s\n", unsortedListFile);
        exit(1);
    }
    
    int* unsorted = (int*) malloc(readBuffSize * sizeof(int));
    if (unsorted == NULL) {
        printf("Failed to allocate memory\n");
        exit(1);
    }
    
    int len = 0;
    int code;    
    while((code = fgetc(fp)) != EOF) {        
        if ((len + 1) % readBuffSize == 0) {
            unsorted = (int*) realloc(unsorted, (len + readBuffSize) * sizeof(int));
            if (unsorted == NULL) {
                printf("Failed to reallocate memory\n");
                exit(1);
            }            
        }
        unsorted[len++] = code - '0';
    }
    fclose(fp);
    
    struct timeval tStart, tEnd;
        
    gettimeofday(&tStart, NULL);
    long long int swaps = bubbleSort(unsorted, len);
    gettimeofday(&tEnd, NULL);
    
    double tStartMs = tStart.tv_sec * 1000000 + tStart.tv_usec;
    double tEndMs = tEnd.tv_sec * 1000000 + tEnd.tv_usec;
    
    printf("sorting time, sec: %.6f\n" , (tEndMs - tStartMs) / 1000000);
        
    printf("result slice [1, 10]:  ");
    for (int i = 0; i < 10; i++) {
        printf(" %d", unsorted[i]);
    }
    printf("\nresult slice [n-10, n]:");
    for (int i = len - 10; i < len; i++) {
        printf(" %d", unsorted[i]);
    }
    
    free(unsorted);
    
    printf("\nswaps: %lld\n", swaps);    
}

int main() {
    for (int i = 0; i < TESTS_COUNT; i++) {
        printf("Doing %s\n", TESTS[i]);
        runSortTest(TESTS[i]);        
        printf("\n");
    }
    return 0;    
}
