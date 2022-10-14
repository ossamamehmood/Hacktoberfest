// https://www.codingninjas.com/codestudio/problems/find-unique_625159

int findUnique(int *arr, int size)
{
     int ans = 0;
        for(int i=0;i<size;i++){
            ans = ans ^ arr[i];
        }
        return ans;
}