import numpy as np
def polynomial(c):
    digit=list(map(int,c))
    return digit
m_signal=('11100')
print('Message polynomial:')
print(np.poly1d(polynomial(m_signal)))
gen=("111010001")
print('Generator polynomial:')
print("\n",np.poly1d(polynomial(gen)))
l_gen = len(gen)
data = m_signal+ '0'*(l_gen-1)
print('Appended signal:')
print(np.poly1d(polynomial(data)))
def xor(a, b):
	result = []
	for i in range(1, len(b)):
		if a[i] == b[i]:
			result.append('0')
		else:
			result.append('1')
	return ''.join(result)
def binarydivision(divident, divisor):
	x= divident[0 : len(divisor)]
	for j in range(len(divisor),len(divident)):
		if x[0] == '1':
			x=xor(divisor,x)+divident[j]
		else: 
			x= xor('0'*j,x)+divident[j]
		j += 1
	if x[0]=='1':
		x=xor(divisor,x)
		
	else:
		x=xor('0'*j,x)
	return x
#tramsmitter side
remainder = binarydivision(data, gen)
print('Remainder:')
print(np.poly1d(polynomial(remainder)))
f_frame= m_signal +remainder
print('Transmitted Frame:')
print(np.poly1d(polynomial(f_frame)))
print("The transmited frame:",f_frame)
#receiver_end
bit=input("enter 0 or 1:")
def flip(bits,index=0,flip=''):
    return '%s%s%s'%(bits[:index],flip,bits[index+1:])
flip_bit=flip(f_frame,(len(f_frame)-1),bit)
print("The flipped frame:",flip_bit)
error=binarydivision(flip_bit,gen)
print('Remainder after flipped:')
print(np.poly1d(polynomial(error)))
ans=binarydivision(f_frame,gen)
if error==ans:
    print("SUCCESSFUL! NO ERROR DETECTED.")
else:
    print("ERROR DETECTED IN RECEIVER SIDE.")
