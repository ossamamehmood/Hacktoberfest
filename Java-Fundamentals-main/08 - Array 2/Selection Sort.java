public class Solution {  

    public static void selectionSort(int[] arr) {
    	//Your code goes here
        
        int n = arr.length;
        
        for(int i=0;i<n-1;i++)
        {
            int min = i;
            
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]<arr[min])
                    min = j;
            }
            
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
            
        }
        
    }   

}