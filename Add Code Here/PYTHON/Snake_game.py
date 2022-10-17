import turtle
import time
import random
delay = 0.1
score = 0
high_score = 0
wn = turtle.Screen()
wn.title("Snake Game")                    #setting up the window
wn.bgcolor("green")
wn.setup(width=600, height=600)
wn.tracer(0)
head = turtle.Turtle()                    #creating snake's head
head.shape("circle")
head.color("black")
head.penup()
head.goto(0, 0)
head.direction = "Stop"
food = turtle.Turtle()                    #creating food with random colors and shapes
food.shape(random.choice(['triangle', 'circle',"square"]))
food.color(random.choice(['red', 'yellow',"blue"]))
food.speed(0)
food.penup()
food.goto(0, 100)
pen = turtle.Turtle()
pen.speed(0)                              #setting up the scoreboard
pen.color("black")
pen.penup()
pen.hideturtle()
pen.goto(0, 250)
pen.write("Score : {}   High Score : {} ".format(score, high_score), align="center", font=("candara", 24, "bold"))
def group():
	if head.direction != "down":
		head.direction = "up"
def godown():
	if head.direction != "up":
		head.direction = "down"                       #defining turtle's movement 
def goleft():
	if head.direction != "right":
		head.direction = "left"
def goright():
	if head.direction != "left":
		head.direction = "right"
def move():
	if head.direction == "up":
		y = head.ycor()
		head.sety(y+20)
	if head.direction == "down":
		y = head.ycor()
		head.sety(y-20)
	if head.direction == "left":
		x = head.xcor()
		head.setx(x-20)
	if head.direction == "right":
		x = head.xcor()
		head.setx(x+20)	
def change_food():                         #changes color of the fruitglobal colors
	global food
	food.shape(random.choice(['triangle', 'circle',"square"]))
	food.color(random.choice(['red', 'yellow',"blue"]))
	food.goto(0,100)
def write_score():                         #updates the scoreboard
	global pen
	pen.clear()
	pen.write("Score : {}   High Score : {} ".format(score, high_score), align="center", font=("candara", 24, "bold"))
wn.listen()
wn.onkeypress(group, "w")
wn.onkeypress(godown, "s")
wn.onkeypress(goleft, "a")
wn.onkeypress(goright, "d")
segments = []
while True:                         #main code
	wn.update()
	if head.xcor() > 290 or head.xcor() < -290 or head.ycor() > 290 or head.ycor() < -290:            #if snake collides with boundary
		time.sleep(1)
		head.goto(0, 0)
		head.direction = "Stop"
		change_food()
		for segment in segments:
			segment.goto(1000, 1000)
		segments.clear()
		score = 0
		delay = 0.1
		write_score()
	if head.distance(food) < 20:                          #if head collides with food
		x = random.randint(-270, 250)
		y = random.randint(-270, 250)
		food.goto(x, y)
		new_segment = turtle.Turtle()
		new_segment.speed(0)
		new_segment.shape("circle")
		new_segment.color("brown") 
		new_segment.penup()
		segments.append(new_segment)
		delay -= 0.001
		score += 10
		if score > high_score:
			high_score = score
		write_score()
	for index in range(len(segments)-1, 0, -1):              #updating individual segments
		x = segments[index-1].xcor()
		y = segments[index-1].ycor()
		segments[index].goto(x, y)
	if len(segments) > 0:                            
		x = head.xcor()
		y = head.ycor()
		segments[0].goto(x, y)
	move()
	for segment in segments:                          #checking for collisions with body
		if segment.distance(head) < 20:
			time.sleep(1)
			head.goto(0, 0)
			head.direction = "stop"
			change_food()
			for segment in segments:
				segment.goto(1000, 1000)
			segment.clear()
			score = 0
			delay = 0.1
			write_score()
	time.sleep(delay)
wn.mainloop()
