package hashing;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Hashing {
    static void frequencyOfElement() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        // Initialize HashMap
        HashMap<Character, Integer> map = new HashMap<>();
        // Put Element Into Hashmap
        for (int i = 0; i < s.length(); i++) {
//            It Will Check If The Element Is Present In HashMap Or Not
//            If The Element Is Not Present In HashMap Then It Will Add Element With
//            Default Value And If The Element Is Present In HashMap Then The Value Of That
//            Element Will Increase By 1
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }
        // Iterate HashMap
        System.out.println("Key     Value");
        for (Map.Entry<Character, Integer> entry: map.entrySet()) {
            System.out.println(entry.getKey() + "       " + entry.getValue());
        }
        // Condition To Find Element Of Highest Frequency
        char max = s.charAt(0);
        for (Map.Entry<Character, Integer> entry: map.entrySet()) {
            if (map.get(entry.getKey()) > map.get(max)) {
                max = entry.getKey();
            }
        }
        System.out.println("Character With Highest Frequency Is -> " + max);

        // Condition To Find Element Of Lowest Frequency
        char min = s.charAt(0);
        for (Map.Entry<Character, Integer> entry: map.entrySet()) {
            if (map.get(entry.getKey()) < map.get(min)) {
                min = entry.getKey();
            }
        }
        System.out.println("Character With Lowest Frequency Is -> " + min);

        // Condition To Find Element With N Frequency
        System.out.print("Enter N -> ");
        int N = scanner.nextInt();
        for (Map.Entry<Character, Integer> entry: map.entrySet()) {
            if (entry.getValue() == N) {
                System.out.println("Character With "+N+" Frequency Is -> " + entry.getKey());
            }
        }
    }

    public static void main(String[] args) {
        frequencyOfElement();
    }
}
