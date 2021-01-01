#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0; // start index
    int last = len - 1; // last index
    int mid;
    
    while (first <= last)
    {
        mid = (first + last) / 2; // find the middle
        if (target == ar[mid]) // if stored in mid is target
            return mid; // search finish
        else // make target size 1/2
        {
            if (target < ar[mid])
                last = mid - 1; // already confirmed mid is not target
            else
                first = mid + 1; // already confirmed mid is not target
        }
    }
    return -1; // cant find
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 7);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! idx is %d\n", idx);

    idx = BSearch(arr, sizeof(arr)/sizeof(int), 4);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! idx is %d\n", idx);
    return 0;
}