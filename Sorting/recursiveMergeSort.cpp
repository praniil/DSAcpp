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

void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int length = sizeof(A) / sizeof(A[0]);
    int i;
    MergeSort(A, 0, length - 1);
    for (i = 0; i < length; i++)
    {
        printf("%d", A[i]);
        printf("\n");
    }

    return 0;
}