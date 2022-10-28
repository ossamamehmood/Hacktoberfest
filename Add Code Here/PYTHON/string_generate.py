# Function Generate two output strings depending upon
# occurrence of character in input string

from collections import Counter

def generateStrings(input):
	
	# convert string into dictionary
	# having characters as keys and frequency as value
	freqDict = Counter(input)

	# separate out characters having frequency 1 and more than 1
	freq1 = [ key for (key,count) in freqDict.items() if count==1]
	freqMore1 = [ key for (key,count) in freqDict.items() if count>1]

	# sort lists and concatenate characters
	# with out space to print resultant strings
	freq1.sort()
	freqMore1.sort()

	# print output strings
	print ('String with characters occurring once:')
	print (''.join(freq1))
	print ('String with characters occurring multiple times:')
	print (''.join(freqMore1))

# Driver program
if __name__ == "__main__":
	input = "geeksforgeeks"
	generateStrings(input)
