#include <stdio.h>
#include <stdlib.h>

/// m - size of mtr, i - row, j - column
void get_matrix(int **mtr, int m, int **p, int i, int j)
{
    int a, b, dx, dy;
    dy = 0;
    for (a = 0; a < m-1; a++)
    {
        dx = 0;
        if (a == i)
            dy = 1;
        for (b = 0; b < m-1; b++)
        {
            if (b == j)
                dx = 1;
            p[a][b] = mtr[a+dy][b+dx];
        }
    }
}

int determinant(int **mtr, int m, int flag)
{
    int d = 0, i;
    int k = 1; /// (-1)^n
    int **p;
    if (m < 1)
        puts("Error size of matrix");
    if (m == 1)
        return mtr[0][0];
    p = (int**) malloc((m-1)*sizeof(int*));
    for (i = 0; i < m-1; i++)
        p[i] = (int*) malloc((m-1)*sizeof(int));
    for (i = 0; i < m; i++)
    {
        get_matrix(mtr, m, p, 0, i);
        if (flag)
        {
            printf("%d ", k * determinant(p, m-1, 0));
        }
        else
        {
            d += k * mtr[0][i] * determinant(p, m-1, 0);
        }
        k = -k;
    }
    for (i = 0; i < m-1; i++)
        free(p[i]);
    free(p);
    return d;
}

int main()
{
    int N, i, j;
    int **coordinates;
    ///input
    scanf("%d", &N);
    coordinates = (int **) malloc((N + 1)*sizeof(int *));
    for (i = 1; i <= N; i++)
    {
        coordinates[i] = (int *) malloc((N + 1)*sizeof(int));
        for (j = 0; j <= N; j++)
        {
            scanf("%d", &coordinates[i][j]);
        }
    }
    ///������� ���������
    determinant(coordinates, N + 1, 1);
    puts("");
    for (i = 1; i <= N; i++)
    {
        free(coordinates[i]);
    }
    free(coordinates);
    return 0;
}
