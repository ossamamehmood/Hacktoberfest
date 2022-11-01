def fizzbuzz(num: int) -> list: 
  
     buzz_list = [] 
  
     for i in range(1, num): 
         if i % 5 == 0 and i % 3 == 0: 
             buzz_list.append("fizzbuzz") 
         elif i % 5 == 0: 
             buzz_list.append("buzz") 
         elif i % 3 == 0: 
             buzz_list.append("fizz") 
         else: 
             buzz_list.append(i) 
  
     return buzz_list
