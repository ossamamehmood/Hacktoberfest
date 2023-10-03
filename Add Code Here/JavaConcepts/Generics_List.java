import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Generics_List {

    public static void main(String[] args) {
        List <Integer> li = new ArrayList<>();
        li.add(89);
        li.add(90);
        li.add(67);
    Collections.sort(li);
    Collections.reverse(li);
    Collections.shuffle(li);
    
        for (int i = 0; i < li.size(); i++) {
            System.out.println(li.get(i));
        }
    }
}
