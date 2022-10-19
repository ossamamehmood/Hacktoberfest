import time
def countdown(t):

while t:

mins, secs = divmod(t, 60)

timer = '{:02d}:{:02d}'.format(mins, secs)

print(timer, end="\r")

time.sleep(1)

t -= 1

print('Lift off!')

# Ask the user to enter the countdown period in seconds

t = input("Enter the time in seconds: ")

# function call

countdown(int(t))
