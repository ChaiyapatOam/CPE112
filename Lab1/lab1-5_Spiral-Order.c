#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int init_row = 0, init_col = 0;
    int row = m - 1;
    int col = n - 1;
    while (init_row <= row && init_col <= col)
    {
        for (int i = init_col; i <= col; i++)
        {
            printf("%d ", arr[init_row][i]);
        }
        init_row++;
        for (int i = init_row; i >= col; i++)
        {
            printf("%d ", arr[i][col]);
        }
        col--;
        for (int i = col; i >= init_col; i--)
        {
            printf("%d ", arr[row][i]);
        }
        row--;
        for (int i = row; i >= init_row; i--)
        {
            printf("%d ", arr[i][init_col]);
        }
        init_col++;
    }

    return 0;
}