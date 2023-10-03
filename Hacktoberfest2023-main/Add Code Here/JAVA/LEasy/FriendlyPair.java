package LEasy;

public class FriendlyPair {

    public static void main(String[] args) {

        int num1 = 7, num2 = 28;

        int n1=getdivisors(num1);
        int n2=getdivisors(num2);
//        System.out.println(n1);
//        System.out.println(n2);
        if(num1/n1 == num2/n2){
            System.out.println("YES");
        }else{
            System.out.println("no");
        }





    }

    private static int getdivisors(int num1) {
        int sum=0; //1+2+3=6
        for (int i = 1; i <num1 ; i++) {
            if(num1%i==0){
                sum+=i;
            }
        }
        return sum;
    }

}
