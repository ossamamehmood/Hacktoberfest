<?php

// Php program for
// Infix to postfix conversion
// Using custom stack

// Stack node
class StackNode
{
	// Stack data
	public $element;
	public $next;
	public	function __construct($element, $next)
	{
		$this->element = $element;
		$this->next = $next;
	}
}
// Define a custom stack
class MyStack
{
	public $top;
	public $size;
	public	function __construct()
	{
		$this->top = NULL;
		$this->size = 0;
	}
	// Add node at the top of stack
	public	function push($element)
	{
		$this->top = new StackNode($element, $this->top);
		$this->size++;
	}
	public	function isEmpty()
	{
		if ($this->size > 0 && $this->top != NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// Remove top element of stack
	public	function pop()
	{
		if ($this->size > 0 && $this->top != NULL)
		{
			$temp = $this->top;
			// Change top element of stack
			$this->top = $temp->next;
			$this->size--;
		}
	}
	// Return top element of stack
	public	function peek()
	{
		if ($this->top == NULL)
		{
			return ' ';
		}
		return $this->top->element;
	}
}

class Conversion
{
	public	function precedence($text)
	{
		if ($text == '+' || $text == '-')
		{
			return 1;
		}
		else if ($text == '*' || $text == '/')
		{
			return 2;
		}
		else if ($text == '^')
		{
			return 3;
		}
		return -1;
	}
	public	function is_operator($text)
	{
		if ($text == '+' || $text == '-' || 
            $text == '*' || $text == '/' || $text == '^')
		{
			return true;
		}
		return false;
	}
	// Converting the given infix expression to postfix expression
	public	function infixToPostfix($infix)
	{
		$result = "";
		// Get the size
		$size = strlen($infix);
		// Create empty stack 
		$s = new MyStack();
		for ($i = 0; $i < $size; ++$i)
		{
			if (($infix[$i] >= '0' && $infix[$i] <= '9') || 
                ($infix[$i] >= 'a' && $infix[$i] <= 'z') || 
                ($infix[$i] >= 'A' && $infix[$i] <= 'Z'))
			{
				// When getting a operands
				$result = $result.strval($infix[$i]);
			}
			else
			{
				if ($s->isEmpty() || $infix[$i] == '(')
				{
					// Base case
					// When getting a open parenthesis
					// Or stack is empty
					$s->push($infix[$i]);
				}
				else if ($infix[$i] == ')')
				{
					// Need to remove stack element until the close bracket
					while ($s->isEmpty() == false && 
                           $s->peek() != '(')
					{
						// Get top element
						$result .= $s->peek();
						// Remove stack element
						$s->pop();
					}
					if ($s->peek() == '(')
					{
						// Remove stack element
						$s->pop();
					}
				}
				else
				{
					// Remove stack element until precedence of 
					// top is greater than current infix operator
					while ($s->isEmpty() == false && 
                           $this->precedence($infix[$i]) <= 
                           $this->precedence($s->peek()))
					{
						// Get top element
						$result .= $s->peek();
						// Remove stack element
						$s->pop();
					}
					// Add new operator
					$s->push($infix[$i]);
				}
			}
		}
		// Add remaining elements
		while ($s->isEmpty() == false)
		{
			$result .= $s->peek();
			$s->pop();
		}
		// Display result
		printf("%s\n", " Infix    : ".$infix);
		printf("%s\n", " Postfix  : ".$result);
	}
	public static
	function main($args)
	{
		$task = new Conversion();
		$infix = "((a/b+c))/(e*f)+(g^h-i)+k";
		$task->infixToPostfix($infix);
		$infix = "((a*b)^(c+d)/e)-f";
		$task->infixToPostfix($infix);
	}
}


Conversion::main(array());