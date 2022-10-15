#include <stdio.h>
#include <time.h>
int a[10][10], visited[10], n, cost = 0;
mincost(int city)
{
    int i, ncity;
    visited[city] = 1;
    printf("%d -->", city + 1);
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0; // ncity is next city
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}
int least(int c)
{
    int i, nc = 999;
    int min = 999;
    for (i = 0; i < n; i++)
    {
        if ((a[c][i] != 0) && (visited[i] == 0))
            if (a[c][i] < min)
            {
                min = a[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += min;
    return nc;
}
void main()
{
    int i, j;
    double clk;
    clock_t starttime, endtime;
    printf("Enter No. of Cities: ");
    scanf("%d", &n);
    printf("\n Enter Cost Matrix\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row # : %d\n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
    }
    printf("\n\nThe cost list is:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\n\n");
        for (j = 0; j < n; j++)
            printf("\t%d", a[i][j]);
    }
    printf("\n\nThe Path is:\n\n");
    starttime = clock();
    mincost(0);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;
    printf("\n\nMinimum cost:%d\n", cost);
    printf("\nThe run time is %f\n", clk);
}