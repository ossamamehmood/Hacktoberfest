import java.util.Arrays;
import java.util.Scanner;

public class CircularPrime {

    public static void main(String [] args){
        String str;
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print("Enter a number to be checked if it is Circular Prime or not : ");
            str = scanner.next();
        }while (Integer.parseInt(str) <= 0);
        boolean cPrime = false;
        int[] arr= permute(str);
        for (int i: arr) {
            if (i != 0) {
                if (isPrime(i)){
                    cPrime = true;
                }
                else {
                    cPrime = false;
                    break;
                }
            }
        }
        if (cPrime){
            System.out.println("Circular Prime!");
        }
        else {
            System.out.println("Not a Circular Prime!");
        }

    }

    public static int factorial(int num){
        if (num == 0){
            return 1;
        } else if (num == 1) {
            return 1;
        }
        else {
            return factorial(num-1)*num;
        }
    }


    public static int[] permute(String str){
        char[] temp = str.toCharArray();
        String temp2;
        int count = 0;
        int[] arr = new int[factorial(temp.length)];
        // Step 1. Sort the string
        Arrays.sort(temp);
        int index = 0;
        int lowest = 0;
        while(true){
            for(int i = 0; i < temp.length - 1; i++){
                if(temp[i] < temp[i+1]){
                    lowest = i;
                }
            }
            index = lowest;
            int j = findCeiling(temp, index);
            if(j == index) break;

            swap(temp, index, j);
            String a = String.valueOf(temp);
            char[] b = a.substring(index + 1).toCharArray();
            Arrays.sort(b);
            a = a.substring(0, index + 1) + String.valueOf(b);
            temp = a.toCharArray();
            temp2 = new String(temp);
            arr[count] =  Integer.parseInt(temp2);
            count++;
            }
        for (int i = 0; i < arr.length; i++){
            if (arr[i] == 0){
                arr[i] = Integer.parseInt(str);
                break;
            }
        }
        return arr;
        }

    private static void swap(char[] str, int i, int j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

        public static int findCeiling(char[] temp, int index){
            int k = index;
            char test = temp[index];
            while (k < temp.length - 1){
                if(temp[index] < temp[k + 1]){
                    index = k + 1;
                    break;
                }
                k++;
            }
            k = index;
            while (k < temp.length - 1){
                if((temp[index] > temp[k + 1]) && (temp[k + 1] > test)){
                    index = k + 1;
                }
                k++;
            }
            return index;
        }

    public static boolean isPrime(int number){
        boolean prime = false;
        if (number == 1){
            prime = false;
            return prime;
        }
        else if (number == 2){
            prime = true;
            return prime;
        }
        if ( number % 2 == 0){
            prime = false;
            return prime;
        }

        else {
            if (number == 3){
                prime = true;
                return prime;
            }
            else {
                for (int i =  3; i <= Math.ceil(Math.sqrt(number)); i+=2) {
                    if (number % i == 0){
                        prime = false;
                        break;
                    }
                    else {
                        prime = true;
                    }
                }
            }
        }
        return prime;
    }
}
