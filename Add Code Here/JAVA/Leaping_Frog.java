import java.util.Arrays;
import java.util.Random;

public class LeapingFrog {
    // leaping frog code, calculating the number of jumps needed for the frog to cross a pond.
    // pond has 20 stones, each with a random number between 1 and 5.
    // frog starts out on first stone and jumps as much as indicated on stone that it is on.
    public static void main(String[] args) {

        int[] stones = arrayBuilder();
        int total=0;
        int jump=0;

        for (int i=0; i< stones.length;){
            total += stones[i];
            jump++;
            i += stones[i];
            if (total > stones.length){
                break;
            }
        }
        System.out.println(Arrays.toString(stones));
        System.out.println(jump);
    }

    public static int[] arrayBuilder(){
        int[] array = new int[20];
        Random random = new Random();
        int min = 1, max = 5;
        for (int i=0; i<array.length; i++){
            array[i] = random.nextInt(max - min) + min;
        }
        return array;
    }
}
