package LEasy;

public class Patterns {

    public static void pat1(int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {


                System.out.print("*");

            }
            System.out.println();

        }
    }
    public static void pat2(int n){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }

    public static void pat3(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }
    public static void pat4(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(i);
            }
            System.out.println();
        }
    }
    public static void pat5(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n-i+1; j++) {
                System.out.print("*");
            }
            System.out.println();
        }
    }
    public static void pat6(int n){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n-i+1; j++) {
                System.out.print(j);
            }
            System.out.println();
        }
    }
    public static void pat7(int n){
        for (int i = 0; i < n; i++) {

            for (int j = 0; j <n-i-1 ; j++) {

                System.out.print(" ");
            }
            for (int j = 0; j < (2*i+1); j++) {
                System.out.print("*");
            }

            for (int j = 0; j < n-i-1 ; j++) {

                System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void pat8(int n){
        for (int i = n-1; i >=0; i--) {

            for (int j = 0; j <n-i-1 ; j++) {

                System.out.print(" ");
            }
            for (int j = 0; j < (2*i+1); j++) {
                System.out.print("*");
            }

            for (int j = 0; j < n-i-1 ; j++) {

                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void pat11(int n){
        for (int i = n-1; i >=0; i--) {

            for (int j = 0; j <n-i-1 ; j++) {

                System.out.print(" ");
            }
            for (int j = 0; j < (2*i+1); j++) {
                System.out.print("*");
            }

            for (int j = 0; j < n-i-1 ; j++) {

                System.out.print(" ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) {

//        int n=4;
//        int m=4;
//        pat1(n);
//        pat2(n);
//        pat3(n);
//        pat4(n);
//        pat5(n);
//        pat6(n);
//        pat7(n);
//        pat8(n);
//        pat11(n);


        char m='a';
        int count=0;
        while (m>'a'){
            count++;
            m--;
        }
        System.out.println(count);








    }
}


