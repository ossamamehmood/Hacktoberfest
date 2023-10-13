import java.util.Random;

public class RandomNumberGenerator {
    public static void main(String[] args) {
        // Create a Random object
        Random random = new Random();

        // Generate a random number between 1 and 100
        int randomNumber = random.nextInt(100) + 1;

        // Print the random number
        System.out.println("Random Number: " + randomNumber);
    }
}
