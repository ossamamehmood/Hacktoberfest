import java.util.Scanner;

public class Main 
{
    public void Binary(int num)
    {
        if (num==0)
        {
            System.out.print("0");
            return;
        }
        
         int binary[] = new int[40];
         int index = 0;
        
         while(num > 0)
         {
           binary[index++] = num%2;
           num = num/2;
         }
        
         for(int i = index-1;i >= 0;i--)
         {
           System.out.print(binary[i]);
         }
        
      }

      public static void main(String a[]){
          
          Scanner sc=new Scanner(System.in);
          Main obj = new Main();
          int n=sc.nextInt();
          obj.Binary(n);
  }
}