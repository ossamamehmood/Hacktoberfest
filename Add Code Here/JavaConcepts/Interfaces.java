public class Interfaces {
    public static void main(String[] args) {
        Writer w1 = new Pen();
        Writer w2 = new Pencil();
        perform p1 = new perform();
        p1.dosomething(w1);
        p1.dosomething(w2);
    }
}

abstract class Writer{
    abstract public void write();
}

class Pen extends Writer{
    public void write(){
        System.out.println("In pen");
    }
}

class Pencil extends Writer{
    public void write(){
        System.out.println("In pencil");
    }
}

class perform{
    public void dosomething(Writer w){
        w.write();
    }
}
