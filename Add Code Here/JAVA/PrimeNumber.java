/*
    Code: prime number programme Using Java(Iterative Approach)
    Name: janith Herath
    Date of Modification: 06 oct 2022
*/
import java.util.Scanner;

/*
A prime number is a whole number greater than 1 whose only factors are 1 and itself. 
A factor is a whole number that can be divided evenly into another number. 
The first few prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23 and 29. 
Numbers that have more than two factors are called composite numbers
*/




public class PrimeNumber {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        //taking user input
        System.out.print("Enter number to find its prime : "); 
        int n = sc.nextInt();
    
        //calling the Findprime and out put the results
        if(Findprime(n)==true){
            System.out.println(n+" isn't a prime number");
         }else{
            System.out.println(n+" is a prime number");
         }
     
        sc.close();
    }

    // we can't find input number is prime by direct what we doing here is search they have other factors than 1 and input number. 
    public static boolean Findprime(int y){
        int temp=y/2;
        for(int i=2;i<temp;i++){
           if((y%i)==0){
                return true;
           }
        }
        return false;
    }
    
}


