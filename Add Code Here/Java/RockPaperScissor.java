import java.util.Scanner;
import java.util.Random;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        System.out.println("Welcome to Rock, Paper, Scissors!");

        while (true) {
            System.out.print("Enter your choice (rock, paper, or scissors): ");
            String userChoice = scanner.nextLine().toLowerCase();

            if (userChoice.equals("rock") || userChoice.equals("paper") || userChoice.equals("scissors")) {
                int randomNumber = random.nextInt(3); // 0 for rock, 1 for paper, 2 for scissors
                String[] choices = {"rock", "paper", "scissors"};
                String computerChoice = choices[randomNumber];

                System.out.println("You chose " + userChoice);
                System.out.println("Computer chose " + computerChoice);

                String result = determineWinner(userChoice, computerChoice);
                System.out.println(result);

                System.out.print("Do you want to play again? (yes/no): ");
                String playAgain = scanner.nextLine().toLowerCase();

                if (!playAgain.equals("yes")) {
                    break;
                }
            } else {
                System.out.println("Invalid choice. Please choose rock, paper, or scissors.");
            }
        }

        System.out.println("Thanks for playing!");
        scanner.close();
    }

    public static String determineWinner(String userChoice, String computerChoice) {
        if (userChoice.equals(computerChoice)) {
            return "It's a tie!";
        } else if ((userChoice.equals("rock") && computerChoice.equals("scissors"))
                || (userChoice.equals("paper") && computerChoice.equals("rock"))
                || (userChoice.equals("scissors") && computerChoice.equals("paper"))) {
            return "You win!";
        } else {
            return "Computer wins!";
        }
    }
}
