#import turtle package
import turtle
 
# Screen object
sc = turtle.Screen()
 
# Screen background color
sc.bgcolor('black')
 
# turtle object
pen = turtle.Turtle()
 
# turtle width
pen.width(4)
 
 
# function to draw a circle of
# rad radius and col color
def circle(col, rad, val):
   
    pen.color(col)
    pen.circle(rad)
    pen.up()
     
    # set position for space
    pen.setpos(0, val)
    pen.down()
 
 
# function to write text
# by setting positions
def text():
   
    pen.color('white')
    pen.up()
    pen.setpos(-100, 140)
    pen.down()
    pen.write("Concentric VIBGYOR", font = ("Verdana", 15))
    pen.up()
    pen.setpos(-82, -188)
    pen.down()
    pen.write("Using Turtle Graphics", font = ("Verdana", 12))
    pen.hideturtle()
 
 
# Driver code
 
if __name__ == "__main__" :
   
  # VIBGYOR color list
   col = ['violet', 'indigo', 'blue','green', 'yellow', 'orange', 'red']
   for i in range(7):
    circle(col[i], -20*(i+1), 20*(i+1))
text()
