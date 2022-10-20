#include<iostream>
#include<queue>

using namespace std;

main()
{
    system("cls");
    queue<int> q, temp;

    int n;
    cout<<"Enter size of queue: ";
    cin>>n;

    for (int i=0; i<n; i++)
    {
        int inp;
        cin>>inp;
        q.push(inp);
    }

    int stop = 1;
    cout<<"\n\n========Left Rotate========\n\nOriginal List: ";
    
    temp = q;
    while (!temp.empty())
    {
        cout << temp.front()<< " ";
        temp.pop();
    }
        

    int k;
    cout<<"\n\nNumber of rotations:";
    cin>>k;

    for(int i=1; i<=k%n; i++)
    {
        q.push(q.front());
        q.pop();
    }
    

    cout<<"\n\nRotated List: ";

    temp = q;
    while (!temp.empty())
    {
        cout << temp.front()<< " ";
        temp.pop();
    }
}
