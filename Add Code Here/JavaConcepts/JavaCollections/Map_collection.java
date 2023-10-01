package JavaCollections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Map_collection {
    public static void main(String[] args) {
        Map <String, String> m = new HashMap<>();
        m.put("Khushi", "Agarwal");
        m.put("Rajini", "Kumari");
        //System.out.println(m);

        Set <String> s = m.keySet();

        for (String str : s) {
            System.out.println(str+ " "+ m.get(str));
            
        }
    }
}
