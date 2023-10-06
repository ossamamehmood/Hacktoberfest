package DynamicPrograming;

import java.util.HashMap;

public class tribonacci {
    public static void main(String[] args) {
        HashMap<Integer,Integer> map=new HashMap<>();

        System.out.println(Trifibo(5,map));

    }
    public static int Trifibo(int n, HashMap<Integer,Integer>map)
    {
        if (n<=1)
        {
            return n;
        }
        if (n==2)
        {
            return 1;
        }
        if (map.containsKey(n))
        {
            return map.get(n);
        }
        int res=Trifibo(n-1,map)+Trifibo(n-2,map)+Trifibo(n-3,map);
        map.put(n,res);
        return res;
    }
}
