package JavaCollections;

import java.util.ArrayList;
import java.util.Collection;

import java.util.Iterator;

public class ArrayList_Collection  {
    public static void main(String[] args) throws Exception {
        Collection values = new ArrayList();
        values.add(23);
        values.add(67);
        System.out.println(values);

        Iterator it = values.iterator();

        while(it.hasNext()){
            System.out.println(it.next());
        }
        
    }
}
