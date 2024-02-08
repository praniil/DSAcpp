#include <iostream>
#include <stdio.h>

void merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[100]; // axulliary array
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= high; j++)
    {
        B[k++] = A[j];
    }
    for (i = 0; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void iterativeMergeSort(int array[], int length)
{
    int pass, low, high, mid, i;
    for (pass = 2; pass <= length; pass = pass * 2)
    {
        for (i = 0; i + pass - 1 < length; i = i + pass)
        {
            low = i;
            high = i + pass - 1;
            mid = (low + high) / 2;
            merge(array, low, mid, high); // perform for one pass and merge that and again do it for another pass
        }
    }
    if (pass / 2 < length)
    {
        merge(array, 0, pass / 2 - 1, length - 1);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int length = sizeof(A) / sizeof(A[0]);
    int i;
    iterativeMergeSort(A, length);
    for (i = 0; i < length; i++)
    {
        printf("%d", A[i]);
        printf("\n");
    }

    return 0;
}