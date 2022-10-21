class Solution {
  public int maxNumberOfFamilies(int n, int[][] reservedSeats) {
    int numOfReservedSeats = reservedSeats.length;
    Map<Integer, HashSet<Integer>> map = new HashMap<>();
    for(int i = 0; i < numOfReservedSeats; i++) {
      if(!map.containsKey(reservedSeats[i][0])) {
        map.put(reservedSeats[i][0], new HashSet<>());
      }
      map.get(reservedSeats[i][0]).add(reservedSeats[i][1]);
    }
    int count = 2 * n - 2 * map.size();
    for(Integer i : map.keySet()) {
      boolean flag = false;
      Set<Integer> reserved = map.get(i);
      if(!reserved.contains(2) && !reserved.contains(3) && !reserved.contains(4) && !reserved.contains(5)) {
        count++;
        flag = true;
      }
      if(!reserved.contains(6) && !reserved.contains(7) && !reserved.contains(8) && !reserved.contains(9)) {
        count++;
        flag = true;
      }
      if(!flag && !reserved.contains(4) && !reserved.contains(5) && !reserved.contains(6) && !reserved.contains(7)) {
        count++;
      }
    }
    return count;
  }
}
