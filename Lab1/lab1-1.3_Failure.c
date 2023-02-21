#include <stdio.h>

int main()
{
    int marks[20][5];
    double sum[20];
    int i, j;
    float avg[20];
    // Loop get value
    for (i = 0; i < 20; i++)
    {
        scanf("%d %d %d %d %d", &marks[i][0], &marks[i][1], &marks[i][2], &marks[i][3], &marks[i][4]);
    }
    // Loop To Sum & Average
    for (i = 0; i < 20; i++)
    {
        sum[i] = 0;
        avg[i] = 0;
        for (j = 0; j < 5; j++)
        {
            sum[i] = marks[i][j] + sum[i];
        }
        avg[i] = sum[i] / 5;
    }
    // Print Result
    for (i = 0; i < 20; i++)
    {
        printf("%g\n", avg[i]);
    }
}