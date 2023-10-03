/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    void insertHeap(int &x)
    {
        // If left side is empty then insert into left
        // If topmost element of left (which is currently the median) is greater than x. Then x will be smaller than median. Hence it will lie in the left side
        if (maxheap.empty() || maxheap.top() >= x)
        {
            maxheap.push(x);
        }
        // x is greater than median. Hence it will lie in right side
        else
        {
            minheap.push(x);
        }
        // Compare two sides sizes
        // Both heaps equal ==> Ignore
        // If left side has 2 or more elements than right side ==> Move topmost element from left to right
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        // If right side is greater ==> Move element from right side to left side
        else if (maxheap.size() < minheap.size())
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    // Function to return Median.
    double getMedian()
    {
        // Equal size
        if (maxheap.size() == minheap.size())
        {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        // Left will always have more size than right
        else
        {
            return maxheap.top();
        }
    }
};

int main()
{
    int arr[] = {5, 15, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution s = Solution(); 
    for(int i=0; i<n; i++){
        s.insertHeap(arr[i]);
        cout<< s.getMedian()<<endl;
    }
    return 0;
}