public class Inner_class {
    public static void main(String[] args) {
        Outer obj1 = new Outer();
        Outer.Inner obj2 = obj1.new Inner();
        obj2.show();
    }
}


class Outer{
    int i;
    public void show(){
        System.out.println("Hello I am an Outer Class");
    }

    class Inner{
        public void show(){
            System.out.println("Hello I am an Inner Class");
        }
    }
}