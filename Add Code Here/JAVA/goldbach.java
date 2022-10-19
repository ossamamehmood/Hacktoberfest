import java.util.*;
class goldbach
{
    void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println(" Enter a Number");
        int n=sc.nextInt();
        int p=0,q=0,tot=0,i=0,j=0;
        System.out.println("Number can be represented as sum of two primes");
        int k=1,c=0;
        for(i=2;i<=n/2;i++)
        {
            k=1;
            c=0;
            p=fnprime(i,k,c);
            for(j=2;j<=n;j++)
            {
                k=1;
                c=0;
                q=fnprime(j,k,c);
                if(p==2 && q==2)
                {
                    tot=i+j;
                }
                if(tot==n)
                {
                    System.out.println(n+"="+i+"+"+j);
                }
                tot=0;
            }
        }
    }
    int fnprime(int n,int k,int c)
    {
        if(k<=n)
        {
            if(n%k==0)
            {
                c=c+1;
            }
            return(fnprime(n,k+1,c));
        }
        else
        return c;
    }
}
            
        
