import java.util.Scanner;

class StopWords {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] sequency = sc.nextLine().split(" ");
        String[] stop = sc.nextLine().split(" ");

        System.out.println(stopWords(sequency, stop).trim());

    }

    public static String stopWords(String[] sequency, String[] stop) {
        String res = "";
        for (String word : sequency) {
            if(!myContains(stop, word)) {
                res += word + " ";
            }
        }
        return res;
    }

    public static boolean myContains(String[] arr, String key) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i].equals(key)) return true;
        }
        return false;
    }
}