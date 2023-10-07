import java.util.Random;
import java.util.Scanner;

public class GuessTheNumber {
    public static void main(String[] args) {
        Random random = new Random();
        int secretNumber = random.nextInt(101);

        Scanner input = new Scanner(System.in);
        int attempts = 0;

        System.out.println("Welcome to the Guess the Number game!");
        System.out.println("I've selected a number between 0 and 100. Try to guess it.");

        while (true) {
            System.out.print("Make a guess: ");
            int userGuess = input.nextInt();
            attempts++;

            if (userGuess < secretNumber) {
                System.out.println("Hint: Increase your number.");
            } else if (userGuess > secretNumber) {
                System.out.println("Hint: Decrease your number.");
            } else {
                System.out.println("Congratulations! You guessed it right.");
                break;
            }

            System.out.println("Attempts: " + attempts);
            System.out.print("Do you want to continue (Y/N)? ");
            String choice = input.next();

            if (choice.equalsIgnoreCase("N")) {
                break;
            }
        }

        System.out.println("Thank you for playing!");
    }
}
