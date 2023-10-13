import java.io.*;
//import java.util.*;

public class MissingNumberInArray {
    public static void main(String[] args) throws IOException {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            String[] str = br.readLine().trim().split(" ");
            int[] array = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                array[i] = Integer.parseInt(str[i]);
            }
            Solution1 sln = new Solution1();
            System.out.println(sln.missingNumber(array, n));
        }
    }
}

class RupeshHacker {
    int missingNumber(int array[], int n) {
        int totalSum = (n * (n + 1)) / 2; // Calculate the sum of all integers from 1 to n
        int arraySum = 0; // Initialize the sum of the array elements

        for (int i = 0; i < array.length; i++) {
            arraySum += array[i]; // Calculate the sum of the array elements
        }

        return totalSum - arraySum; // Return the missing element
    }
}
