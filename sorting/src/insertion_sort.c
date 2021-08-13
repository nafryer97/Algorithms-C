/*
 * At each array position, check the current value against the largest known
 * value, which is the previous value in the array.
 *     If the current value is larger continue
 *     If the largest value is smaller, find the correct position and shift all
 *     of the larger values up. Finally, insert the current value in its correct
 *     position.
 *
 * Best Case Time Complexity:
 *     The array is already sorted -> O(n)
 *
 * Worst Case Time Complexity:
 *     The array is in reverse-order -> O(n^2)
 *
 * Average Case Time Complexity:
 *     Insertion sort is one of the fastest algorithms for sorting small arrays,
 *     but its average case complexity quickly becomes quadratic as the array
 *     size increases. This is typically around n = 10.
 *
 *     See https://stackoverflow.com/questions/17055341/why-is-insertion-sort-Θn2-in-the-average-case/17055342#17055342
 */

#include "headers/insertion_sort.h"

void insertionSort(int arr[], int n) {

    if(n <= 1) return;

    printf("\t\tInversions: ");

    for(int i = 1; i < n; ++i) {
        int j = i - 1;
        int temp = arr[i];

        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
        if(j != i - 1) {
            printf("%i...", i);
        }
    }
    printf("\n");
}

void printArray(int arr[], int n) {
    printf("\t\tArray: { ");
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) {
            printf("%i }\n", arr[i]);
        }
        else {
            printf("%i, ", arr[i]);
        }
    }
}
