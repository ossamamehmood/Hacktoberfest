
public class Object_classes {
    public static void main(String[] args) {
        Calc obj = new Calc();
        obj.a = 9;
        obj.b = 4;
        obj.perform();
    }
}

class Calc{
    int a;
    int b;
    int result;
    public void perform(){
        result = a+b;
        System.out.println(result);
    }
}