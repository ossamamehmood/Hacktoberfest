class Solution {
   public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (wordList == null || wordList.size() == 0) return 0;
        //Hashset benefits: deduplication is also completed
        //start end
        HashSet<String> start = new HashSet<>();
        //end
        HashSet<String> end = new HashSet<>();
        //dictionary of all strings
        HashSet<String> dic = new HashSet<>(wordList);
        start.add(beginWord);
        end.add(endWord);
        if (!dic.contains(endWord)) return 0;
        //After going through the above series of judgments, when you get here, if there is a path, the minimum is 2, so start with 2
        return bfs(start, end, dic, 2);

    }

    public int bfs(HashSet<String> st, HashSet<String> ed, HashSet<String> dic, int l) {
        //When searching with two ends, if any segment is "broken", that is to say, there is no path that can be connected, it will return 0 directly.
        if (st.size() == 0) return 0;
        if (st.size() > ed.size()) {//Double-ended search, in order to optimize the time, always use less to find more. For example, if 1000 are inserted at the beginning, but only 3 at the end, it is definitely better to start from the less end.
            return bfs(ed, st, dic, l);
        }
        //Marking behavior of BFS, i.e. used not reused
        dic.removeAll(st);
        //Collect next level proximity points
        HashSet<String> next = new HashSet<>();
        for (String s : st) {
            char[] arr = s.toCharArray();
            for (int i = 0; i < arr.length; i++) {
                char tmp = arr[i];
                //Variety
                for (char c = 'a'; c <= 'z'; c++) {
                    if (tmp == c) continue;
                    arr[i] = c;
                    String nstr = new String(arr);
                    if (dic.contains(nstr)) {
                        if (ed.contains(nstr)) return l;
                        else next.add(nstr);
                    }
                }
                //Variety
                arr[i] = tmp;
            }
        }
        return bfs(next, ed, dic, l + 1);
    }
}
