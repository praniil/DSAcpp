#include <iostream>

void Insert(int heap[], int index)
{
    int i = index, temp;
    temp = heap[i];

    while (i > 1 && temp > heap[i / 2])
    {
        heap[i] = heap[i / 2];
        i = i / 2;
    }

    heap[i] = temp;
}

int Delete(int heap[], int length)
{
    int val;
    int deleted = heap[1];
    int temp = heap[length];
    heap[1] = temp;
    int i = 1, j = i * 2;
    val = heap[1];
    while (j < length - 1)
    {
        if (heap[j + 1] > heap[j])
        {
            j = j + 1;
        }
        if (heap[i] < heap[j])
        {
            temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return val;
}

int main()
{
    int heapArray[] = {0, 2, 5, 8, 9, 4, 10, 7}; // 1st index 0 is not used so only 7 elements are present in the heap
    int length = sizeof(heapArray) / sizeof(heapArray[0]);
    for (int i = 2; i <= length - 1; i++)
    {
        Insert(heapArray, i);
    }

    printf("Deleted vaule is %d\n", Delete(heapArray, length - 1));

    for (int i = 1; i <= length - 1; i++)
    {
        printf("%d \n", heapArray[i]);
    }
}