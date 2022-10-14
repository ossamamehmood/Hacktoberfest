Sort an Array in Java

  This content is useful for  learning and also interviews pur..........

  The sorting is a way to arrange elements of a list or array in a certain order. The order may be in ascending or descending order. The numerical and lexicographical (alphabetical) order is a widely used order.

  Sort Array in Ascending Order

  The ascending order arranges the elements in the lowest to highest order. It is also known as natural order or numerical order. We can perform sorting in the following ways:

>Using the sort() Method

>Without using the method

>Using the for Loop

>Using the User Defined Method

Using the sort() Method

In Java, Arrays is the class defined in the java.util package that provides sort() method to sort an array in ascending order. It uses Dual-Pivot Quicksort algorithm for sorting. Its complexity is O(n log(n)). It is a static method that parses an array as a parameter and does not return anything. We can invoke it directly using the class name. It accepts an array of type int, float, double, long, char, byte.

 

  FileName:- SortArrayExample1.java

  

  import java.util.Arrays;   

public class SortArrayExample1  

{   

public static void main(String[] args)   

{   

//defining an array of integer type   

int [] array = new int [] {90, 23, 5, 109, 12, 22, 67, 34};  

//invoking sort() method of the Arrays class  

Arrays.sort(array);   

System.out.println("Elements of array sorted in ascending order: ");  

//prints array using the for loop  

for (int i = 0; i < array.length; i++)   

{       

System.out.println(array[i]);   

}   

}  

}  

OutPuts:-

  Array elements in ascending order: 

5 

12 

22 

23 

34 

67 

90 

109

  File Name:-SortArrayExample2.java

  public class SortArrayExample2  

  {  

  public static void main(String[] args)   

  {  

//creating an instance of an array  

int[] arr = new int[] {78, 34, 1, 3, 90, 34, -1, -4, 6, 55, 20, -65};  

System.out.println("Array elements after sorting:");  

//sorting logic  

for (int i = 0; i < arr.length; i++)   

{  

for (int j = i + 1; j < arr.length; j++)   

{  

int tmp = 0;  

if (arr[i] > arr[j])   

{  

tmp = arr[i];  

arr[i] = arr[j];  

arr[j] = tmp;  

}  

}  

//prints the sorted element of the array  

System.out.println(arr[i]);  

}  

}  

} 
