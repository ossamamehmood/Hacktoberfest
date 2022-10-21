Question:-


Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index).
The idea here is to represent each array/list as an integer in itself of digits N and M.
You need to find the sum of both the input arrays/list treating them as two integers and put the result in another array/list
i.e. output array/list will also contain only single digit at every index.
  
Note:
The sizes N and M can be different. 

Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more than the size of the bigger array/list. Place 0 at the 0th index if there is no carry. 

No need to print the elements of the output array/list.
Using the function "sumOfTwoArrays", write the solution to the problem and store the answer inside this output array/list. The main code will handle the printing of the output on its own.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements of the first array/list.

Third line contains an integer 'M' representing the size of the second array/list.

Fourth line contains 'M' single space separated integers representing the elements of the second array/list.
Output Format :
For each test case, print the required sum of the arrays/list in a row, separated by a single space.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
0 <= M <= 10^5
Time Limit: 1 sec 
Sample Input 1:
1
3
6 2 4
3
7 5 6
Sample Output 1:
1 3 8 0
Sample Input 2:
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9
Sample Output 2:
0 8 6 5
1 0 2 2 0 
  
Code:-
  
#include <bits/stdc++.h>
using namespace std;


void sumOfTwoArrays(int input1[], int size1, int input2[], int size2, int output[])
{
    using namespace std;
    int carry=0;
    int size3 = max(size1,size2);
    int i;
    int j;
    int add=0;
    for( i = size1-1,  j=size2-1;  i>=0&&j>=0; i--,j-- )
    {
         add=0;
         add=input1[i]+input2[j]+carry;
        
        if(add>9)
        {
            output[size3]=add%10;
            carry=add/10;
        }
        else
        {
            output[size3]=add;
            carry=0;
        }
    size3=size3-1;
    }
    add=0;
    while(i>=0)
    {
        add=input1[i]+carry;
        if(add>9)
        {
            output[size3]=carry%10;
            carry=add/10;
        }
        else
        {
            output[size3]=add;
            carry=0;
        }
        i=i-1;
        size3=size3-1;
    }
    while(j>=0)
    {
        add=input2[j]+carry;
        if(add>9)
        {
            output[size3]=carry%10;
            carry=add/10;
        }
        else
        {
            output[size3]=add;
            carry=0;
        }
        j=j-1;
        size3=size3-1;
    }
    output[size3]=carry;
}



int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}  
  
