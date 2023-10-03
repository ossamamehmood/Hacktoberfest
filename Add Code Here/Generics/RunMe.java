public class RunMe {
    public static void main(String[] args) {
        Printer<Integer> p = new Printer<>(234);
        p.display();
        Printer<String> p1 = new Printer<>("Aniket Shaw");
        p1.display();
        Printer<Double> p2 = new Printer<>(234.331);
        p2.display();
        Printer<Character> p3 = new Printer<>('V');
        p3.display();
    }
}
