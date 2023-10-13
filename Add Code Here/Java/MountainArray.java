public class MountainArray {
    public static boolean validMountainArray(int[] arr) {
        if (arr == null || arr.length < 3) {
            return false;
        }

        int peakIndex = 0;
        int n = arr.length;

        // Find the peak of the mountain
        while (peakIndex < n - 1 && arr[peakIndex] < arr[peakIndex + 1]) {
            peakIndex++;
        }

        // Check if peak is at the start or end
        if (peakIndex == 0 || peakIndex == n - 1) {
            return false;
        }

        // Check the decreasing part
        while (peakIndex < n - 1 && arr[peakIndex] > arr[peakIndex + 1]) {
            peakIndex++;
        }

        return peakIndex == n - 1;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 4, 3, 2};
        boolean isMountain = validMountainArray(arr);

        if (isMountain) {
            System.out.println("The array is a mountain array.");
        } else {
            System.out.println("The array is not a mountain array.");
        }
    }
}
