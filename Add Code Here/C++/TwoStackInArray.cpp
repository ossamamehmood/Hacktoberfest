/*Cpp program to implement two stack in a array*/
/*###############################

@author: Tapati Chakraborty
student: GCETTB

###################################*/

/* Two stack is implemented here by an array.
	One Stack start from the leftmost position of the array and yhe other Stack
	starts from the rightmost position of the array.
	The first element of stack1 pused at index = 0 and the first element of stack2
	pushed at index = n-1.
	This method utilizes all the space in the array.It doesn't cause an overflow
	if any space is available in the array. */

#include <iostream>
#include <stdlib.h>

using namespace std;

//Stack class with basic stack functionalitis
class twoStack
{
	int *arr;
	int size;
	int top1, top2;

	public:
		twoStack(int n)//constructor
		{
			size = n;
			arr = new int[n];
			top1 = -1;
			top2 = size;
		}
		void push1(int x);
		void push2(int x);
		int pop1();
		int pop2();
};

//twoStack's member method to push an element x to stack1
void twoStack::push1(int x)
{
	if(top1 == top2-1)
		cout << "Stack overflow!" << endl;
	else//There is atleast one empty space to push a new element
	{
		top1++;
		arr[top1] = x;
	}

}

//twoStack's member method to push an element x to stack2
void twoStack::push2(int x)
{
	if(top1 == top2-1)
		cout << "Stack overflow!" << endl;
	else//There is atleast one empty space to push a new element
	{
		top2--;
		arr[top2] = x;
	}

}

//twoStack's member method to remove an element x to stack1
int twoStack::pop1()
{
	int x;
	if(top1 == -1)
		cout << "Stack underflow!" << endl;
	else
	{
		x = arr[top1];
		top1--;
	}
	return x;

}

//twoStack's member method to remove an element x to stack2
int twoStack::pop2()
{
	int x;
	if(top2 == -1)
		cout << "Stack underflow!" << endl;
	else
	{
		x = arr[top2];
		top2++;
	}
	return x;

}

/*Driver program to test twoStack class*/
int main()
{
	twoStack ts(5);
	cout << "Stack1 and Stack2 has been created successfully" << endl;
	ts.push1(2);
	ts.push2(28);
	ts.push2(45);
	ts.push1(32);
	ts.push1(89);
	cout << "Popped element from Stack1: " << ts.pop1() << endl;
	ts.push2(62);
	cout << "Popped element from Stack2: " << ts.pop2() << endl;

	return 0;
}

/*####################################################

Output:

Stack1 and Stack2 has been created successfully
Popped element from Stack1: 89
Popped element from Stack2: 62

######################################################*/