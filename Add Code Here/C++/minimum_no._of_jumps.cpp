
class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1)
            return 0;
        if(n>1 && arr[0] == 0)
            return -1;
            
        int reach_upto = arr[0];
        int step_remain = arr[0];
        int jumps=0;
        
        for(int i=1; i<n; i++)
        {
            if(i==n-1)
                return jumps+1;
                
            step_remain--;
            reach_upto = max(reach_upto, arr[i]+i);
                
            if(step_remain == 0)
            {
                if(i==reach_upto)
                    return -1;
                jumps++;
                step_remain = reach_upto-i;
            }
        }
        return jumps;
    }
};