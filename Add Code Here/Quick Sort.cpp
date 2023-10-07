class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
            int p=partition(arr, low, high);
            quickSort(arr, low, p-1);
            quickSort(arr, p+1, high);
        }
        // code here
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot=arr[low];
        int i=low;
        int j=high;
        while(i<j)
        {
            while(arr[i]<=pivot && i<=high-1)
            {
                i++;
            }
            while(arr[j]>pivot && j>=low+1)
            {
                j--;
            }
            if(i<j)
            {
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low],arr[j]);
        return j;
       // Your code here
    }
};
