/* codemastershrey  - https://github.com/codemastershrey  
   * find the Kth vlaue of array 
   * first the array is coverting in assending order after it diplay Kth value
*/
package com.company;

import java.util.Scanner;

public class dsa_array_que3 {
    public dsa_array_que3() {
    }

    public static void sort(int[] arr) {
        int i;
        for(i = 0; i < arr.length; ++i) {
            for(int j = i + 1; j < arr.length; ++j) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }

        for(i = 0; i < arr.length; ++i) {
            System.out.println(arr[i]);
        }

    }

    public static void main(String[] args) {
        int[] arr = new int[]{12, 4, 552, 560, 15, 47, 56};
        Scanner sc = new Scanner(System.in);
        sort(arr);
        System.out.print("Enter the kth value:");
        int n = sc.nextInt();
        System.out.println(arr[n - 1]);
    }
}
