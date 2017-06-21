#include <stdio.h>
#include "QuickSort.h"

void count_comparisons()
{
    int a[10000];
    int count[1] = {0};
    load_array_from_file("quicksort_input.txt", a, 10000);
    printf("Unsorted\n");
    print_array_oflength(a, 10);
    printf("Final element %i\n", a[9999]);
    printf("\n");
    quick_sort(a, 10000, count);
    printf("Sorted\n");
    print_array_oflength(a, 10);
    print_array_oflength(a+9990, 10);
    printf("Final element %i\n", a[9999]);
    printf("Count: %i\n", count[0]);
}

int main()
{
	count_comparisons();
	return 0;
}
