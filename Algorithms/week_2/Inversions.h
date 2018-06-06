#define Inversions
#include "Utilities.h"
#include <string.h>
#include <stdio.h>

int log_level = 0;
int merge_log_level = 0;

long count_split_inversions(int *b, int *c, int *d, int n)
{
    int len_b = n/2 + n%2;
    int len_c = n-len_b;
    int j = 0;
    int i = 0;
    if(n == merge_log_level)
    {
        printf("b\n");
        print_array_oflength(b, len_b);
    }
    if(n == merge_log_level)
    {
        printf("c\n");
        print_array_oflength(c, len_c);
    }
    if(n == merge_log_level)
    {
        printf("d before\n");
        print_array_oflength(d, n);
    }
    long invs = 0;
    for (int k = 0; k < n; ++k)
    {
        
        if(n == merge_log_level)
        {// 
            printf("b[i], c[j] = %i, %i\n", b[i], c[j]);
        }
        if (b[i] < c[j] || j == len_c && i != len_b)
        {
            d[k] = b[i];
            i++;
        }
        else if (c[j] < b[i] || i == len_b)
        {
            d[k] = c[j];
            j++;
            invs+=(len_b-i);
            if(n == merge_log_level)
            {// 
                printf("Found %i inversion!\n", len_b-i);
            }
        }
        if (i == len_b)
        {
            if(n == merge_log_level)
            {
                printf("Hit end condition i == len_b, i = %i, j = %i, k = %i, n = %i\n", i, j, k, n);
                printf("copying:");
                print_array_oflength(c+j, len_c-j);
                printf("\nto:");
                print_array_oflength(d+k+1, len_c-j);
            }            
            memcpy(d+k+1, c+j, (len_c-j)*sizeof(int));
            if(n == merge_log_level)
            {
                printf("\nd after:");
                print_array_oflength(d, n);
                printf("\n");
            }
            return invs;
        }
        if (j == len_c)
        {
            if(n == merge_log_level)
            {
                printf("Hit end condition j == len_c, i = %i, j = %i, k = %i, n = %i\n", i, j, k, n);
                printf("d after\n");
                printf("copying:");
                print_array_oflength(b+i, len_b-i);
                printf("\nto:");
                print_array_oflength(d+k+1, len_b-i);

            }
            memcpy(d+k+1, b+i, (len_b-i)*sizeof(int));
            if(n == merge_log_level)
            {
                printf("\nd after:");
                print_array_oflength(d, n);
                printf("\n");
            }
            return invs;
        }
    }
    if(n == 2)
    {
        printf("d after outside\n");
        print_array_oflength(d, n);
    }
    return invs;
}

int getInvCount(int arr[], int n)
{
  int inv_count = 0;
  for (int i = 0; i < n - 1; i++)
    for (int j = i+1; j < n; j++)
      if (arr[i] > arr[j])
        inv_count++;
 
  return inv_count;
}

long count_inversions(int* a, int n)
{
    if( n == 1) 
    {
        return 0;
    }
    if(n == log_level)
    {
        printf("a before\n");
        print_array_oflength(a, n);
    }
    int m = n/2 + n%2;
    int b[m];
    memcpy(b, a, m*sizeof(int));
    if(n == log_level)
    {
        printf("b before\n");
        print_array_oflength(b, m);
    }
    int c[n-m];
    memcpy(c, a+m, (n-m)*sizeof(int));
    if(n == log_level)
    {
        printf("c before\n");
        print_array_oflength(c, n-m);    
    }
    int d[n];
    memset(d, 0, n*sizeof(int));
    long x = count_inversions(b, m);
    if(n == log_level)
    {
        printf("b after\n");
        print_array_oflength(b, m);
    }
    long y = count_inversions(c, n-m);
    if(n == log_level)
    {
        printf("c after\n");
        print_array_oflength(c, n-m);
    }
    long z = count_split_inversions(b, c, d, n);
    memcpy(a, d, n*sizeof(int));
if(n == log_level)
{
        printf("a after\n");
        print_array_oflength(a, n);
    }
    return x + y + z;
}
