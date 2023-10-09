public interface InterfacePriorityQueue {
    /**
     * Add an element to the queue
     * 
     * @param e element to be added
     */
    public void enqueue(int e);

    /**
     * Remove an element from the queue
     * 
     * @throws RuntimeException if the queue is empty
     */
    public void dequeue();

    /**
     * Get the element at the front of the queue
     * 
     * @return the element at the front of the queue
     * @throws RuntimeException if the queue is empty
     */
    public int front();

    /**
     * Check if the queue is empty
     * 
     * @return true if the queue is empty, false otherwise
     */
    public boolean isEmpty();

    /**
     * Check if the queue is full
     * 
     * @return true if the queue is full, false otherwise
     */
    public boolean isFull();
}
