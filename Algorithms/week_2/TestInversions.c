#include <stdio.h>
#include "Inversions.h"
int print_invs_assertion(int expected, int found)
{
    printf("Found %i Inversions when I should have found %i inversions\n", found, expected);
}

void test_count_inversions()
{
    int a[6] = {1 , 3, 5, 2, 4, 6};
    int ans = 3;
    int invs = count_inversions(a, 6);
    print_invs_assertion(ans, invs);
    int b[10] = {5, 2, 10, 8, 1, 9, 4, 3, 6, 7};
    int bans = 22;
    int binvs = count_inversions(b, 10);
    print_invs_assertion(bans, binvs);
}

int main()
{
    test_count_inversions();
    return 0;
}