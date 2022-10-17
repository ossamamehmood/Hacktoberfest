/*
----------- Infix to Postfix then Evaluation ----------
		    Using Stack Data Structure Method
	
	N.B. On evaluation function if you want to display only 
		 final output just put the result displayer from loop
		 
------- © April 2019. AI Programming, @freecodecs --------
*/

#include<iostream> 
#include<stack> 
#include<cstring>

using namespace std;

// Verify whether a character is numeric digit or not.
bool IsNumber(char C) { 
	if(C >= '0' && C <= '9')
		return true; 
	else 
		return false; 
	}

// Verify whether a character is operator symbol or not. 
bool IsOperator(char C) {
  if(C == '+' || C == '-' || C == '*' || C == '/' || C == '^' || C == '(' || C == ')')
  	return true;
  else
  	return false;
  }
  
// Get weight of an operator. 
int GetWeight(char op){  
	switch(op)
		{
		case '^': // square operator
			return 3;
			break;
		case '*':
		case '/':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
		default:
			return 0;
			break;
		}
	 }
	 
// Operation of precidence condition 
int HighPrecedence(char op1, char op2) { 
	if(GetWeight(op1) <= GetWeight(op2)) 
		return true;
	else
		return false; 
	}

// Postfix expression Converter
void expressionToPostfix(char expression[], char postfix[], int size) {  
	stack<char> S;
	
	int i=0, k=0; 
 
 	// insert & print into stack & postfix until expression length is empty 
	while(i<size)
		{
		if(expression[i] == '(')
			{	
			S.push(expression[i]);
			i++;
			continue;
			}
		if(expression[i] == ')')
			{
			while(!S.empty() && S.top() != '(')
				{
				postfix[k++]=' ';
				postfix[k++]=S.top();
				postfix[k++]=' ';
				S.pop();
				}
			if(!S.empty())
				S.pop();
			i++;
			continue;
			}
		if(!IsOperator(expression[i]))
			{
			postfix[k++] = expression[i];
			}
		else
			{
			if(S.empty())
				{
				S.push(expression[i]);
				postfix[k++]=' ';
				}
				
			else
				{
				while(!S.empty() && S.top() != '(' && HighPrecedence(expression[i], S.top()))
					{
					postfix[k++]=' ';
					postfix[k++] = S.top();
					S.pop();
					}
				S.push(expression[i]);
				postfix[k++]=' ';
				}
			}
		i++;	
		}
		
	//print out all stack
	while (!S.empty()) {
		postfix[k++]=' ';
		postfix[k++] = S.top();
		S.pop();
	}
	
	//terminate array last tail
	postfix[k] = 0;
	
   }

//Calculate two oprands with given operator
int calculate(char oper, int oprd1, int oprd2)
	{
	if(oper == '+') return oprd1 + oprd2;
	else if(oper == '-') return oprd1 - oprd2;
	else if(oper == '*') return oprd1 * oprd2;
	else if(oper == '/') return oprd1 / oprd2;
	else if(oper == '^') return oprd1 * oprd1;

	else cout<<"Unexpected Error \n";
	return 0; 
	}

// Evaluate postfix expression to final result if the expression is number 
void evaluatePostfix(string postfixexp, int sizepfx){
	stack<int> S;
	for(int i=0; i<sizepfx ;i++)
		{
			if(postfixexp[i] == ' ')
				continue;
			else if(!IsNumber(postfixexp[i]) && !IsOperator(postfixexp[i]))
				{
				cout<<"\nThe expression is not number! \n It can't be evaluated.";
				break;
				}
			else if(IsOperator(postfixexp[i]))
				{
				int oprd2 = S.top();
					S.pop();
				int oprd1 = S.top();
					S.pop();
				int result = calculate(postfixexp[i], oprd1, oprd2);
				S.push(result);
				}
			else if(IsNumber(postfixexp[i]))
				{
				int operand = 0;
				while(i<sizepfx && IsNumber(postfixexp[i]))
					{
					operand = (operand * 10) + (postfixexp[i] - '0');
					i++;
					}
				i--;
				S.push(operand);
				}
		cout<<"\nThe evaluated expression is : "<<S.top();
		}
	
		
}
	
int main() {
	// declare expression expression & its length
	char expression[30];
	
	cout<<"Postfix Converter & Evaluator"<<endl<<endl;
	
	cout<<"Enter Expression : ";
	cin>>expression;
	
	//declare size of expression & postfix variable
	int size = strlen(expression);
	char postfix[size];
	
	//call and print expression to postfix
	expressionToPostfix(expression, postfix, size);  
	cout<<"\nThe Postfix Expression is : "<<postfix<<"\n";
	
	//call evaluate postfix
	evaluatePostfix(postfix, strlen(postfix));
	
	return 0; 
		}
