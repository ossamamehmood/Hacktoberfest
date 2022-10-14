//made by ShizuKA
class priorityQueue {

    private int max;
    private int[] arr;
    private int n;

    public priorityQueue() {}
    public priorityQueue(int max) {
        this.max = max;
        arr = new int[max];
        this.n = 0;
    }

    public void insert (int val) {
        int i;
        if (n == 0) {
            arr[0] = val;
            n++;
            return;
        }
        for (i=n-1;i>=0;i--) {
            if (val > arr[i]) {
                arr[i+1] = arr[i];
            }
            else break;
        }
        arr[i+1] = val;
        n++;
    }
    void print(){
        for (int i=n-1;i>=0;i--) {
            System.out.print(arr[i] + " ");
        }
    }
}


public class Main {
    public static void main(String[] args) {
        var q = new priorityQueue(5);
        q.insert(1);
        q.insert(2);
        q.insert(6);
        q.insert(9);
        q.insert(3);
        q.print();
    }
}
