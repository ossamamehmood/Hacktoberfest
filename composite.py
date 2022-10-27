n=int(input('Enter the number '))
factor=0
for i in range(1,n):
  if n%i==0:
    factor=i
if factor>1:
  print ('The number is a composite number!')
elif n==1:
  print ('The number 1 is neither prime nor composite!')
else:
  print ('This is not a composite number!')
