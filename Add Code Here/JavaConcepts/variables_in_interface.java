public class variables_in_interface {
    public static void main(String[] args) {
       int i=90;
       System.out.println("I am in the word! "+i);
    }
}

interface A{
    int a =90;
}

class B implements A{
    public void change(){
      //  a=89; // cannot be possible
    }
}
