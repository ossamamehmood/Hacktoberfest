//169. Majority Element

package com.morle;

import java.util.HashMap;
import java.util.Map;

public class MajorityElement {
    public static void main(String[] args) {
        System.out.println("asd");
    }
    public static int majorityElement(int[] nums) {
        Map<Integer, Integer> countMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int key = nums[i];
            if (countMap.containsKey(key))
            {
                int count = countMap.get(key);
                count++;
                countMap.put(key, count);
            }
            else
            {
                countMap.put(key, 1);
            }
        }
        for(Map.Entry<Integer,Integer> val : countMap.entrySet())
        {
            if (val.getValue() > nums.length/2)
            {
                return val.getKey();
            }
        }
        return 0;
    }
}
