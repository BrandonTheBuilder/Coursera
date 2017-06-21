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

void quick_sort(int* a, int n, int* call_count)
{
    // printf("QuickSort Called With array of length %i\n", n);
	if (n == 0)
	{
		return;
	}
	if(n == 1)
	{
		return;
	}
    call_count[0] += n-1;
	int i = partition(a, 0, n);
	quick_sort(a, i-1, call_count);
	quick_sort(a + i, n - i, call_count);
}
