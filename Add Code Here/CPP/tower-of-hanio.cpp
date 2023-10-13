#include <iostream>

using namespace std;

void TOH(int n, char source, char aux, char dest)
{
    if (n == 1)
    {
        printf("Moved disc %d from %c to %c\n", n, source, dest);
    }
    else
    {
        TOH(n - 1, source, dest, aux);
        printf("Moved disc %d from %c to %c\n", n, source, dest);
        TOH(n - 1, aux, source, dest);
    }
}

int main()
{
    int disc;
    cout << "Enter the number of discs: ";
    cin >> disc;
    TOH(disc,'A','B','C');
    
}