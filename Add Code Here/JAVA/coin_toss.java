import java.util.*;
public class coin_toss{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        boolean c = true;
        while(c==true){
            System.out.println("Enter 1 to toss again");
            System.out.println("Enter 2 to Exit");
            int n = sc.nextInt();
            switch(n){
                case 1:
                    double d = Math.random()*100;
                    if(d>50)
                    System.out.println("IT'S .... HEAD");
                    else
                    System.out.println("IT'S .... TAIL");
                    break;
                case 2:
                    c=false;
            }
        }
        sc.close();
    }
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Term
