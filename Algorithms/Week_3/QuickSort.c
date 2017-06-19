#include <stdio.h>
#include "TestQuickSort.h"

void run_tests()
{
	test_partition();
	test_swap();
	test_slice_array();
	test_partition();
	test_array_equals();
	test_quick_sort();
	test_load_array();
}

int main()
{
	run_tests();
	return 0;
}
