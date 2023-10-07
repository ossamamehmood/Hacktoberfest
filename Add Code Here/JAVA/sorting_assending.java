import java.util.*;

class call{
    public void num()
    {
        System.out.println("enter array length");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int num[] = new int[a];
        int temp=0;
        for(int i=0;i<a;i++)
        {
            num[i]=sc.nextInt();
            
        }
    System.out.print("elements are");
        for(int i=0;i<num.length;i++)
    {
       System.out.println(" "+num[i] + " ");
    }
    
    for(int i=0;i<a;i++)
    {
       for(int j=i+1;j<num.length ;j++)
       {
        if(num[j]<num[i])
        {
            temp=num[i];
            num[i]=num[j];
            num[j]=temp;
        }
       }
    }
    System.out.println("sorted array: ");
    for(int i=0;i<a;i++)
    {
        System.out.print(num[i] + " ");
    } 

    sc.close();
}

}


public class sorting_assending {
    public static void main(String args[])
    {
       call obj = new call();
       obj.num();
    }
    
}
