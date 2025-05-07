#include <stdio.h>

#define SIZE 5

 #define SORT_ASC
//#define SORT_DESC

#ifdef SORT_ASC
#define SORT_FUNCTION  getAndSortAscending
#elif defined(SORT_DESC)
#define SORT_FUNCTION getAndSortDescending
#else
#error "Please define SORT_ASC or SORT_DESC"
#endif

int* getAndSortAscending() {
    static int arr[SIZE];
    int i, j, temp;
    printf("Enter %d integers:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int* getAndSortDescending() {
    static int arr[SIZE];
    int i, j, temp;
    printf("Enter %d integers:\n", SIZE);
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < SIZE - 1; i++) {
        for (j = i + 1; j < SIZE; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main() {
    int* sortedArray = SORT_FUNCTION();
    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sortedArray[i]);
    }
    printf("\n");
    return 0;
}


