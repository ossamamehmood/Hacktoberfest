import java.util.*;

class NGGame{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int mynumber = (int)(Math.random()*100); 
        
        int guess;
        int attempt=1; 
        int repeat=1;

        do{
            System.out.print("Guess the number : ");
           
            guess = sc.nextInt();

            if(guess == mynumber){
                System.out.println("Congrats!..You guess the right number.\n");
                System.out.print("You have guess the number in " + attempt);
                
                if(attempt==1)
                    System.out.println(" attempt..\n");
                else
                    System.out.println(" attempts..\n");

                attempt = 1;
                System.out.print("Do you want to play again(1/0) : ");
                
                repeat = sc.nextInt();
                mynumber = (int)(Math.random()*100);

                System.out.println();
            }
            
            else if(guess > mynumber && guess < (mynumber+5))
                System.out.println("Your number is fairly large.\n");
            
            else if(guess < mynumber && guess > (mynumber-5))
                System.out.println("Your number is fairly small.\n");

            else if(guess > mynumber)
                System.out.println("Your number is too large.\n");

            else
                System.out.println("Your number is too small.\n");

            attempt++;

        }while(repeat != 0);

        System.out.println("Thanks For Playing With Us!\n");
        sc.close();
    }
}
