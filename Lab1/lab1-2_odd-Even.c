#include <stdio.h>

int eventChecker(int num)
{
    if (num % 2 == 0)
    {
        return 1;
    }
    else
        return 0;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    // Loop get value
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int countOdd = 0;
    int countEven = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            if (eventChecker(arr[i][j]) == 0)
            {
                countOdd++;
            }
            else
            {
                countEven++;
            }
        }
    }
    int evenArr[countEven];
    int oddArr[countOdd];
    countEven = 0;
    countOdd = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            if (eventChecker(arr[i][j]) == 0)
            {
                oddArr[countOdd] = arr[i][j];
                countOdd++;
            }
            else
            {
                evenArr[countEven] = arr[i][j];
                countEven++;
            }
        }
    }
    // Print Result
    if (countOdd <= 0)
    {
        printf("None");
    }
    else
    {
        for (int i = 0; i < countOdd; i++)
        {
            printf("%d ", oddArr[i]);
        }
    }
    printf("\n");
    if (countEven <= 0)
    {
        printf("None");
    }
    else
    {
        for (int i = 0; i < countEven; i++)
        {
            printf("%d ", evenArr[i]);
        }
    }
    return 0;
}