#include <stdio.h>
void main()
{
    int i, j, r, c, count = 0;
    int b[5][5], a[10][10];
    printf("Enter the number of rows : ");
    scanf("%d", &r);
    printf("Enter the number of columns : ");
    scanf("%d", &c);

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("Enter element at %d,%d", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                count++;
            }
            else
                continue;
        }
    }
    b[0][0] = r;
    b[0][1] = c;
    b[0][2] = count;
    int d = 1;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (a[i][j] != 0)
            {
                b[d][0] = i;
                b[d][1] = j;
                b[d][2] = a[i][j];
                d++;
            }
        }
    }
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
}