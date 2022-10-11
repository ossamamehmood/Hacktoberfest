import java.util.*;
class Smith_Number
{//start of class
    public static int sod(int n)//to calculate sum of digits
    {
        int s=0;//initialize
        while(n>0)
        {
            int d=n%10;//digit extraction
            s=s+d;//sum of the digit
            n=n/10;//modification
        }
        return s;
    }

    public static boolean check(int n)
    {
        int cpy=n;// copy the number
        int i=2,s=0; // initialize
        while(i<=n)
        {
            if(n%i==0)//check the factorization
            {
                s=s+sod(i);
                n=n/i;//modification
            }
            else
                i++;
        }
        if(sod(cpy)==s)//checking
            return true;
        else
            return false;

    }

    public static void main(String a[])
    {//start of main()
        Scanner sc= new Scanner(System.in);
        System.out.print("Enter the range : ");
        int n=sc.nextInt();
        System.out.println("All the Smith Numbers from 1 to "+n+" : ");
        for(int i=1;i<=n;i++)
        {
            if(check(i)==true)//checking
                System.out.print(i+" ");
        }
        System.out.println();
    }//end of main()
}//end of class
