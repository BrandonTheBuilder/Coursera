#define QuickSort
#include "Utilities.h"

int partition(int* a, int l, int r)
{
	int p = a[l];
	int i = l + 1;
	for (int j = i; j < r; ++j)
	{
		if (a[j] < p)
		{
			swap(a, j, i);
			i += 1;
		}
	}
	swap(a, l, i-1);
	return i;
}

void place_pivot(int *a, int n, int count_method)
{
    switch(count_method)
    {
        case 1:
            use_last_value_as_pivot(a, n);
            break;
        case 2: 
            use_median_value_as_pivot(a, n);
            break;
    }
}

void quick_sort(int* a, int n, int* call_count, int count_method)
{
    // printf("QuickSort Called With array of length %i\n", n);
	// printf("Got\n");
    // print_array_oflength(a, n);
    if (n == 0)
	{
		return;
	}
	if(n == 1)
	{
		return;
	}
    call_count[count_method] += n-1;
    place_pivot(a, n, count_method);
	int i = partition(a, 0, n);
    // printf("partitioned\n");
    // print_array_oflength(a, n);
	quick_sort(a, i-1, call_count, count_method);
	quick_sort(a + i, n - i, call_count, count_method);
}
