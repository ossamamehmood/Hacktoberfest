import java.util.Scanner;

public class BubbleSort {
  public static void main(String []args) {
    int i,j,temp,limit;
    Scanner sc = new Scanner(System.in);
 
    System.out.println("Enter the limit of the numbers:");
    limit = sc.nextInt();
 
    int array[] = new int[limit];
 
    System.out.println("Enter " + limit + " numbers: ");
    for (i = 0; i <limit; i++) 
      array[i] = sc.nextInt();
 
    for (i = 0; i < ( limit - 1 ); i++) {
      for (j = 0; j < limit - i - 1; j++) {
        if (array[j] > array[j+1]) //swap the elements if first one is greater than second
        {
           temp = array[j];
           array[j] = array[j+1];
           array[j+1] = temp;
        }
      }
    }
 
    System.out.println("******Sorted list******");
    for (i = 0; i < limit; i++) 
      System.out.println(array[i]);
  }
}
