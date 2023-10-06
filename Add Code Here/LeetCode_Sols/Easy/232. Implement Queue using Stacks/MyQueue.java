//Solution 1
class MyQueue {
    Stack<Integer> queue = new Stack<Integer>();

    public MyQueue() {
        
    }
    
    public void push(int x) {
        Stack<Integer> stack = new Stack<Integer>();
        while(!queue.empty())
            stack.push(queue.pop());
        stack.push(x);
        while(!stack.empty())
            queue.push(stack.pop());
    }
    
    public int pop() {
        return queue.pop();
    }
    
    public int peek() {
        return queue.peek();
    }
    
    public boolean empty() {
        return queue.empty();
    }
}


//Solution 2

/**
    1,2,3,4

    S1: []
    S2: [4]
 */

class MyQueue {
    Stack<Integer> pushS = new Stack<>();
    Stack<Integer> popS = new Stack<>();
    //** Initialize your data structure here */
    public MyQueue() {
        
    }
    
    /** Push element x to the back of queue */
    public void push(int x) {
        pushS.push(x);
    }
    private void convertPushSToPopS()
    {
        int size = pushS.size();
        for(int i = 0; i < size; i++)
        {
            Integer top = pushS.pop();
            popS.push(top);
        }
    }
    
    public int pop() {
        if(popS.isEmpty())
        {
            convertPushSToPopS();
        }
        return popS.pop();
    }
    
    /**Get the front element */
    public int peek() {
        if(popS.isEmpty())
        {
            convertPushSToPopS();
        }
        return popS.peek();
    }
    
    /**returns whether the queue is empty */
    public boolean empty() {
        return pushS.isEmpty() && popS.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */