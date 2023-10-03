/*#include<iostream>
using namespace std;

void unique(int arr[], int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << "The unique value is " << ans << endl;

}
int main(){
    int n;
    cout << "Enter the total value "<< endl;
    cin >> n;

    int arr[100];
    cout << "Put the elements " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unique(arr, n);
}*/

#include <iostream>
using namespace std;

void unique(int find[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (find[i] == find[j])
            {
                cout << "The unique value is "<< find[i] << endl;
                break;
            }
           
        }
    }
         //cout << "The unique value is "<< find[i] << endl;
}
int main()
{
    int n;
    cout << "Enter the value " << endl;
    cin >> n;

    int find[100];
    cout << "Put the value " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> find[i];
    }

    unique(find, n);
}