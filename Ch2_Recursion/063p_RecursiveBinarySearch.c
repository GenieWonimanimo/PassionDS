// only fur accustomed for recursion, iterative version is more effective
#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
    int mid;
    if (first > last)
        return -1; // fail to search
    mid = (first + last) / 2; // find mid

    if (ar[mid] == target)
        return mid; // return target's index
    else if (target < ar[mid])
        BSearchRecur(ar, first, mid - 1, target);
    else
        BSearchRecur(ar, mid + 1, last, target);
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 7);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! index is %d\n", idx);
    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) - 1, 4);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! index is %d\n", idx);

    return 0;
}