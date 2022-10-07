import java.util.Scanner;
public class Bubble_sort {
    public static void B_sort(int[]A)
    {
        for(int i=0;i<A.length;i++)
        for(int j=1;j<A.length-i;j++)
        {
            if(A[j-1]>A[j])
            {
                int temp=A[j-1];
                A[j-1]=A[j];
                A[j]=temp;
            }

         }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter How many elements:");
        int n=sc.nextInt();
        int[]A=new int[n];
        for(int i=0;i<A.length;i++)
        A[i]=sc.nextInt();
        B_sort(A);
        for(int i=0;i<A.length;i++)
        System.out.print(A[i]+"\t");
    }
    
}
