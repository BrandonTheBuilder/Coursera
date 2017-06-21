#include <stdio.h>
#include "TestQuickSort.h"

void run_tests()
{
	test_partition_slice();
	test_swap();
	test_slice_array();
	test_array_equals();
	test_quick_sort();
	test_load_array();
	test_long_input();
    test_count();
    test_place_pivot();
}

void run_test_cases()
{
    test_case_one();
    test_case_two();
    test_case_three();
    test_case_four();
    test_case_five();
    test_case_six();
}

int main()
{
	// run_tests();
    run_test_cases();
	return 0;
}