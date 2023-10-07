public class Wrapper_classes {
    public static void main(String[] args) {
        int i=30;
        //Integer value = new Integer(i); boxing
        Integer value = i; // autoboxing
        System.out.println(value); 

        int k = value.intValue(); // unboxing
        int p = value; // autounboxing
        System.out.println(p);
        System.out.println(k);

    }
}


