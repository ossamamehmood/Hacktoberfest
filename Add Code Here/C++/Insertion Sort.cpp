// ---- AI Programming ------
// Implementation of Insertion Sort using C++
// Join our underground coding movement
// @freecodecs (c) May, 2019

#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"\nEnter the size of your element : ";
	cin>>n;
	int arr[n];
	cout<<"\nBy using space enter any "<<n<<" unsorted numbers : ";
	
	//Input Unsorted
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	//Sorting
	for(int i=1; i<n; i++)
	{
		int temp=arr[i];
		int j=i-1;
		while(j>=0 && temp<arr[j])
		{
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=temp;
	}
	
	//Output Sorted
	cout<<"\nSorted elements are : ";
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<", ";
	}
  return 0;
}

