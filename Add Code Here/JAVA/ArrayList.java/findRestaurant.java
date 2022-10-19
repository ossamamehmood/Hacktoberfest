class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        int count = 0;
        int minindex=1100;
        int minindexx =1100;
         ArrayList <String> arr = new ArrayList<>();
        for(int a=0;a<list1.length; a++){
            for(int b=0;b<list2.length;b++){
                if(list1[a].equals(list2[b])){
                    // System.out.println(a);
                    if( (a+b) <= minindex + minindexx ){
                        minindex =a;
                        minindexx = b;
                    }
                     
                }
            }
        }
          count = minindex+minindexx;
          // System.out.println(count);
       for(int c=0;c<list1.length; c++){
            for(int d=0;d<list2.length;d++){
                if(list1[c].equals(list2[d])){
                   if(c+d == count){
                       arr.add(list1[c]);
                   }
                     
                }
            }
        }
        System.out.println(minindex);
        // System.out.println(arr);
        String [] ar = new String[arr.size()];
        for(int n=0; n<arr.size(); n++){
            ar[n] = arr.get(n);
        }
        
        return ar;
        
    }
}
