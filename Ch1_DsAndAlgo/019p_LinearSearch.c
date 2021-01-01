#include <stdio.h>

int LSearch(int ar[], int len, int target) // Linear Search func
{
    for (int i = 0; i < len; i++)
    {
        if (ar[i] == target)
            return i; // return searched target's idx
    }
    return -1; // return "cant find" by -1
}

int main(void)
{
    int arr[] = {3, 5, 2, 4, 9};
    int idx;

    idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);
    if (idx == -1)
        printf("Fail to search!\n");
    else
        printf("Success to search! Idx is %d\n", idx);
    
    idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);
    if (idx == -1)
        printf("Fail to search!\n");
    else
        printf("Success to search! Idx is %d\n", idx);
    return 0;
}