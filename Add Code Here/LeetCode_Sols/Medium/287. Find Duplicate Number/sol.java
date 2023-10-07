public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int findDuplicate(int[] arr) {
            int slowPtr = arr[0];
            int fastPtr = arr[0];

            do {
                fastPtr = arr[arr[fastPtr]];
                slowPtr = arr[slowPtr];
            } while (fastPtr != slowPtr);

            fastPtr = arr[0];

            while (fastPtr != slowPtr) {
                fastPtr = arr[fastPtr];
                slowPtr = arr[slowPtr];
            }

            return fastPtr;
        }
    }
}
