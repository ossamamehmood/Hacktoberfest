import java.util.Scanner;
class ConvertToBinary
{
public static void main(String[] args)
{
    Scanner dtpe = new Scanner(System.in);
    System.out.println("Enter a no.");
    int a = dtpe.nextInt();
int binary[] = new int[1000]; int c=0;
while(a>0)
{
int d= a%2;
binary[c] = d;
a=(int)a/2; c++;
}

for(int x=c-1; x>=0; x--)
System.out.print(binary[x] + " ");
}}
