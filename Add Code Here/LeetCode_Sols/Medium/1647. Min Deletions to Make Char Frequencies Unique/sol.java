import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    public class Solution {
        public int minDeletions(String s) {
            int[] freq = new int[26]; // Create an array to store character frequencies

            for (char c : s.toCharArray()) {
                freq[c - 'a']++; // Count the frequency of each character
            }

            Arrays.sort(freq); // Sort frequencies in ascending order

            int del = 0; // Initialize the deletion count

            for (int i = 24; i >= 0; i--) {
                if (freq[i] == 0) {
                    break; // No more characters with this frequency
                }

                if (freq[i] >= freq[i + 1]) {
                    int prev = freq[i];
                    freq[i] = Math.max(0, freq[i + 1] - 1);
                    del += prev - freq[i]; // Update the deletion count
                }
            }

            return del; // Return the minimum deletions required
        }
    }
}
