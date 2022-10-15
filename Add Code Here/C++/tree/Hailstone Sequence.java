import java.util.*;
class Hailstone
{
    void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter a number");
        int N=sc.nextInt();
        System.out.println("Hailstone Sequence:");
        seq(N);
    }

    void seq(int N)
    {
        if(N<=0)
        {
            System.out.println("Invalid Input");
        }
        else if(N==1)
        {
            N=0;
        }
        else if(N%2==0)
        {
            System.out.println(N/2);
            N=N/2;
            seq(N);
        }
        else
        {
            System.out.println(3*N+1);
            N=3*N+1;
            seq(N);
        }
    }
}
 
