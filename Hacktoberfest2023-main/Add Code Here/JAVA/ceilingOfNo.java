

public class ceilingOfNo {

    public static void main(String[] args) {


        // Given is a sorted array 
        int[] arr ={2,3,4,6,8,9,11,14,15,17,19,22,49,68};
        int target=55;
        int ans = search(arr, target);
        System.out.println(ans);
        
    }

    static int search(int[] arr,int target){

        int start=0;
        int end =arr.length-1 ;

        while(start<=end){
           // int middle = (start+end)/2 
           
           // Here if (start +end) has very big value it may exceeds the int range in java therefore we simplify the code

           int middle=start +(end-start)/2 ;

           if(target<arr[middle]){
            end=middle-1;
           }
           else if(target>arr[middle]){
            start=middle+1;
           }
           else{
            return middle;
           } 
        }
        return arr[start];
       
    }
    
}
