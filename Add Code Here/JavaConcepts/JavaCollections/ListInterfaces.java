package JavaCollections;

import java.util.ArrayList;
import java.util.List;

public class ListInterfaces {
    public static void main(String[] args) {
        List li = new ArrayList();
        li.add(78);
        li.add(45);
        li.add(1,89);
        System.out.println(li);

        for (int i = 0; i < li.size(); i++) {
            System.out.println(li.get(i));
        }

        for (Object obj : li) {
            System.out.println(obj);
        }
    }
}
