class Conversion: 
      
    def __init__(self, capacity): 
        self.top = -1 
        self.capacity = capacity   
        self.array = [] 
        self.output = [] 
        self.precedence = {'+':1, '-':1, '*':2, '/':2, '^':3} 
      
    def isEmpty(self): 
        return True if self.top == -1 else False
      
    def peek(self): 
        return self.array[-1] 
    
    def pop(self): 
        if not self.isEmpty(): 
            self.top -= 1
            return self.array.pop() 
        else: 
            return "empty"
      
    def push(self, op): 
        self.top += 1
        self.array.append(op)  
  
    def isOperand(self, ch): 
        return ch.isalpha() 
  
  
    def notGreater(self, i): 
        try: 
            a = self.precedence[i] 
            b = self.precedence[self.peek()] 
            return True if a  <= b else False
        except KeyError:  
            return False
   
    def infixToPostfix(self, exp): 
          
        for i in exp: 
           
            if self.isOperand(i): 
                self.output.append(i) 
              
           
            elif i  == '(': 
                self.push(i) 
  
            elif i == ')': 
                while( (not self.isEmpty()) and self.peek() != '('): 
                    a = self.pop() 
                    self.output.append(a) 
                if (not self.isEmpty() and self.peek() != '('): 
                    return -1
                else: 
                    self.pop() 
  
            
            else: 
                while(not self.isEmpty() and self.notGreater(i)): 
                    self.output.append(self.pop()) 
                self.push(i) 
  
      
        while not self.isEmpty(): 
            self.output.append(self.pop()) 
  
        print ("".join(self.output) )
  
exp = "a+b*(c^d-e)^(f+g*h)-i"
obj = Conversion(len(exp)) 
obj.infixToPostfix(exp) 
