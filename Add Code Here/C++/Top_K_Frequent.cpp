// Just Sorting
// The easiest way to think of this problem and easy to implement.
// Time complexity: O(nlogn), naive sort is o(nlogn)
// Space complexity: O(n), for map and list

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }
        List<Map.Entry<String, Integer>> l = new LinkedList<>();
        for(Map.Entry<String, Integer> e:map.entrySet()){
            l.add(e);
        }
        Collections.sort(l, new MyComparator());//just use our Comparator to sort
        List<String> ans = new LinkedList<>();
        for(int i = 0;i<=k-1;i++){
            ans.add(l.get(i).getKey());
        }
        return ans;
    }
}
/*
// Implement our own comparator for this problem, I will also use this Comparator in other methods(A little different in minHeap method).
// We can also use anonymous Comparaotr or Lambda function.
// */
class MyComparator implements Comparator<Map.Entry<String, Integer>> {

    public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2){
        String word1 = e1.getKey();
        int freq1 = e1.getValue();
        String word2 = e2.getKey();
        int freq2 = e2.getValue();
        if(freq1!=freq2){
            return freq2-freq1;
        }
        else {
            return word1.compareTo(word2);
        }
    }
}
Max Heap
Maintain a max heap and add all the words in it. Pop top K words to get the results.
Time Complexity: O(nlogn + Klogn) = O(nlogn)
Space Complexity: O(n), for heap

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(new MyComparator());
        for(Map.Entry<String, Integer> e:map.entrySet()){
            pq.offer(e);
        }
        List<String> ans = new LinkedList<>();
        for(int i = 0;i<=k-1;i++){
            ans.add(pq.poll().getKey());
        }
        return ans;
    }
}
class MyComparator implements Comparator<Map.Entry<String, Integer>> {
    public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2){
        String word1 = e1.getKey();
        int freq1 = e1.getValue();
        String word2 = e2.getKey();
        int freq2 = e2.getValue();
        if(freq1!=freq2){
            return freq2-freq1;
        }
        else {
            return word1.compareTo(word2);
        }
    }
}
// Min Heap
// Instead of using a max heap, we only store Top K Freqency word we have met so far in our min heap.
// Time Complexity: O(nlogK), logK time for each word
// Space Complexity: O(K), since the largest number of words in our minheap is K

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }
        MyComparator comparator = new MyComparator();
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(comparator);
        for(Map.Entry<String, Integer> e:map.entrySet()){
            // If minHeap's size is smaller than K, we just add the entry
            if(pq.size()<k){
                pq.offer(e);
            }
            // Else, we compare the current entry with "min" entry in priority queue
            else {
                if(comparator.compare(e, pq.peek())>0){
                    pq.poll();
                    pq.offer(e);
                }
            }
        }
        List<String> ans = new LinkedList<>();
        for(int i = 0;i<=k-1;i++){
            ans.add(0, pq.poll().getKey());//the "smaller" entry poll out ealier 
        }
        return ans;
    }    
}

// The comparaotr is reversed as maxHeap
class MyComparator implements Comparator<Map.Entry<String, Integer>> {
    public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2){
        String word1 = e1.getKey();
        int freq1 = e1.getValue();
        String word2 = e2.getKey();
        int freq2 = e2.getValue();
        if(freq1!=freq2){
            return freq1-freq2;
        }
        else {
            return word2.compareTo(word1);
        }
    }
}
// Bucket sort + Trie
// This method is derived from 347. Top K Frequent Elements. At 347, we use bucket sort(LinkedList in each bucket) to find top K frequency integers and we can choose any integer if there is a tie of frequency . But in this question, the problem is that when there is a tie of frequency, we need to compare the lexicographic order. Thus using bucket sort(LinkedList in each bucket) is not good.
// The way to solve the tie problem is to use either trie or BST.
// Time Complexity: O(nm) = O(n), m time to construct trie for each word and m is a constant
// Space Complexity: O(nm) = O(n), m space for each bucket and m is a constant

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }

        Trie[] buckets = new Trie[words.length];
        for(Map.Entry<String, Integer> e:map.entrySet()){
            //for each word, add it into trie at its bucket
            String word = e.getKey();
            int freq = e.getValue();
            if(buckets[freq]==null){
                buckets[freq] = new Trie();
            }
            buckets[freq].addWord(word);
        }

        List<String> ans = new LinkedList<>();

        for(int i = buckets.length-1;i>=0;i--){
        //for trie in each bucket, get all the words with same frequency in lexicographic order. Compare with k and get the result
            if(buckets[i]!=null){
                List<String> l = new LinkedList<>();                               
                buckets[i].getWords(buckets[i].root, l);
                if(l.size()<k){
                    ans.addAll(l);
                    k = k - l.size(); 
                }
                else {
                   for(int j = 0;j<=k-1;j++){
                       ans.add(l.get(j));
                   } 
                    break;
                }
            }
        }
        return ans;
    }
}

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    String word = null;
}

class Trie {
    TrieNode root = new TrieNode();
    public void addWord(String word){
        TrieNode cur = root;
        for(char c:word.toCharArray()){
            if(cur.children[c-'a']==null){
                cur.children[c-'a'] = new TrieNode();
            }
            cur = cur.children[c-'a'];
        }
        cur.word = word;
    }

    public void getWords(TrieNode node, List<String> ans){
        //use DFS to get lexicograpic order of all the words with same frequency
        if(node==null){
            return;
        }
        if(node.word!=null){
            ans.add(node.word);
        }
        for(int i = 0;i<=25;i++){
            if(node.children[i]!=null){
                getWords(node.children[i], ans);
            }
        }

    }
}
// Bucket sort + BST
// The reason we use Trie is to break the tie of same word frequency. Thus we can easily use BST to replace Trie(In Java, we can use TreeMap or TreeSet)
// Time Complexity: O(n), not sure
// Space Complexity: O(n), not sure

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }
        TreeMap<String, Integer>[] buckets = new TreeMap[words.length];
        for(Map.Entry<String, Integer> e:map.entrySet()){
            String word = e.getKey();
            int freq = e.getValue();
            if(buckets[freq]==null){
                buckets[freq] = new TreeMap<>((a, b)->{
                    return a.compareTo(b);
                });
            }
            buckets[freq].put(word, freq);
        }

        List<String> ans = new LinkedList<>();
        for(int i = buckets.length-1;i>=0;i--){
            if(buckets[i]!=null){
                TreeMap<String, Integer> temp = buckets[i];
                if(temp.size()<k){
                    k = k - temp.size();
                    while(temp.size()>0){
                        ans.add(temp.pollFirstEntry().getKey());
                    }  
                }
                else {
                    while(k>0){
                        ans.add(temp.pollFirstEntry().getKey());
                        k--;
                    }
                    break;
                }
            }
        }     
        return ans;
    }
}
// Quick select
// If the question is to find Kth frequency word, quick select is a good solution and only cost O(n), for this question, after getting Top K frequency words by using quick select, we also need to do a sort to make sure they are in the right order.
// Time Complexity: O(n+KlogK), n time for quick select and KlogK time for sort
// Space Complexity: O(n)

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word:words){
            map.put(word, map.getOrDefault(word, 0)+1);
        }

        Map.Entry<String, Integer>[] entrys = new Map.Entry[map.size()];
        int index = 0;
        for(Map.Entry<String, Integer> e:map.entrySet()){
            entrys[index] = e;
            index++;
        }
        //do quick select
        int start = 0;
        int end = entrys.length-1;
        int mid = 0;
        while(start<=end){
            mid = partition(entrys, start, end);
            if(mid == k-1){
                break;
            }
            else if(mid<k-1){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        List<String> ans = new LinkedList<>();
        List<Map.Entry<String, Integer>> l = new LinkedList<>();
        for(int i = 0;i<=mid;i++){
            l.add(entrys[i]);
        }
        //still need to sort these K words, because we only know they are in result, but not in right order
        Collections.sort(l, new MyComparator());
        for(Map.Entry<String, Integer> e:l){
            ans.add(e.getKey());
        }
        return ans;
    }

    private int partition(Map.Entry<String, Integer>[] entrys, int start, int end){
        int pivot = start;
        int left = start + 1;
        int right = end;
        MyComparator myComparator = new MyComparator();
        while(true){
            while(left<=end){
                if(myComparator.compare(entrys[left], entrys[pivot])<=0){
                    left++;
                }
                else {
                    break;
                }
            }

            while(right>=start+1){
                if(myComparator.compare(entrys[right], entrys[pivot])>0){
                    right--;
                }
                else {
                    break;
                }
            }
            if(left>right){
                break;
            }
            swap(entrys, left, right);
        }
        swap(entrys, pivot, right);
        return right;
    }

    private void swap(Map.Entry<String, Integer>[] entrys, int i, int j){
        Map.Entry<String, Integer> a = entrys[i];
        entrys[i] = entrys[j];
        entrys[j] = a;
    }
}

class MyComparator implements Comparator<Map.Entry<String, Integer>> {

    public int compare(Map.Entry<String, Integer> e1, Map.Entry<String, Integer> e2){
        String word1 = e1.getKey();
        int freq1 = e1.getValue();
        String word2 = e2.getKey();
        int freq2 = e2.getValue();
        if(freq1!=freq2){
            return freq2-freq1;
        }
        else {
            return word1.compareTo(word2);
        }
    }
}

