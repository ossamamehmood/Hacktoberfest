#include <iostream>
#include "stack.cpp"
using namespace std;
 
bool bracketbalance(string exp)
{
	Stack<char> s;
	char x;
	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
		{
			s.push(exp[i]);
		}

		else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')')
		{
			if (s.isEmpty())
			{
				return false;
			}
		}

		if (exp[i] == ']')
		{
			x = s.stackTop();
			s.pop();
			if (x == '(' || x == '{')
				return false;
		}

		if (exp[i] == '}')
		{
			x = s.stackTop();
			s.pop();
			if (x == '(' || x == '[')
				return false;
		}

		if (exp[i] == ')')
		{

			x = s.stackTop();
			s.pop();
			if (x == '[' || x == '{')
				return false;
		}

	}
	return s.isEmpty();
}
int main()
{
	string expr = "{()}[]";

	// Function call
	if (bracketbalance(expr))
		cout << "Balanced ";
	else
		cout << "Not Balanced";
	return 0;
}