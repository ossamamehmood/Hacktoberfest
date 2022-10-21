#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

int multiply(int x, int res[], int res_size);

void factorial(int x)
{
    int res[MAX], res_size;
    res[0] = 1;
    res_size = 1;

    for (int i = 2; i <= x; i++)
    {
        res_size = multiply(i, res, res_size);
    }

    for (int j = res_size - 1; j >= 0; j--)
    {
        cout << res[j];
    }
    cout << "\n";
}

int multiply(int x, int res[], int res_size)
{
    int carry = 0, prod;

    for (int i = 0; i < res_size; i++)
    {
        prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        res[res_size++] = carry % 10;
        carry = carry / 10;
    }
    return res_size;
}

int main()
{
    int a;
    printf("Enter the number: ");
    scanf("%d", &a);

    printf("The Factorial of %d is: ", a);
    factorial(a);

    return 0;
}
