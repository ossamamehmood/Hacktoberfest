#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {

        int n = graph.size();
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++)
        {
            for (int node : graph[i])
            {
                adjList[i].push_back(node);
            }
        }

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(i);
        }

        int minLen = INT_MAX;
        while (!pq.empty())
        {
            int start = pq.top();
            pq.pop();

            vector<int> visited(n, 0);
            getLen(adjList, visited, start);

            if (!isValid(visited))
                continue;

            minLen = min(calcLen(visited), minLen);
        }

        return minLen != INT_MAX ? minLen : -1;
    }

private:
    int calcLen(vector<int> &visited)
    {
        int len = 0;
        for (int v : visited)
            len += v;
        return len - 1;
    }

    bool isValid(vector<int> &visited)
    {
        for (int v : visited)
            if (v == 0)
                return false;
        return true;
    }

    void getLen(vector<vector<int>> &adjList, vector<int> &visited, int index)
    {
        visited[index]++;
        if (isValid(visited))
            return;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int node : adjList[index])
        {
            pq.push(node);
        }

        while (!pq.empty())
        {
            int curr = pq.top();
            pq.pop();

            if (!isValid(visited) && visited[curr] < adjList[curr].size())
            {
                getLen(adjList, visited, curr);
            }
        }
    }
};

int main()
{

    // call your fn here

    return 0;
}