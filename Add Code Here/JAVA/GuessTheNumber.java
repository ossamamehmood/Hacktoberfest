import java.util.Scanner;
import java.util.Random;

public class GuessTheNumber {

    public static void main(String [] args) {

        Random obj=new Random();
        Scanner input=new Scanner(System.in);
        
        int a=obj.nextInt(101);
        System.out.println("Generated Number= "+a);

        int attempts = 0;
        boolean right = false;

        System.out.println("Number Generated Successfully!!\n\nNow start Guessing the Number.");

        System.out.println("Are you Ready?? Enter Yes or No.");
        String b=input.next();

        if(b.equalsIgnoreCase("yes")) {

            for(int i=0;i<50;i++) {

                System.out.println("Make a Guess.");

                int x=input.nextInt();
                
                attempts++;
                
                if(a-x>0) {

                    System.out.println("Oops!! not a right guess. \nHint: Increase your Number.");

                }

                else if(a-x<0) {

                    System.out.println("Oops!! not a right guess. \nHint: Decrease your Number.");

                }
                
                else {

                    System.out.println("Congrats!! You Guessed it Right.");
                    
                    right = true;
                }
                
                System.out.println("Attempts: " + attempts);
                
                int correct = 0;
                
                if (right) {
                    correct++;
                    attempts--;
                }
                
                System.out.println("Unsuccessfull: " + attempts + "\nSuccessful: " + correct);
                
                if (right) {
                    break;
                }
                
            }

        }

    }

}
