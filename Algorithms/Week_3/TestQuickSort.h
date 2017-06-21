#define TestQuickSort
#include "QuickSort.h"

void test_load_array()
{
	printf("test_load_array\n");
	int a[8];
	int b[8] = {1,2,12,3,5,7,123,56};
	load_array_from_file("test_input.txt", a, 8);
	print_assertion(arrays_equal(a,b));
	printf("large_input\n");
	int B[100];
	load_array_from_file("test_long_input.txt", B, 100);
	print_assertion(B[0]==79);
	print_assertion(B[99]==78);

}

void test_swap()
{
	printf("test_swap\n");
	int A[5] = {1,2,3,4,5};
	int a = A[2];
	int b = A[3];
	swap(A,2,3);
	print_assertion(A[3] == a);
	print_assertion(A[2] == b);
	printf("large_input\n");
	int B[100];
	load_array_from_file("quicksort_input.txt", B, 100);
	a = B[7];
	b = B[43];
	swap(B, 7, 43);
	print_assertion(B[43] == a);
	print_assertion(B[7] == b);

}

void test_partition()
{
	printf("test_partition\n");
	int a[8] = {3, 8, 2, 5, 1, 4, 7, 6};
	int b[8] = {1, 2, 3, 5, 8, 4, 7, 6};
	int i = partition(a,0,8);
	print_assertion(arrays_equal(a,b));
	printf("long_input\n");
	int B[100];
	load_array_from_file("test_long_input.txt", B, 100);
	int c = B[0];
	int d = partition(B,0,100);
	for (int j = 0; j < d; ++j)
	{
		if (B[j] > c)
		{
			printf("Not partitioned!!\n");
		}
	}
	for (int k = d+1; k < 100; ++k)
	{
		if (B[k] < c)
		{
			printf("Not partitioned!!\n");
		}
	}
	print_assertion(1);

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
    int count[1] = {0};
	quick_sort(a, 5, count,  0);
	print_assertion(arrays_equal(a,b));
}

void test_long_input()
{
	printf("test_long_input\n");
	int a[100];
	load_array_from_file("test_long_input.txt", a, 100);
	int count[1] = {0};
    quick_sort(a, 100, count, 0);
	for (int i = 0; i < 100; ++i)
	{
		if (a[i] != i)
		{
			printf("Not Sorted correctly %i!", a[i]);

		}
	}
	print_assertion(1);
}

void _test_partition_slice(int* a, int p, int n, int first_half)
{
	if (first_half)
	{
		printf("In the first half with p = %i and an n of %i\n", p, n);
	}
	else
	{
		printf("In the second half with p = %i and an n of %i\n", p, n);
	}
	for (int i = 0; i < n; ++i)
	{	
		if (a[i] > p)
		{
			if (first_half)
			{
				printf("a[%i]\n", a[i]);
				print_assertion(0);
			}	
		}
		else if (a[i] == p)
		{
			printf("a[%i]\n", a[i]);
			print_assertion(0);
		}
		else 
		{
			if(!(first_half))
			{
				printf("a[%i]\n", a[i]);
				print_assertion(0);
			}
		}
		
	}
}

void test_partition_slice()
{
	int B[99];
	load_array_from_file("test_long_input.txt", B, 99);
	int c = B[0];
	int d = partition(B,0,99);
	print_assertion(c == B[d-1]);
	// print_array_oflength(B, d-1);
	_test_partition_slice(B, c, d-1, 1);
	_test_partition_slice(B + d, c, 99-d, 0);

}

void test_slice_array()
{
	printf("test_slice_array\n");
	int a[4] = {1,2,3,4};
	test_slice(a+1,2);

}

void test_place_pivot()
{
    printf("test_place_pivot\n");
    int n = 5;
    int a[5] = {4,3,5,1,2};
    int b[5] = { 3, 2, 1, 4, 5 };
    place_pivot(a, n, 1);
    print_assertion(a[0] == 2);
    print_assertion(a[n-1] == 4);
    int c[5] = {1,2,5,4,3};
    place_pivot(c, 5, 2);
    int d[4] = {4,5,6,7};
    place_pivot(d, 4, 2);
    place_pivot(b, 5, 2);
    print_assertion(c[0] == 3);
    print_assertion(d[0] == 5);
    print_assertion(b[0] == 3);
}

void test_count()
{
    int a[10];
    int count[1] = {0};
    load_array_from_file("quicksort_input.txt", a, 10);
    quick_sort(a, 10, count, 0);
    printf("Got a count of %i\n", count[0]);
    print_assertion(count[0] == 25);
}

void test_case_one()
{
    printf("\n Case One \n");
    int n = 5;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_01_5.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_01_5.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_01_5.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_01_5.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}

void test_case_two()
{
    printf("\n Case two \n");
    int n = 5;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_02_5.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_02_5.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_02_5.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_02_5.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}

void test_case_three()
{
    printf("\n Case three \n");
    int n = 5;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_03_5.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_03_5.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_03_5.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_03_5.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}

void test_case_four()
{
    printf("\n Case four \n");
    int n = 5;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_04_5.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_04_5.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_04_5.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_04_5.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}

void test_case_five()
{
    printf("\n Case five \n");
    int n = 5;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_05_5.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_05_5.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_05_5.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_05_5.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}

void test_case_six()
{
    printf("\n Case six \n");
    int n = 10;
    int a[n];
    int b[n];
    int c[n];
    load_array_from_file("testCases/input_dgrcode_06_10.txt", a, n);
    load_array_from_file("testCases/input_dgrcode_06_10.txt", b, n);
    load_array_from_file("testCases/input_dgrcode_06_10.txt", c, n);
    int count[3] = {0,0,0};
    quick_sort(a, n, count, 0);
    quick_sort(b, n, count, 1);
    quick_sort(c, n, count, 2);
    int expected[3];
    load_array_from_file("testCases/output_dgrcode_06_10.txt", expected, 3);
    print_assertion(count[0] == expected[0]);
    print_assertion(count[1] == expected[1]);
    print_assertion(count[2] == expected[2]);
}


