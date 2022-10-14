package Data_Structure_Using_JavaProgramming;

// Sort An Array In Java:
// Method 1: Using java.util.Arrays

import java.util.Arrays;
public class SortArray {
  public static void main (String [] args) {
   int [] array = {45,12,85,32,89,39,69,44,42,1,6,8}; // Enter Your Input Here
   Arrays.sort(array);
   for (int i = 0; i < array.length; i++) {
   System.out.println(array[i]);
   }
  };
}

// java.util.Arrays is a library, included in Java programming language.
//  use of sort method which will save us time by not requiring us to manually 
//  create the loops for sorting but do it automatically. 



