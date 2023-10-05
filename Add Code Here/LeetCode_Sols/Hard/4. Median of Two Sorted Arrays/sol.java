public class sol{
    public static void main(String[] args) {
        // call the fn here
    }
}
class Solution {
    public double findMedianSortedArrays(int[] m, int[] n) {
        int[] merged = new int[m.length + n.length];
        int i = 0, j = 0, k = 0;

        while (i < m.length && j < n.length) {
            if (m[i] <= n[j]) {
                merged[k++] = m[i++];
            } else {
                merged[k++] = n[j++];
            }
        }

        while (i < m.length) {
            merged[k++] = m[i++];
        }

        while (j < n.length) {
            merged[k++] = n[j++];
        }

        int mid = merged.length / 2;
        if (merged.length  % 2 == 0){
        int sum = merged[mid] + merged[mid - 1];
        return (double) sum / 2;
        }
        else{
            return merged[mid];
        }
        
        
       // return avg;

    }
}