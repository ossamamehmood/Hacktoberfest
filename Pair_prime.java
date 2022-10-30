import java.util.Scanner;

class PrimePair {
public static void main(String [] args){
int range;
Scanner obj= new Scanner(System.in);
System.out.println("Enter Range: ");
range=obj.nextInt();
if( range>1){
System.out.println("2,3");
for (int i=1;i<=range;i++)
{
if((i+2) < range){
if(isPrime(i) && isPrime(i+2)){
System.out.println(i+","+(i+2)+"   ");

}
}
}
}


}
public static boolean isPrime(int num){
int flag=-1;

if(num == 1)
   {
    flag = 0;
   }
   else
   {
return false;
}

}

}
