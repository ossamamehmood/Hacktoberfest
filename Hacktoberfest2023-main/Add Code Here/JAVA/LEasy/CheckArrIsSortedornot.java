package LEasy;

public class CheckArrIsSortedornot {
    public static void main(String[] args) {

        int[] arr={1,2,3,5,4,5};

        System.out.println(isSorted(arr));




    }

    private static boolean isSorted(int[] arr) {

        for (int i = 1; i <arr.length ; i++) {

            if(arr[i]>=arr[i-1]){

            }else{
                return false;
            }


        }
        return true;


    }
}
