package arrays2;

public class SecondLargestInArray {
	
	public static int secondLargestElement(int[] arr) {
    	//Your code goes here
        int l=-10000;
            int s=-10000;
        for(int i=0; i<arr.length; i++){
            if(arr[i]>l){
                int temp= l;
                l = arr[i];
                s = temp;
            }
            if(arr[i]>s && arr[i]!=l){
                s = arr[i];
            }
        }
        if(s!=-10000){
            return s;
        }
        return Integer.MIN_VALUE;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
