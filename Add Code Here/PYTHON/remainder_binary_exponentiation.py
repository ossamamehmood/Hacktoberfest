'''Hello everyone!! Below is python code to find the remainder when an exponents is divided by an integer,using binary exponentiation with remainderisation at each recursion(step).

Sometimes a^b becomes so large that it is not possible for us to first evaluate it and then find remainder when it is divided by any integer. So for large b we use binary exponentiation with remainderisation at each step to evaluate remainder without evaluating actual number.

we will use following property of remainder:
     (a*b)%c=((a%c)*(b*c))*c)''' 

import sys

sys.setrecursionlimit(10**7)

def binary_exp(base , index):             #binary exponentiation using recursion
	
	if(index==0):
		return 1
	res= binary_exp(base, index//2)
	
	if(index%2==1):
		return res*res*base
		
	else:
		return res*res

def binary_remainder(base , index , divider):        #finding remainder using binary exponentiation recursion 

	if(index==0):
		return 1
	res= binary_remainder(base, index//2, divider)
	
	if(index%2==1):
		return ((res%divider)*(res%divider)*base)%divider
		
	else:
		return ((res%divider)*(res%divider))%divider
		
		
if __name__=="__main__":
	
	base=int(input("enter the base number : "))
	
	index=int(input("enter the power number : "))
	
	mid= int(binary_exp(base , index))
	
	print(str(base) + "^" + str(index) + "=" + str(mid))
	
	divider=int(input("enter the divider number : "))
	
	answer=int(binary_remainder(base , index , divider))
	
	print("on dividing " + str(base) + "^" + str(index) + " = " + str(mid) + " with " + str(divider) + " we get remainder = " + str(answer))
		
