#include <iostream>

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low, j = high;
    while (i < j)
    {
        do
        {
            i++;
        } while (array[i] <= pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        if (i < j)
        {
            int temp;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp;
    temp = array[j];
    array[j] = array[low];
    array[low] = temp;
    return j;
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int j = partition(array, low, high);
        quickSort(array, low, j);
        quickSort(array, j + 1, high);
    }
}

int main()
{
    int array[] = {10, 16, 8, 12, 15, 6, 3, 9, 5, 1000};
    int length = sizeof(array) / sizeof(array[0]);
    // printf("%d", length);
    quickSort(array, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        printf("%d \t", array[i]);
        printf("\n");
    }
    return 0;
}