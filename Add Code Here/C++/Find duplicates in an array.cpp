//Find duplicates in an array

class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
         int a[n]={0};
         for(int i=0;i<n;i++)
         {
             a[arr[i]]++;
         }
         vector<int> v;
         int flag=0;
         for(int i=0;i<n;i++)
         {
             if(a[i]>1)
             {
                 v.push_back(i);
                 flag=1;
             }
         }
         if(flag==0)
         {
             return {-1};
         }
         return v;
    }
};
