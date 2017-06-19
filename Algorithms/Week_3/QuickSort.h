#define QuickSort

int add_int(int a, int b)
{
	return a+b;
}

void swap(int* a, int b, int c)
{
	int temp = a[b];
	a[b] = a[c];
	a[c] = temp;
}

void print_array(int* a, int l, int r)
{
	printf("[ ");
	for (int i = l; i < r; ++i)
	{
		printf("%i, ", a[i]);
	}
	printf("]\n");
}

void print_array_oflength(int *a, int n)
{
	print_array(a, 0, n);
}

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

void quick_sort(int* a, int n)
{
	if(n == 1)
	{
		return;
	}
	int i = partition(a, 0, n);
	quick_sort(a, i-1);
	quick_sort(a + i, n - i);

}
