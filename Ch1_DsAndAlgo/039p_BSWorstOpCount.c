#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0; // start index
    int last = len - 1; // last index
    int mid;
    int opCount = 0;
    
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
        opCount++;
    }
    printf("Comparing operation number: %d\n", opCount);
    return -1; // cant find
}

int main(void)
{
    // initialize all elements 0
    int arr1[500] = {0,};
    int arr2[5000] = {0,};
    int arr3[50000] = {0,};
    int idx;

    idx = BSearch(arr1, sizeof(arr1)/sizeof(int), 1);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! idx is %d\n", idx);

    idx = BSearch(arr2, sizeof(arr2)/sizeof(int), 2);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! idx is %d\n", idx);

    idx = BSearch(arr3, sizeof(arr3)/sizeof(int), 3);
    if (idx == -1)
        printf("Fail to search\n");
    else
        printf("Success to search! idx is %d\n", idx); 
    return 0;
}