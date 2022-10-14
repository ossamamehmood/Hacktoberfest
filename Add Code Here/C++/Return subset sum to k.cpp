#include<iostream>
using namespace std;
/***In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here
    if(n==0)
    {
        if(k==0)
        {
            output[0][0]=0;
            return 1;
        }
        else
            return 0;
    }

    int smallOutput1=subsetSumToK(input+1,n-1,output,k);
    int smallOutput2=subsetSumToK(input+1,n-1,output+smallOutput1,k-input[0]);
    
    int smallOutputSize=smallOutput1+smallOutput2;
    for(int i=smallOutput1;i<smallOutputSize;i++)
    {
        for(int j=output[i][0];j>0;j--)
        {
            output[i][j+1]=output[i][j];
        }
        output[i][1]=input[0];
        output[i][0]++;
    }
    return smallOutputSize;
    
}

int main()
{
    int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

    int k;
    cin>>k;

	int output[20][50];

	int length=subsetSumToK(arr,n,output,k);
 
    cout<<length<<endl;

    for(int i=0;i<length;i++)
    {
        for(int j=1;j<output[i][0]+1;j++)
            cout<<output[i][j]<<" ";
        cout<<endl;
    }
}