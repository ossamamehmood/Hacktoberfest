package LEasy;

public class GCD {

    //highest common divider.. of both number

    public static void bruteforce(int n1,int n2){
        int gcd=1;
        for (int i = 1; i < Math.min(n1,n2); i++) {

            if(n1%i==0 && n2%i==0){
                gcd=i;
            }
        }
        System.out.println(gcd);
    }
    public static void better(int n1,int n2){

        int gcd=1;
        for (int i = Math.min(n1,n2); i >=1 ; i--) {

            if(n1%i==0 && n2%i==0){
                gcd=i;
                break;
            }

        }
        System.out.println(gcd);

    }
    public static void morebetter(int n1,int n2){

        while (n1>0 && n2>0){

            if(n1>n2){
                n1=n1%n2;
            }else{
                n2=n2%n1;
            }
        }
        if(n1==0){
            System.out.println(n2);
        }else {
            System.out.println(n1);
        }

    }

    public static void main(String[] args) {


        int n1=20,n2=30;
//        bruteforce(n1,n2);
//        better(n1,n2);
        morebetter(n1,n2);




    }
}
