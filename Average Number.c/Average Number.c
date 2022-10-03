#include <iostream>

using namespace std;

int main()

{

    int t;

    cin>>t;

    while(t--)

    {

        int a,b,c;

        cin>>a>>b>>c;

        int arr[a];

        for(int i=0;i<a;i++)

        {

            cin>>arr[i];

        }

        int d=0;

        for(int i=0;i<a;i++)

        {

            d=d+arr[i];

        }

        int e=0;

        e=(a+b)*c;

        if((e-d)%b==0 && (e-d)>b)

        {

            cout<<(e-d)/b<<endl;

        }

        else 

        {

            cout<<-1<<endl;

        }



    }

}
