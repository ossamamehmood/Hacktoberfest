    package LEasy;

    import java.util.HashMap;
    import java.util.Iterator;

    public class GetSingleElement {


        public  static void better(int[] arr){
            HashMap<Integer,Integer> map=new HashMap<>();
            for (int i = 0; i < arr.length; i++) {
                map.put(arr[i], map.getOrDefault(arr[i], 0) + 1); // Corrected line

            }
            System.out.println(map);

            Iterator<Integer> it = map.keySet().iterator(); // Create an iterator for keys

            while (it.hasNext()) {
                Integer key = it.next();
                Integer value = map.get(key);
//                System.out.println("Key: " + key + ", Value: " + value);

                if(value==1){
                    System.out.println(key);
                    break;
                }
            }
        }
        public static void main(String[] args) {
            int[] arr={1,1, 2,2, 3};

            optimal(arr);

        }

        private static void optimal(int[] arr) {

            int xor=0;
            for (int i = 0; i < arr.length; i++) {

                xor=arr[i]^xor;
                
            }
            System.out.println(xor);



        }

    }
