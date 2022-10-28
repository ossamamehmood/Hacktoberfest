public class trycatch {
    public static void main(String[] args) {
        
        try{
            int a,b,c;
            a=12;
            b=0;
            int d[] = new int[3];
            c=a/b;
            System.out.println(c);

            d[4] = 45;
            System.out.println(d[4]);
        }
     //   catch(Exception e){
     //       System.out.println(e);
     //   }
          catch(ArithmeticException e){
              System.out.println(e);
          }
          
          catch(ArrayIndexOutOfBoundsException e){
              System.out.println(e);
          }
        
    }
}
