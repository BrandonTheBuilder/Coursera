#include <stdio.h>
#include "Inversions.h"
int print_invs_assertion(int expected, int found)
{
    printf("Found %i Inversions when I should have found %i inversions\n", found, expected);
}

int print_long_invs_assertion(long expected, long found)
{
    printf("Found %lo Inversions when I should have found %lo inversions\n", found, expected);
}

void test_count_inversions()
{
    int a[6] = {1 , 3, 5, 2, 4, 6};
    int ans = 3;
    int invs = count_inversions(a, 6);
    print_invs_assertion(ans, invs);
    int invsFromCount = getInvCount(a);
    print_invs_assertion(invsFromCount, ans);
    int b[10] = {5, 2, 10, 8, 1, 9, 4, 3, 6, 7};
    int bans = 22;
    int binvs = count_inversions(b, 10);
    print_invs_assertion(bans, binvs);
}

void test_long_input()
{
    printf("\n long input \n");
    int n = 1000000;
    long ans = 250106195909;
    int a[n];
    load_array_from_file("input_1000000", a, n);
    long invs = count_inversions(a, n);
    
    print_invs_assertion(ans, invs);
}

int main()
{
    test_count_inversions();
    test_long_input();
    return 0;
}
