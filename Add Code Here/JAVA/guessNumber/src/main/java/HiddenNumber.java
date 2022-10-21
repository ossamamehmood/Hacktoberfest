
import java.util.Scanner;

public class HiddenNumber {

    public static void main(String[] args) {
        Scanner key = new Scanner(System.in);
        int option;
        int numInt = 5;
        int numMax = 10;
        int hiddenNum = 0;
        int guessNum = 0;
        int contTries = 0;
        boolean exit = false;

        do {
            System.out.println("Welcome to 'Guess the Hidden Number'.");
            //System.out.println("\n1. Configuration.");
            System.out.println("\n1. Play.");
            System.out.println("\n2. Exit.");
            System.out.println("Choose an option: ");
            option = key.nextInt();

            switch (option) {
                case 1:
                    System.out.println("Ready to play? Let's go!");
                    hiddenNum = (int) Math.floor(Math.random() * numMax + 1);
                    System.out.println("Guess the number: ");

                    guessNum = key.nextInt();

                    while ((hiddenNum != guessNum) && (contTries < numInt)) {
                        System.out.println("Guess the number: ");

                        if (guessNum < hiddenNum) {
                            System.out.println("The hidden number is GREATER");
                        } else {
                            System.out.println("The hidden number is SMALLER");
                        }
                        guessNum = key.nextInt();
                        contTries++;
                    }
                    if (guessNum == hiddenNum) {
                        System.out.println("You win!.");

                    } else {
                        System.out.println("You lost!.");
                    }

                    break;
                case 2:
                    System.out.println("End.");
                    exit = true;
                    break;
            }

        } while (((guessNum == hiddenNum) || (contTries > 5)) && !exit);
    }
}
