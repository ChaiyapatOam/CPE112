#include <stdio.h>

int main()
{
    int marks[20][5];
    double sum[5];
    int i, j;
    float avg[5];
    // Loop get value
    for (i = 0; i < 20; i++)
    {
        scanf("%d %d %d %d %d", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3], &marks[i][4]);
    }
    // Loop To Sum & Average
    for (j = 0; j < 5; j++)
    {
        sum[j] = 0;
        avg[j] = 0;
        for (i = 0; i < 20; i++)
        {
            sum[j] = marks[i][j] + sum[j];
        }
        avg[j] = sum[j] / 20;
    }
    // Print Result
    for (i = 0; i < 5; i++)
    {
        printf("%g\n", avg[i]);
    }
}