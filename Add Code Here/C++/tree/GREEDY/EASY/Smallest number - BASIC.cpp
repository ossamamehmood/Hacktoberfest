/*
Smallest number 

Basic Accuracy: 43.69% Submissions: 8226 Points: 1
The task is to find the smallest number with given sum of digits as S and number of digits as D.

 

Example 1:

Input:
S = 9 
D = 2
Output:
18
Explanation:
18 is the smallest number
possible with sum = 9
and total digits = 2.
 

Example 2:

Input:
S = 20
D = 3
Output:
299
Explanation:
299 is the smallest number
possible with sum = 20
and total digits = 3.
 

Your Task:

You don't need to read input or print anything. Your task is to complete the function smallestNumber() which takes the two integers S and D and 
returns a string which is the smallest number if possible, else return "-1".

 

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)

 

Constraints:
1 = S = 100
1 = D = 6
*/

#include<bits/stdc++.h> 
using namespace std;
void smallestnumber(int s,int d){
    if(s==0){
        (d==1)?cout<<"0"<<"\n":cout<<"-1"<<"\n"; return;
    }
    if(s>9*d){cout<<"-1"<<"\n";return;}
    s-=1;
    int a[d];
    for(int i=d-1;i>0;i--){
        if(s>9){a[i]=9;s-=9;}
        else{a[i]=s;s=0; }
    }a[0]=s+1;
    for(int i=0;i<d;i++)
       cout<<a[i];
       cout<<"\n";
}
int main() {
int x;cin>>x;
   while(x--){
       int s,d;
       cin>>s>>d;
     smallestnumber(s,d);
   }
	return 0;
}
