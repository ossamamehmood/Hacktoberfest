import java.util.Random;
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        String[] choices = {"rock", "paper", "scissors"};

        while (true) {
            int computerChoice = random.nextInt(3); // 0 for rock, 1 for paper, 2 for scissors
            System.out.print("Enter your choice (rock, paper, scissors): ");
            String userChoice = scanner.nextLine().toLowerCase();

            if (!userChoice.equals("rock") && !userChoice.equals("paper") && !userChoice.equals("scissors")) {
                System.out.println("Invalid choice. Please enter rock, paper, or scissors.");
                continue;
            }

            System.out.println("Computer chose: " + choices[computerChoice]);
            System.out.println("You chose: " + userChoice);

            if (userChoice.equals(choices[computerChoice])) {
                System.out.println("It's a tie!");
            } else if ((userChoice.equals("rock") && choices[computerChoice].equals("scissors"))
                    || (userChoice.equals("paper") && choices[computerChoice].equals("rock"))
                    || (userChoice.equals("scissors") && choices[computerChoice].equals("paper"))) {
                System.out.println("You win!");
            } else {
                System.out.println("Computer wins!");
            }

            System.out.print("Do you want to play again? (yes/no): ");
            String playAgain = scanner.nextLine().toLowerCase();
            if (!playAgain.equals("yes")) {
                break;
            }
        }

        scanner.close();
    }
}
