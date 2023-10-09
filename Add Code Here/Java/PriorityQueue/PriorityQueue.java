public class PriorityQueue implements InterfacePriorityQueue {
    private int[] queue;
    private int size;
    private int capacity;

    public PriorityQueue(int capacity) {
        this.capacity = capacity;
        this.queue = new int[capacity];
        this.size = 0;
    }

    public void enqueue(int e) {
        if (this.isFull()) {
            throw new RuntimeException("Queue is full");
        }

        if (this.isEmpty()) {
            this.queue[0] = e;
        } else {
            int i = this.size - 1;
            while (i >= 0 && this.queue[i] > e) {
                this.queue[i + 1] = this.queue[i];
                i--;
            }
            this.queue[i + 1] = e;
        }
        this.size++;
    }

    public void dequeue() {
        if (this.isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }

        for (int i = 0; i < this.size - 1; i++) {
            this.queue[i] = this.queue[i + 1];
        }
        this.size--;
    }

    public int front() {
        if (this.isEmpty()) {
            throw new RuntimeException("Queue is empty");
        }

        return this.queue[0];
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public boolean isFull() {
        return this.size == this.capacity;
    }
}
