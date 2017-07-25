#define Inversions
#include "Utilities.h"

int count_split_inversions(int* a, int n)
{
    print_array_oflength(a, n);
    int m = n/2 + n%2;
    int j = m;
    int i = 0;
    int invs = 0;
    for (int k = 0; k < n; ++k)
    {
        if (i == m || j == n)
        {
            return invs;
        }
        printf("a[i], a[j] = %i, %i\n", a[i], a[j]);
        if (a[i] < a[j])
        {
            i++;
        }
        else if (a[j] < a[i])
        {
            j++;
            invs+=(m-i);
            printf("Found %i inversion!\n", m-i);
        }
    }
    return invs;
}

int count_inversions(int* a, int n)
{
    if( n == 1) 
    {
        return 0;
    }
    int m = n/2 + n%2;
    int x = count_inversions(a, m);
    int y = count_inversions( a+m, n-m );
    int z = count_split_inversions(a, n);
    return x + y + z;
}
