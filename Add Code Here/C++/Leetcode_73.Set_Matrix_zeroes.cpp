#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
        set<int> s1;
        set<int> s2;
        // cout<<matrix.size()<<" "<<matrix[0].size()<<endl;
        for(int i = 0;i<matrix.size();i++)
        {
            for(int j = 0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        vector<int> A;
        vector<int> B;
        for(auto it : s1)
        {
            // cout<<it<<" ";
            A.push_back(it);
        }
        // cout<<endl;
        for(auto it : s2)
        {
            // cout<<it<<" ";
            B.push_back(it);
        }
        // cout<<endl;
        int k = 0,l = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            int j = 0;
            if(k<A.size() && i == A[k])
            {
                while(j<matrix[0].size())
                {
                    matrix[i][j] = 0;
                    j++;
                }
                k++;
            }
        }
        for(int j = 0;j<matrix[0].size();j++)
        {
            int a = 0;
            if(l<B.size() && j == B[l])
            {
                while(a<matrix.size())
                {
                    matrix[a][j] = 0;
                    a++;
                }
                l++;
            }
        }
       // return matrix;
    }
    int main()
    {
        int m, n, a[100][100], i, j;

        cout << "Enter number of rows (between 1 and 100): ";
        cin >> m;

        cout << "Enter number of columns (between 1 and 100): ";
        cin >> n;
        cout << endl << "Enter elements of matrix(only 1 or 0): " << endl;

        // Storing elements of first matrix entered by user.
        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cout << "Enter element a" << i + 1 << j + 1 << " : ";
                cin >> a[i][j];
            }
        }
        vector<vector<int>> matrix;
        for(i = 0; i < m; ++i)
        {
            vector<int> v;
            for(j = 0; j < n; ++j)
            {
                v.push_back(a[i][j]);
            }
            matrix.push_back(v);
        }
        setZeroes(matrix);
        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
