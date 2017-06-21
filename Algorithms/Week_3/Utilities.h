#define Utilities

void load_array_from_file(char* file_location, int* a, int n)
{
	FILE* file = fopen (file_location, "r");
	int i = 0;
	for (int i = 0; i < n; ++i)
	{
		fscanf (file, "%d", &a[i]);
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