
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    clock_t start, end;
    double cpu_time_used;
    start=clock();
    int diff= 9999999;
    int n;
    int l1=0, r1=0;
    //taking input from user of size of the array
    printf("Enter size of array\n");
    cin>>n;
    int arr[n];
    //taking input of elements of array
    printf("Enter elements of the sorted array \n");
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    // maintain two indices pointing to endpoints of the array
    int l=0, r=n-1;
    //storing target value in sum using random function
    int sum= rand()%100;
    printf("Random value of Sum we check closest for is %d \n", sum);
    // reduce the search space `arr[l to r]` at each iteration of the loop
    // loop till the search space is exhausted
    while(r>l)
    {
        if(abs(arr[l]+arr[r]-sum)<diff)
        {
            l1=l;
            r1=r;
            diff=abs(arr[l]+arr[r]-sum);
        }
        
        if (arr[l] + arr[r] > sum)
		    r--;
	    else 
	     	l++;
    }
    printf("Elements that have their sum closest to %d in this array are %d and %d \n", sum, arr[l1], arr[r1]);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout<<"Time taken to execute this program is "<<cpu_time_used<<" seconds"<<endl;
    return 0;
}


