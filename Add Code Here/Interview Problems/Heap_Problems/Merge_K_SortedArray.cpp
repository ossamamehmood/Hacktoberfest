#include<bits/stdc++.h>
using namespace std;


class node
{
public:
    int data;
    int r;
    int c;

    node(int data, int row, int col)
    {
        this->data = data;
        r = row;
        c = col;
    }
};

class compare
{
public:
    bool operator()(node *a, node *b)
    {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<node *, vector<node *>, compare> minHeap;

    for (int i = 0; i < k; i++)
    {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;
    while (minHeap.size() > 0)
    {
        node *temp = minHeap.top();

        ans.push_back(temp->data);
        minHeap.pop();

        int RowIndex = temp->r;
        int ColIndex = temp->c;

        if (ColIndex + 1 < kArrays[RowIndex].size())
        {
            node *temp = new node(kArrays[RowIndex][ColIndex + 1], RowIndex, ColIndex + 1);
            minHeap.push(temp);
        }
    }
    return ans;
}
