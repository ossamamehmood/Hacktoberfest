// Reverse an Array Using While, For, Do-While loops in Java
import java.util.Scanner;
public class ArrayReverse {

    static{
        System.out.println("Starting.......");
    }
    public static void main(String args[]) {
        int sizeArray;  
        Scanner sc=new Scanner(System.in);  
        System.out.print("Enter the size of array: ");  
        sizeArray=sc.nextInt();  
        sc.close();
        int[] array = new int[sizeArray];  
        System.out.println("Enter the elements of the array: ");  
        for(int i=0; i<sizeArray; i++)  
        {    
        array[i]=sc.nextInt();  
        }
        forReverse(array);
        whileReverse(array);
        doWhileReverse(array);
        
    }
    private static void forReverse(int[] array){
        System.out.println("\nReverse by for");
        for(int i=array.length-1;i>=0;i--){
            System.out.print(array[i]);
        }
        
        
    }
    private static void whileReverse(int[] array){
        System.out.println("\nReverse by while:");
        int i=array.length-1;
        while(i>=0){
            System.out.print(array[i]);
            i--;
        }
        
    }
    private static void doWhileReverse(int[] array){
        System.out.println("\nReverse by Do while:");
        int i=array.length-1;
        do{
            System.out.print(array[i]);
            i--;
        }
        while(i>=0);
        
    }
}