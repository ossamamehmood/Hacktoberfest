# define a function for calculating
# the area of a shapes
def calculate_area(name):\

# converting all characters
# into lower cases
name = name.lower()

# check for the conditions
if name == "rectangle":
	l = int(input("Enter rectangle's length: "))
	b = int(input("Enter rectangle's breadth: "))
	
	# calculate area of rectangle
	rect_area = l * b
	print(f"The area of rectangle is
		{rect_area}.")

elif name == "square":
	s = int(input("Enter square's side length: "))
	
	# calculate area of square
	sqt_area = s * s
	print(f"The area of square is
		{sqt_area}.")

elif name == "triangle":
	h = int(input("Enter triangle's height length: "))
	b = int(input("Enter triangle's breadth length: "))
	
	# calculate area of triangle
	tri_area = 0.5 * b * h
	print(f"The area of triangle is
		{tri_area}.")

elif name == "circle":
	r = int(input("Enter circle's radius length: "))
	pi = 3.14
		
	# calculate area of circle
	circ_area = pi * r * r
	print(f"The area of circle is
		{circ_area}.")
		
elif name == 'parallelogram':
	b = int(input("Enter parallelogram's base length: "))
	h = int(input("Enter parallelogram's height length: "))
	
	# calculate area of parallelogram
	para_area = b * h
	print(f"The area of parallelogram is
		{para_area}.")
	
else:
	print("Sorry! This shape is not available")

# driver code
if __name__ == "__main__" :

print("Calculate Shape Area")
shape_name = input("Enter the name of shape whose area you want to find: ")

# function calling
calculate_area(shape_name)
