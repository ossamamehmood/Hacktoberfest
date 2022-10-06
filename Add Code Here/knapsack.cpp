#include<iostream>
using namespace std;

float knapsack(float p[], float w[], int W, int size);
void bubbleSort(float p[], float w[], int n);


int main()
{
    int n, W;
    cout<<"Enter the number of products:\n";
    cin>>n;
    float p[n], w[n];
    cout<<"Enter the total capacity of the knapsack:\n";
    cin>>W;
    cout<<"Enter the profits and weights of the products:\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i]>>w[i];
    }
    bubbleSort(p, w, n);
    cout<<"The total profit is "<<knapsack(p, w, W, n);
    return 0;
}

float knapsack(float p[], float w[], int W, int size)
{
    int weight = 0;
    float x[size];
    for(int i=0;i<size;i++)
    {
        x[i] = 0;
    }
    for(int i=0;i<size;i++)
    {
        if((weight+w[i]) <= W)
        {
            x[i] = 1;
            weight += w[i];
        }
        else
        {
            x[i] = (W-weight)/w[i];
            weight = W;
            break;
        }
    }
    float profit = 0;
    for(int i=0;i<size;i++)
    {
        profit = profit + (p[i]*x[i]);
    }
    return profit;
}

void bubbleSort(float p[], float w[], int n)
{
    int i, j;
    float ratio[n];
    for(int i=0;i<n;i++)
    {
        ratio[i] = (p[i]/w[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1; j++)
        {
            if(ratio[j] < ratio[j+1])
            {
                swap(ratio[j], ratio[j+1]);
                swap(p[j], p[j+1]);
                swap(w[j], w[j+1]);
            }
        }
    }
}