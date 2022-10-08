#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 
    int dead; 
    int profit; 
};


class Solution 
{
    public:
     static bool comp(Job& j1, Job& j2)
    {
        return j1.profit > j2.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort( arr,arr+n,comp);
       // To know the max deadline
       int max_deadline=arr[0].dead;
       for( int i=0;i<n;i++)
       {
           max_deadline=max(max_deadline,arr[i].dead);
       }
       
       
       int job_slot[max_deadline+1];
       for( int i=0;i<=max_deadline;i++)
       {
           job_slot[i]=-1;
       }
       
       int profit=0;
       int job_count=0;
       
       for( int i=0;i<n;i++)
       {
           for( int j=arr[i].dead;j>0;j--)
           {
               if( job_slot[j]==-1)
               {
                   job_slot[j]=i;
                   profit=profit+arr[i].profit;
                   job_count++;
                   break;
               }
           }
       }
       
       vector<int>result;
       result.push_back(job_count);
       result.push_back(profit);
       
       return result;
    }
};

int main() 
{ 
    int t;
   
    cin >> t;
    
    while(t--){
        int n;
        
       
        cin >> n;
        Job arr[n];
        
       
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
       
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}

