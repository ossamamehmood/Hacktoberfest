import java.util.Scanner;
public class TaylorSeriesRecursion {


    int pow(int m,int n)
    {
        if(n != 0)
            return m * pow(m,n-1);
        else 
            return 1;
    }

    int fact(int n)
    {
        if(n>0)
            return n * fact(n-1);
        else
            return 1;
    }

    int fun(int x ,int n)
    {
        if(n == 1)
            return 1;
        else 
            return  fun(x,n-1) + pow(x,n)/fact(n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        sc.close();
        TaylorSeriesRecursion t = new TaylorSeriesRecursion();
        System.out.println(t.fun(x,n));
    }
}