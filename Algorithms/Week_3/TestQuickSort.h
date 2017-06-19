#define TestQuickSort
#include "QuickSort.h"

void load_array_from_file(char* file_location, int* a)
{
	FILE* file = fopen (file_location, "r");
	int i = 0;
	while (!feof (file))
	{  
	  fscanf (file, "%d", &a[i]);
	  i++;      
	}
	fclose (file);  
}

void print_assertion(int assertion)
{
	if (assertion)
	{
		printf("Passed!\n");
	}
	else
	{
		printf("failed :(\n");
	}
}

int arrays_equal(int* a, int* b)
{
	int na = sizeof(a);
	int nb = sizeof(b);
	if (na != nb)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < na; ++i)
		{
			if (a[i] != b[i])
			{
				return 0;
			}
		}
		return 1;
	}
}

void test_load_array()
{
	printf("test_load_array\n");
	int a[8];
	int b[8] = {1,2,12,3,5,7,123,56};
	load_array_from_file("test_input.txt", a);
	print_assertion(arrays_equal(a,b));

}

void test_swap()
{
	int A[5] = {1,2,3,4,5};
	int a = A[2];
	int b = A[3];
	swap(A,2,3);
	print_assertion(A[3] == a);
	print_assertion(A[2] == b);
}

void test_partition()
{
	printf("test_partition\n");
	int a[8] = {3, 8, 2, 5, 1, 4, 7, 6};
	int b[8] = {1, 2, 3, 5, 8, 4, 7, 6};
	int i = partition(a,0,8);
	print_assertion(arrays_equal(a,b));

}

void test_array_equals()
{
	printf("test_array_equals\n");
	int a[8] = {3, 8, 2, 5, 1, 4, 7, 6};
	int b[8] = {3, 8, 2, 5, 1, 4, 7, 6};
	print_assertion(arrays_equal(a,b));
	
}

void test_slice(int* a, int n)
{
	int c[2] = {2,3};
	for (int i = 0; i < n; ++i)
	{
		print_assertion(a[i] == c[i]);
	}
}

void test_quick_sort()
{
	printf("test_quick_sort\n");
	int a[5] = {4,3,5,1,2};
	int b[5] = {1,2,3,4,5};
	quick_sort(a, 5);
	print_assertion(arrays_equal(a,b));
}

void test_slice_array()
{
	printf("test_slice_array\n");
	int a[4] = {1,2,3,4};
	test_slice(a+1,2);

}
