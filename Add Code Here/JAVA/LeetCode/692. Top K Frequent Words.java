class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String str : words) map.put(str, map.getOrDefault(str,0)+1);
        
        PriorityQueue<String> temp = new PriorityQueue<>((a,b)->{
            if(map.get(a)==map.get(b)) return b.compareTo(a);
            
            return map.get(a) - map.get(b);
        });
        
        for(String str: map.keySet()){
            temp.add(str);
            if(temp.size() > k) temp.remove();
        }
        
        List<String> sol =new LinkedList<>();
        while(temp.size()!=0){
            sol.add(0, temp.remove());
        }
        
        return sol;
    }
        
}