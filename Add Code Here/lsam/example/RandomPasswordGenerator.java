package lsam.example;

import java.util.Random;
import java.util.Scanner;

public class RandomPasswordGenerator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the length of the password: ");
        int length = scanner.nextInt();
        scanner.nextLine(); 

        System.out.print("Include Uppercase Letters? (yes/no): ");
        boolean includeUppercase = scanner.nextLine().equalsIgnoreCase("yes");

        System.out.print("Include Lowercase Letters? (yes/no): ");
        boolean includeLowercase = scanner.nextLine().equalsIgnoreCase("yes");

        System.out.print("Include Numbers? (yes/no): ");
        boolean includeNumbers = scanner.nextLine().equalsIgnoreCase("yes");

        System.out.print("Include Special Characters? (yes/no): ");
        boolean includeSpecialChars = scanner.nextLine().equalsIgnoreCase("yes");

        String password = generateRandomPassword(length, includeUppercase, includeLowercase, includeNumbers, includeSpecialChars);

        System.out.println("Generated Password: " + password);

        scanner.close();
    }

    public static String generateRandomPassword(int length, boolean includeUppercase, boolean includeLowercase,
                                                boolean includeNumbers, boolean includeSpecialChars) {
        StringBuilder password = new StringBuilder();
        String uppercaseLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String lowercaseLetters = "abcdefghijklmnopqrstuvwxyz";
        String numbers = "0123456789";
        String specialChars = "!@#$%^&*()-_+=<>?";

        String characters = "";

        if (includeUppercase) characters += uppercaseLetters;
        if (includeLowercase) characters += lowercaseLetters;
        if (includeNumbers) characters += numbers;
        if (includeSpecialChars) characters += specialChars;

        Random random = new Random();
        for (int i = 0; i < length; i++) {
            int randomIndex = random.nextInt(characters.length());
            password.append(characters.charAt(randomIndex));
        }

        return password.toString();
    }
}
