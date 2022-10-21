/*
Job Sequencing Problem 

Medium Accuracy: 48.94% Submissions: 41033 Points: 4
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.


Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = {(1,2,100),(2,1,19),(3,2,27),
        (4,1,25),(5,1,15)}
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).

Your Task :
You don't need to read input or print anything. Your task is to complete the function JobScheduling() which takes an integer N and an array of Jobs(Job id, Deadline, Profit) as input and returns the count of jobs and maximum profit.


Expected Time Complexity: O(NlogN)
Expected Auxilliary Space: O(N)


Constraints:
1 <= N <= 105
1 <= Deadline <= 100
1 <= Profit <= 500
*/

#include<bits/stdc++.h>
using namespace std;
struct job
{
    int id;
    int dead;
    int prof;
    job(int id,int dead,int prof)
    {
        this->id=id;
        this->dead=dead;
        this->prof=prof;
    }
};
bool comparator(job &j1,job &j2)
{
    return j1.dead<j2.dead;
}


int main()
{
    int tes,n,temp1,temp2,temp3,sum;
    cin>>tes;
    for(int t=0;t<tes;t++)
    {
        cin>>n;
        vector<job>v;
        for(int i=0;i<n;i++)
        {
            cin>>temp1>>temp2>>temp3;
            job j(temp1,temp2,temp3);
            v.push_back(j);
        }
        sort(v.begin(),v.end(),comparator);
        priority_queue<int,vector<int>,greater<int>> pq;
        pq.push(v[0].prof);
        int pqsize=1;
        for(int j=1;j<n;j++)
        {
            if(pqsize<v[j].dead)
            {
                pq.push(v[j].prof);
                pqsize++;
            }
            else if(v[j].prof>pq.top())
            {
                pq.pop();
                pq.push(v[j].prof);
            }
        }
        cout<<pqsize<<" ";
        sum=0;
        while(pqsize!=0)
        {
            sum=sum+pq.top();
            pq.pop();
            pqsize--;
        }
        cout<<sum<<endl;

    }
    return 0;
}

