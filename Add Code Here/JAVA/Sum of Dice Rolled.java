import java.util.*;

//Program to Stimulate Sum of N Dice Rolled
public class Dice {
	public static void Dice(String args[])
	{
		System.out.print("Enter the number of dice: ");

		// Initializing the Scanner object to read input
		Scanner input = new Scanner(System.in);
		int numberOfDice = input.nextInt();

		// Initializing the Random object for
		// generating random numbers
		Random ranNum = new Random();

		System.out.print("Hey Geek! You rolled: ");
		int total = 0;
		int randomNumber = 0;

		for (int i = 0; i < numberOfDice; i++) {

			// Generating the random number and storing it
			// in the 'randomNumber' variable
			randomNumber = ranNum.nextInt(6) + 1;
			total = total + randomNumber;
			System.out.print(randomNumber);
			System.out.print(" ");
		}

		System.out.println("");
		System.out.println("Total: " + total);
		input.close();
	}
}
