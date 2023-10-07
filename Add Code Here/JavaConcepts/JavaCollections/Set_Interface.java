package JavaCollections;
// import java.util.HashSet;
import java.util.Set;
import java.util.TreeSet;

public class Set_Interface {
    public static void main(String[] args) {
        Set <Integer> i = new TreeSet<>();
        i.add(100);
        i.add(90);
        i.add(89);
        i.add(78);
        i.add(89);


        for (Integer inte : i) {
            System.out.println(inte);
        }
    }
}
