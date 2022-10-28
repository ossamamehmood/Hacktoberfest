#include <iostream>
// #include <set>
// #include <algorithm>
// #include <iterator>
// #define ll long long
using namespace std;

int main() {
	int n,m,i,ansindexa,ansindexb,minansindexa,minansindexb;
	int maxa=-1000000001,maxb=-1000000001,mina=1000000000,minb=1000000000;
	
	cin>>n>>m;
	int a[n];
	int b[m];
	for(i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(a[i]>=maxa)
	    {
	        maxa=a[i];
	        ansindexa=i;
	    }
	    if(a[i]<=mina)
	    {
	        mina=a[i];
	        minansindexa=i;
	    }
	}
    for(i=0;i<m;i++)
	{
	    cin>>b[i];
	    if(b[i]>=maxb)
	    {
	        maxb=b[i];
	        ansindexb=i;
	    }
	    if(b[i]<=minb)
	    {
	        minb=b[i];
	        minansindexb=i;
	    }
	}
	if(n>=m)
	{   
	    for(i=0;i<n;i++)
	    {
	        cout<<i<<" "<< minansindexb<<endl;
	    }
	    for(i=0;i<m;i++)
	    {   if(i==minansindexb)
	        continue;
	        else
	        cout<<ansindexa<<" "<<i<<endl;
	    }
	    
	}
	if(m>n)
	{
	    for(i=0;i<m;i++)
	    {
	        cout<<minansindexa <<" "<<i<<endl;
	    }
	    for(i=0;i<n;i++)
	    {   if(i==minansindexa)
	        continue;
	        else
	        cout<<i<<" "<<ansindexb<<endl;
	    }
	        

	}
	
	return 0;
}
