public class UserDefinedException {
    public static void main(String[] args) {
        int i=9;
        int j=10;

        try{
            int k = i/j;
            if(k==0){
                throw new Khushi_Exception("K value is not allowed");
            }
        }
        catch(Khushi_Exception e){
            System.out.println("Error! "+e.getMessage());
        }
    }
}


class Khushi_Exception extends Exception{
   public Khushi_Exception(String s){
      super(s);
    }
}