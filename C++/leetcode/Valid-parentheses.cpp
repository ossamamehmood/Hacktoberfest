stack<int>stack;
        stack.push(0);
        for(int i=0; i<s.size(); i++)
        {
            if (s[i]=='(')
                stack.push('(');
            else if (s[i]=='[')
                stack.push('[');
            else if (s[i]=='{')
                stack.push('{');
            else if (s[i]==')')
            {
                if(stack.top()=='(')
                    stack.pop();
                else
                {
                    stack.push(')');
                    break;
                }
            }
            else if (s[i]==']')
            {
                if(stack.top()=='[')
                    stack.pop();
                else
                {
                    stack.push(']');
                    break;
                }
            }
            else if (s[i]=='}')
            {
                if(stack.top()=='{')
                    stack.pop();
                else
                {
                    stack.push('}');
                    break;
                }
            }
        }
        if(stack.size()==1)
        {
            return true;
        }
        else
        {
            return false;
        }
