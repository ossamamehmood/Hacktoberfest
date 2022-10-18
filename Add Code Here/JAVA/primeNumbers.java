public class PrimeNumber{
  public static void main(String args[]){
     System.out.println("Enter no. prime numbers");
     Scanner scan =new Scanner(System.in);
     int count=scan.nextInt();
     int n1=2,i;
     if (count==1){
     System.out.print(n1);
   }
 else (count>1){ 
     count=count+2;
     for (i=2;i<count;i++) {
        if (n1%i!=0){
           System.out.print(" "+n1);
           }
        }
     }
  } 
}
