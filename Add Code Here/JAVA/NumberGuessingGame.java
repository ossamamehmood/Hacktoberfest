import java.util.Scanner;
class LoopQuestion17{
    public static void main(String[] args){
        int num, randNum;
        Scanner sc = new Scanner(System.in);
        randNum = (int)(Math.random()*100)+1;
        System.out.println(randNum);
        do{
            System.out.println("Enter the number: ");
            num = sc.nextInt();
            if (num> randNum){
                System.out.println("Too high, try again.");
            }
            else if(num<randNum){
                System.out.println("Too low, try again.");
            }
        }while(randNum != num);
        System.out.println("You guessed correct.");
        sc.close();
    }
}


