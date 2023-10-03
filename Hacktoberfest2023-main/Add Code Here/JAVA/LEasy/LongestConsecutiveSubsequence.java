package LEasy;

public class LongestConsecutiveSubsequence {

    public static void bruteforce(int[] arr){
        int counter = 0;
        for (int i = 0; i < arr.length; i++) {
            int x = arr[i];
            counter = 1;
            while (search(arr, x + 1) == true) {
                x = x + 1;
                counter++;
            }
        }
//        System.out.println(longest);
        System.out.println(counter);
    }
    public static void main(String[] args) {
        int[] arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
//        bruteforce(arr);
        better(arr);





    }

    private static void better(int[] arr) {

        int longest=1;


    }

    private static boolean search(int[] arr, int i) {
        for (int j = 0; j < arr.length; j++) {
            if(arr[j]==i){
                return true;
            }
        }
        return false;
    }
}
