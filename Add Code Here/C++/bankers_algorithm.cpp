#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int r;
    cout << "\nEnter number of process :";
    cin >> n;
    cout << "\n Enter  resources available : ";
    cin >> r;
    // 2D array for need , allocation & max
    long int need[n][r], allocate[n][r], max[n][r];
    // 1D array for available
    int avail[r];
    // Initial available resources(given)
    cout << "\nEnter initial available resources :\n";
    for (int i = 0; i < r; i++)
    {
        cout << "The initial availability of " << i + 1 << "th process\n";
        cin >> avail[i];
    }
    vector<int> v;
    // Inputing allocation matrix
    cout << "\n Enter allocation matrix  \n";
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < r; j++)
        {
            cout << "The allocation for " << i + 1 << "th process"<< "of " << j + 1 << "th resources\n";
            cin >> allocate[i][j];
        }
    }
    // Inputing max requirement of each process
    cout << "\n Enter MAX matrix  \n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << "The max allocation for " << i + 1 << "th process"<< "of " << j + 1 << "th resources\n";
            cin >> max[i][j];
        }
    }
    // calculating NEED MATRIX
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocate[i][j];
        }
    }
    cout << "The need matrix is\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < r; j++)
        {
            cout << need[i][j] << " ";
        }
        cout << '\n';
    }
    // checking for safe state
    bool inSafe[n]{};
    int curr = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (inSafe[j] == 0)
            {
                bool flag = false;
                for (int k = 0; k < r; k++)
                {
                    if (avail[k] < need[j][k])
                    {
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    v.push_back(j);
                    curr++;
                    for (int l = 0; l < r; l++)
                    {
                        avail[l] += allocate[j][l];
                    }
                    inSafe[j] = 1;
                }
            }
        }
    }
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (inSafe[i] == 0)
        {
            check = false;
            cout << "No!!!The sequence is not in safe state\n";
            break;
        }
    }
    if (check)
    {
        cout << "The safe state:-\n";
    }
    // Safe sequence
    for (auto &e : v)
    {
        cout << "process " << e << " --> ";
    }
    // here:
    return 0;
}