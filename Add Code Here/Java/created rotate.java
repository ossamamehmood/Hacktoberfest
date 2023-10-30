import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int size;
        System.out.println("Enter the size of the array: ");
        size = sc.nextInt();
        int[] arr = new int[size];
        int[] temp = new int[size];
        System.out.println("Enter the elements of the array: ");
        for(int i = 0; i<size; i++){
            arr[i] = sc.nextInt();
            temp[i] = arr[i];
        }
        int k;
        System.out.println("Enter the number by which the elements need to be rotated: ");
        k = sc.nextInt();
        for(int i = 0; i<size; i++){
            arr[(i+k)%size] = temp[i];
        }
        System.out.println("Rotated elements: ");
        for(int i = 0; i<size; i++){
            System.out.println(arr[i]);
        }
    }
}
