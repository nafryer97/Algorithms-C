#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "insertion_sort.h"

void test1() {
    int test0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int test1[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    int test2[] = { 2, 1, 4, 3, 6, 5, 8, 7, 10, 9 };

    insertionSort(test0, 10);
    insertionSort(test1, 10);
    insertionSort(test2, 10);

    for (int i = 0; i < 10; ++i) {
        assert_int_equal(i + 1, test0[i]);
        assert_int_equal(i + 1, test1[i]);
        assert_int_equal(i + 1, test2[i]);
    }

}

int main(void) {
    const UnitTest tests[] = {
        unit_test(test1),
    };

    return run_tests(tests);
}
