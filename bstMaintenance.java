import java.io.*;
import java.util.*;

public class Solution {

  static int tick;
  static int[] l;
  static int[] r;
  static int[] size;

  static class NodeDfs {
    int v;
    int p;
    boolean start = true;
    public NodeDfs(int v, int p) {
      this.v = v;
      this.p = p;
    }
  } 
  
  static int dfs(int v) {
    if (v < 0) {
      return 0;
    }
    Deque<NodeDfs> deque = new LinkedList<>();
    deque.add(new NodeDfs(v, -1));
    while (!deque.isEmpty()) {
      NodeDfs node = deque.peekLast();
      if (node.start) {
        size[node.v] = 1;
        if (l[node.v] >= 0) {
          deque.add(new NodeDfs(l[node.v], node.v));
        }
        if (r[node.v] >= 0) {
          deque.add(new NodeDfs(r[node.v], node.v));
        }
        node.start = false;
      } else {
        if (node.p >= 0) {
          size[node.p] += size[node.v];
        }
        deque.removeLast();
      }
    }
    
    return size[v];
  }

  static void add(long fenwick[], int i, long v) {
    for (; i < fenwick.length; i |= i+1) {
      fenwick[i] += v;
    }
  }

  static long getSum(long fenwick[], int i) {
    long s = 0;
    for (; i > 0; i &= i-1) {
      s += fenwick[i-1];
    }
    return s;
  }

  static int[] pre;
  static int[] post;
  static int[] heavy;
  static int[] dep;
  static int[] p;

  static class NodeH {
    int d;
    int v;
    int chain;
    NodeH next = null;
    boolean start = true;
    
    public NodeH(int d, int v, int chain) {
      this.d = d;
      this.v = v;
      this.chain = chain;
    }
  } 
  
  static void heavyLight(int d, int v, int chain) {
    Deque<NodeH> deque = new LinkedList<>();
    deque.add(new NodeH(d, v, chain));
    while (!deque.isEmpty()) {
      NodeH node = deque.peekLast();
      if (node.start) {
        int[] c = new int[2];
        int nc = 0;
        pre[node.v] = tick++;
        heavy[node.v] = node.chain;
        dep[node.v] = node.d;
        if (~ l[node.v] != 0) {
          p[l[node.v]] = node.v;
          c[nc++] = l[node.v];
        }
        if (~ r[node.v] != 0) {
          p[r[node.v]] = node.v;
          c[nc++] = r[node.v];
        }
        if (nc == 2 && size[c[0]] < size[c[1]]) {
          int tmp = c[0];
          c[0] = c[1];
          c[1] = tmp;
        }
        if (nc > 0) {
          deque.add(new NodeH(node.d+1, c[0], node.chain));
          if (nc == 2) {
            node.next = new NodeH(node.d+1, c[1], c[1]);
          }
        }
        node.start = false;
      } else {
        if (node.next != null) {
          deque.add(node.next);
          node.next = null;
        } else {
          post[node.v] = tick;
          deque.removeLast();          
        }
      }
    }
  }

  static long[] fw_size;
  
  static long getSize(int i) {
    return getSum(fw_size, post[i]) - getSum(fw_size, pre[i]);
  }

  static void iota(Integer v[], int val) {
    for (int i = 0; i < v.length; i++) {
      v[i] = val++;
    }
  }
  
  static void cartesianTreeConstruction(int arr[], int n) {
    Integer[] b = new Integer[n];
    iota(b, 0);
    Arrays.sort(b, (i, j) -> { return arr[i] - arr[j]; });

    Deque<Integer> stack = new LinkedList<>();
    l = new int[n];
    r = new int[n];
    for (int i = 0; i < n+1; i++) {
      int j = i == n ? -1 : b[i], x = -1;
      for (; ! stack.isEmpty() && stack.peek() > j; stack.pop()) {
        int y = stack.peek();
        r[y] = x;
        x = y;
      }
      if (i < n) {
        stack.push(j);
        l[j] = x;
      }
    }

    size = new int[n];
    dfs(0);
    
    pre = new int[n];
    post = new int[n];
    heavy = new int[n];
    dep = new int[n];
    p = new int[n];
    
    heavyLight(0, 0, 0);
  }
  
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

    StringTokenizer st = new StringTokenizer(br.readLine());
    int n = Integer.parseInt(st.nextToken());

    int[] arr = new int[n];
    st = new StringTokenizer(br.readLine());
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      int item = Integer.parseInt(st.nextToken());
      arr[i] = item;
      if (item == i + 1) {
        cnt1++;
      }
      if (item == n - i) {
        cnt2++;
      }
    }

    if (cnt1 == n || cnt2 == n) {
      // special
        for (int i = 0; i < n; i++) {
          long result = (long)i * (i + 1) * (i + 2) / 6;
          bw.write(result + "\n");
        }
    } else {
      cartesianTreeConstruction(arr, n);
      
      long ans = 0;
      long sum = 0;
      long[] fw_s = new long[n];
      long[] fw_ds = new long[n];
      fw_size = new long[n];
      
      for (int i = 0; i < n; i++) {
        ans += sum;
        for (int v = i; v > 0; ) {
          int u = p[v];
          ans += (dep[i]-2*dep[u]) * (getSize(u)-getSize(v));
          long s = getSum(fw_s, pre[u]) - getSum(fw_s, pre[heavy[u]]);
          long ds = getSum(fw_ds, pre[u]) - getSum(fw_ds, pre[heavy[u]]);
          ans += dep[i]*s - 2*ds;
          if (heavy[v] != heavy[u]) {
            add(fw_s, pre[u], 1);
            add(fw_ds, pre[u], dep[u]);
          }
          v = heavy[u];
        }
        add(fw_size, pre[i], 1);
        add(fw_s, pre[i], 1);
        add(fw_ds, pre[i], dep[i]);
        sum += dep[i];
        bw.write(ans + "\n");
      }
    }
    
    bw.close();
    br.close();
  }
}
