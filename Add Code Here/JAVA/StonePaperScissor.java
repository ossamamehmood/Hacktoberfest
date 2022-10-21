import java.util.Random;
import java.util.Scanner;

public class StonePaperScissor {
    public static void main(String[] args){
        String logo = """
          ______      ______       ______
         /  ___/     |  __  \\     /  ___/
        |  (__       | |__)  |   |  (__
         \\__  \\      |   ___/     \\__  \\
         ___)  | _   |  |    _    ___)  | _
        /_____/ |_|  |__|   |_|  /_____/ |_|
        """;
        System.out.println(logo);
        System.out.println("Welcome to Stone Paper Scissor!");
        System.out.println("\n Instructions: \n\t There will be 10 matches to be played");
        Game();
    }
    public static void Game(){
        int userscore = 0;
        int compscore = 0;
        String winner = "";
        int a = 1;
        while (a <= 10) {
            System.out.println("""
                    ________________________________________________________
                          """);
            System.out.println("\n \t\tMatch : "+a+"\n");
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter either 'Stone / Paper / Scissor' : ");
            String user = scan.next();
            Random random = new Random(100);
            int computer = random.nextInt();
            String comp = "";
            if (computer <= 33) {
                comp = "Stone";
            }
            if (computer > 33 && computer <= 66){
                comp = "Paper";
            }
            if (computer > 66 && computer <= 100){
                comp = "Scissor";
            }
            System.out.println("Computer's choice : "+comp);
            System.out.println("User's choice : "+ user);

            // Computer
            if (comp.equals("Stone") && user.equals("Scissor")|| user.equals("scissor")){
                compscore = compscore+1;
            }
            if (comp.equals("Paper") && user.equals("Stone")|| user.equals("stone")){
                compscore = compscore+1;
            }
            if (comp.equals("Scissor")&& user.equals("Paper") || user.equals("paper")){
                compscore = compscore+1;
            }

            // User
            if (user.equals("Stone")||user.equals("stone") && comp.equals("Scissor")){
                userscore = userscore+1;
            }
            if (user.equals("Paper")||user.equals("paper") && comp.equals("Stone")){
                userscore = userscore+1;
            }
            if (user.equals("Scissor")|| user.equals("scissor") && comp.equals("Papar")){
                userscore = userscore+1;
            }

            System.out.println("User Score : "+userscore);
            System.out.println("Computer : "+compscore);

            if (compscore<userscore){
                winner="User";
                System.out.println("\tLead : "+winner+"\n");
            }
            if (userscore<compscore){
                winner="Computer";
                System.out.println("\tLead : "+winner+"\n");
            }
            if (userscore==compscore){
                winner="Both";
                System.out.println("\tLead : "+winner+"\n");
            }
            if (a==10){
                System.out.println("\n\tGame won by "+winner);
            }
            a = a+1;
        }
    }
}
