public class Mutiple_Catch_blocks{
  public static void main(String[] args) {
    
    try{
        //int []arr = null;
        int i=90;
        int j=0;
        int k=i/j;
        System.out.println("Output is "+k);
    }
    catch(ArithmeticException | NullPointerException e){
      System.out.println("Error");
    }
    catch(Exception e){
      System.out.println("something went wrong..");
    }

    finally{
      System.out.println("Bye byee");
    }
  }
}