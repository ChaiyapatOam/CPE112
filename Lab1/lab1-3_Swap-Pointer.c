#include <stdio.h>

void swapPointer(int *secondSmallest, int *secondLargest)
{
    int temp;
    temp = *secondSmallest;
    *secondSmallest = *secondLargest;
    *secondLargest = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int restedArr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        restedArr[i] = arr[i];
    }
    int position = 0;
    for (int i = 0; i < n - 1; i++)
    {
        position = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[position] > arr[j])
                position = j;
        }
        if (position != i)
        {
            int temp = arr[i];
            arr[i] = arr[position];
            arr[position] = temp;
        }
    }
    int second_smallestIndex = 0;
    int second_largestIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (restedArr[i] == arr[1])
        {
            second_smallestIndex = i;
        }
        if (restedArr[i] == arr[n - 2])
        {
            second_largestIndex = i;
        }
    }

    swapPointer(&restedArr[second_smallestIndex], &restedArr[second_largestIndex]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", restedArr[i]);
    }

    return 0;
}