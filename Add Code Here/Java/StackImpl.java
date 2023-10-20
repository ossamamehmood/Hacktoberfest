package adt.stack;

public class StackImpl<T> implements Stack<T> {

	private T[] array;
	private int top;

	@SuppressWarnings("unchecked")
	public StackImpl(int size) {
		array = (T[]) new Object[size];
		top = -1;
	}

	@Override
	public T top() {
		return array[top];
	}

	@Override
	public boolean isEmpty() {
		if(top == -1) {
			return true;
		}
		return false;
	}

	@Override
	public boolean isFull() {
		if(top == array.length - 1) {
			return true;
		}
		return false;
	}

	@Override
	public void push(T element) throws StackOverflowException {
		if(!this.isFull()) {
			top++;
			array[top] = element;
		} else {
			throw new StackOverflowException();
		}
	}

	@Override
	public T pop() throws StackUnderflowException {
		if(top != -1) {
			T result = array[top];
			array[top] = null;
			top--;
			return result;
		} else {
			throw new StackUnderflowException();
		}
	}

}