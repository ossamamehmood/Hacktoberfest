//Stack implementation using Array in java 

package Data_Structure_Using_JavaProgramming.Stack;

public class Stackpro {
    int size;
    int arr[];
    int top;
 
    Stackpro(int size) {
        this.size = size;
        this.arr = new int[size];
        this.top = -1;
    }
 
    public void push(int element) {
        if (!isFull()) {
            top++;
            arr[top] = element;
            System.out.println("Pushed element:" + element);
        } else {
            System.out.println("Stack is full !");
        }
    }
 
    public int pop() {
        if (!isEmpty()) {
            int topElement = top;
            top--;
            System.out.println("Popped element :" + arr[topElement]);
            return arr[topElement];
 
        } else {
            System.out.println("Stack is empty !");
            return -1;
        }
    }
 
    public int peek() {
        if(!this.isEmpty())
            return arr[top];
        else
        {
            System.out.println("Stack is Empty");
            return -1;
        }
    }
 
    public boolean isEmpty() {
        return (top == -1);
    }
 
    public boolean isFull() {
        return (size - 1 == top);
    }
 
    public static void main(String[] args) {
        Stackpro Stackpro = new Stackpro(5);
        Stackpro.pop();
        System.out.println("=================");
        Stackpro.push(100);
        Stackpro.push(90);
        Stackpro.push(10);
        Stackpro.push(50);
        System.out.println("=================");
        Stackpro.pop();
        Stackpro.pop();
        Stackpro.pop();
        System.out.println("=================");
    }
}
