 package stacks;

public class StackX {
	private int maxSize;
	private char[] stackArray;
	private int top;
	
	public StackX (int s) {
		maxSize = s;
		stackArray = new char[maxSize];
		top = -1;
	}
	public void push (char j) {
		if (top == (maxSize-1))
			System.out.println("Stack is Full");
		else
		{
			stackArray[++top]=j;
		}
	}
	public char pop()
	{
		return stackArray[top--];
	}
	public char peek()
	{
		return stackArray[top];
	}
	public boolean isEmpty()
	{
		if(top == -1)
			return true;
		else
			return false;
	}
	public boolean isFull()
	{
		if(top == maxSize-1)
			return true;
		else
			return false;
	}
}

