import random
rand = random.randint(1,3)
print(rand)

def game(a,b):
	if (a==b):
		print('The game is tie')
	elif(a=='s'):
		if (b=='w'):
			print('Computer has won the game')
		elif(b=='g'):
			print('You have won the game')
	elif(a=='w'):
		if(b=='g'):
			print('Computer has wonthe game')
		elif(b=='s'):
			print('You won the game')
	elif(a=='g'):
		if(b=='s'):
			print('Computer has wonthe game')
		elif(b=='w'):
			print('You won the game')


if rand ==1:
	comp='s'
elif(rand==2):
	comp='w'
elif(rand == 3):
	comp = 'g'

you = input('Enter the choice among snake(s) or water(w) or gun(g)')
print(comp)
game(comp,you)