public class Try_Catch_Finally{
    public static void main(String[] args) {    
    
        try{
            int i=90;
            int j=70;
            int k = i/j;
            System.out.println("The output is "+k);
        }
        catch(ArithmeticException e){
            System.out.println("Error");
        }
        finally{
            System.out.println("Bye");
        }
        
    
    }
}
