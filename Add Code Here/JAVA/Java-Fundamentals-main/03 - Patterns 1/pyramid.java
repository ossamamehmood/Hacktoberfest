public class pyramid {
    public static void main(String[] args) {

        int i,j;
        int a=1;

        for(i=1;i<=5;i++){
            for(j=1;j<=i;j++){
                System.out.print("*");
            }
            System.out.print("\n");
        }

        System.out.println("\n");

        for(i=1;i<=5;i++){
            for(j=1;j<=i;j++){
                System.out.print(a+" ");
                a++;
            }
            System.out.print("\n");
        }
        
    }
}
