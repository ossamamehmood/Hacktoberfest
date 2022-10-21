#include <iostream>
using namespace std;
#include <conio.h>
int main()
{
    int m, n, p, q, A[10][10], B[10][10], C[10][10], D[10][10];
    cout << "Matrix addition and subtraction" << endl;
    cout << "Enter the order of first matrix";
    cin >> m >> n;

    cout << "Enter order of second matrix";
    cin >> p >> q;
    if ((m != p) || (n != q))
    {
        cout << "Matrix operation not possible";
        
    }
    // Read elements of first matrix
    cout << "Enter the elements of first matrix" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    // Read elements of second matrix
    cout << "Enter the elements of second matrix" << endl;
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> B[i][j];

    /*Store sum in matrix C and store difference in matrix D*/
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            D[i][j] = A[i][j] - B[i][j];
        }

    //displaying addition
    cout<<"result of addition is"<<endl;
    for (int i = 0; i < m; i++)
    {
        cout << endl;

        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << " ";
        }
    }
 cout<<"result of subtraction is"<<endl;
    //displaying subtraction
    for (int i = 0; i < m; i++)
    {
        cout << endl;

        for (int j = 0; j < n; j++)
        {
            cout << D[i][j] << " ";
        }
    }
    
}
