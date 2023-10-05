#include <stdio.h>
#include <string.h>

int match(char st[100], char pat[100], int *validShifts)
{
    int n, m, i, j;
    int flag = -1;
    n = strlen(st);
    m = strlen(pat);
    i = 0;
    *validShifts = 0; // Initialize the valid shift count to 0
    do
    {
        j = 0;
        if (st[i + j] == pat[j])
        {
            for (j = 0; j < m; j++)
                if (st[i + j] != pat[j])
                    break;
            if (j == m)
            {
                printf("Pattern Found at index %d\n", i);
                (*validShifts)++; 
            }
            flag = 1;
            i = i + j;
        }
        else
            i++;
    } while (i <= n);
    return flag;
}

int main(int argc, char **argv)
{
    char st[100], pat[100];
    int status, validShifts;
    printf("*** Optimized Naive String Matching Algorithm ***\n");
    printf("Enter the String.\n");
    gets(st);
    printf("Enter the pattern to match.\n");
    gets(pat);
    status = match(st, pat, &validShifts);
    if (status == -1)
        printf("\nNo match found");
    printf("Total number of valid shifts: %d\n", validShifts); 
}

