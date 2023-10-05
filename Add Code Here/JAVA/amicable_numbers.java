import java.util.*;
class amicable
{
    static int factors(int n)
    {
        int s=0;
        for(int i=1;i<=n/2;i++)
        {
            if(n%i==0)
            {
                s=s+i;
            }
        }
        return s;
    }
    public static void main()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the numbers : ");
        int n1=sc.nextInt();
        int n2=sc.nextInt();
        amicable obj= new amicable();
        int f1=obj.factors(n1);
        int f2=obj.factors(n2);
        if(n1==f2 && n2==f1)
        {
            System.out.println("Amicable numbers");
        }
        else
        {
            System.out.println("Not Amicable numbers");
        }
    }
}