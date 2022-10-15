package com.techvidvan.mergearrays;
import java.util.Arrays;
public class ManualMethod {
  public static void main(String[] args) {
    //declaring two character arrays
    int[] array1 = {
      1,
      2,
      3,
      4
    };
    int[] array2 = {
      5,
      6,
      7,
      8
    };

    //Calculating sum of length of two arrays
    int length = array1.length + array2.length;

    System.out.println("First Array is: ");
    for (int i = 0; i < array1.length; i++) {
      System.out.print(" " + array1[i]);
    }
    System.out.println(" ");

    System.out.println("Second Array is: ");
    for (int i = 0; i < array2.length; i++) {
      System.out.print(" " + array2[i]);
    }

    //Creating a resulting array of the calculated length
    int[] result = new int[length];
    int position = 0;

    //for each loop to add array1 elements to the resulting array
    for (int element: array1) {
      result[position] = element;
      position++;
    }

    //for each loop to add array2 elements to the resulting array
    for (int element: array2) {
      result[position] = element;
      position++;
    }

    System.out.println("\nThe resulting array after merging two arrays is: ");
    System.out.println(Arrays.toString(result));
  }
}
