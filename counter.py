# import Counter from collections
from collections import Counter

# creating a raw data-set using keyword arguments
x = Counter (a = 2, x = 3, b = 3, z = 1, y = 5, c = 0, d = -3)

# printing out the elements
for i in x.elements():
	print( "% s : % s" % (i, x[i]), end ="\n")
