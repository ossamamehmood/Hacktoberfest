import java.util.Scanner;

class InsertSort{
    public static void main(String []args){
        int arr[] = new int[9];
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Array length :-");
        int size = sc.nextInt();
        for(int i=0; i<size; i++){
            arr[i] = sc.nextInt();
        }
        for(int i =0; i<size; i++){
            System.out.println(" " +arr[i]);
        }
    }
}