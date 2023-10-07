/**
  Fascinating Number: 
  When a number (3 digits or more) is multiplied by 2 and 3, 
  and when both these products are concatenated with the original number, then 
  it results in all digits from 1 to 9 present exactly once. There could be any 
  number of zeros and are ignored. 
  Examples: Input: 192. 
*/

import java.util.Scanner;

public class FascinatingNumber {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.print("Enter a number: ");
    int number = scanner.nextInt();
    scanner.close();

    if (isFascinating(number)) {
      System.out.println(number + " is a fascinating number.");
    } else {
      System.out.println(number + " is not a fascinating number.");
    }
  }

  private static boolean isFascinating(int number) {
    String concatenatedResult = number + "" + (number * 2) + "" + (number * 3);
    if (concatenatedResult.length() != 9) {
      return false;
    }
    int[] digitCount = new int[10];
    for (int i = 0; i < concatenatedResult.length(); i++) {
      digitCount[Character.getNumericValue(concatenatedResult.charAt(i))]++;
    }
    for (int i = 1; i < digitCount.length; i++) {
      if (digitCount[i] != 1) {
        return false;
      }
    }
    return true;
  }
}
