package LEasy;

public class LongestSubarray_SumofK {
    public static void main(String[] args) {


        int[] arr={1,2,3,1,1,1,1};
        int n=arr.length;
        int key=4;
        better(arr,key);


    }

    private static void better(int[] arr,int key) {

    int sum=0,max=0;
        for (int i = 0; i < arr.length; i++) {
            sum=0;
            for (int j = i; j < arr.length; j++) {
                sum+=arr[j];

                if(sum==key){

                    max=Math.max(max,j-i+1);

                }

            }

        }
        System.out.println(max);


    }

    public static void bruteforce(int[] arr){
        int key=4;
        int sum=0;
        int max=0;

        for (int i = 0; i < arr.length ;i++) {

            for (int j = i; j <arr.length ; j++) {

                for (int k = i; k <j ; k++) {

                    sum+=arr[k];
                    if(sum==key){
                        max=Math.max(max,j-i+1);
                    }
                }
            }
        }

        System.out.println(max);
    }
}
