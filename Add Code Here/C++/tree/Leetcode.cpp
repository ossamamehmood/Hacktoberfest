/*
232. Implement Queue using Stacks
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

*/


class MyQueue {
public:
    stack <int> stack1;
    stack <int> stack2;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(stack2.size()==0){
            while(stack1.size()){
                int i=stack1.top();
                stack2.push(i);
                stack1.pop();
            }
        
        }
        int j=stack2.top();
        stack2.pop();
        return j;
        
    }
    
    /** Get the front element. */
    int peek() {
        if(stack2.size()==0){
            while(stack1.size()){
                int i=stack1.top();
                stack2.push(i);
                stack1.pop();
            }
        
        }
        int j=stack2.top();
        return j;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return !(stack1.size() || stack2.size());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */