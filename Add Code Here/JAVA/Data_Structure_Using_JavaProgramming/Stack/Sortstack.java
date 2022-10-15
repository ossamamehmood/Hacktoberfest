// Sort a stack using another stack in java.

package Data_Structure_Using_JavaProgramming.Stack;

public class Sortstack {
    int size;
    int arr[];
    int top;
 
    Sortstack(int size) {
        this.size = size;
        this.arr = new int[size];
        this.top = -1;
    }
 
    public void push(int pushedElement) {
        if (!isFull()) {
            top++;
            arr[top] = pushedElement;
        } else {
            System.out.println("Stack is full !");
        }
    }
 
    public int pop() {
        if (!isEmpty()) {
            int returnedTop = top;
            top--;
            return arr[returnedTop];
 
        } else {
            System.out.println("Stack is empty !");
            return -1;
        }
    }
 
    public int peek() {
        return arr[top];
    }
 
    public boolean isEmpty() {
        return (top == -1);
    }
 
    public boolean isFull() {
        return (size - 1 == top);
    }
 
    public static void main(String[] args) {
        Sortstack Sortstack = new Sortstack(10);
        System.out.println("=================");
        Sortstack.push(10);
        Sortstack.push(30);
        Sortstack.push(50);
        Sortstack.push(40);
        Sortstack.printStack(Sortstack);
        Sortstack sortedStack=sortStack(Sortstack);
        System.out.println("=================");
        System.out.println("After Sorting :");
        System.out.println("=================");
        sortedStack.printStack(sortedStack);
 
    }
 
    // Sort a stack using another stack
    public static Sortstack sortStack(Sortstack stack)
    {
        Sortstack tempStack = new Sortstack(10);
        while(!stack.isEmpty())
        {
            int currentData=stack.pop();
            while(!tempStack.isEmpty() && tempStack.peek() > currentData) {
                stack.push(tempStack.pop());
            }
            tempStack.push(currentData);
        }
        return tempStack;
    }
 
    public  void printStack(Sortstack stack)
    {
        if(top>=0)
        {
            System.out.println("Elements of stacks are:");
            for (int i = 0; i <= top; i++) {
                System.out.println(arr[i]);
            }
        }
 
    }
}
 
