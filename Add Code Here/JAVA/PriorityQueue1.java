import java.util.PriorityQueue;

class PriorityQueue1 {

  public static void main(String[] args) {
    long[] arr = { 4, 3, 2, 6 };

    PriorityQueue<Long> pq = new PriorityQueue<>();
    for (long i : arr) pq.offer(i);
    for (long i : arr) System.out.println(pq.peek());
  }
}
