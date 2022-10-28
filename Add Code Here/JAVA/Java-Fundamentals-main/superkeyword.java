class animal{
    void method(){
        System.out.println("I am animal.");
    }
}

class dog extends animal{
    void method(){
        System.out.println("I am dog.");
    }

    void text(){
        method();
        super.method();
    }
}

public class superkeyword {
    public static void main(String[] args) {
        dog obj = new dog();
        obj.text();
    }
}
