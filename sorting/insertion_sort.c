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

#if(__STDC_VERSION >= 201112L) // C11 Standard or greater
#include "insertion_sort.h"

void insertionSort(int_fast64_t arr[], uint_fast64_t n) {

    if(n <= 1) return;

    for(int_fast64_t i = 1; i < n; ++i) {
        uint_fast64_t j = i - 1;
        int_fast64_t temp = arr[i];

        while(j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}

#endif
