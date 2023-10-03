print("Welcome to MadLibs")
print('''Here you have to enter a bunch of adjectives, nouns, verbs, etc. without any context 
and they will be put into a paragraph with blanks in which they may or maynot make sense. 
This will lead to the paragraph being funny and hopefully you will enjoy it''')
print("Let's begin!!")
adj1=input("Enter an adjective: ")
nation=input("Enter a nationality: ")
person=input("Enter a person's name: ")
noun1=input("Enter a noun: ")
adj2=input("Enter another adjective: ")
noun2=input("Enter another noun: ")
adj3=input("Enter another adjective: ")
adj4=input("Enter another adjective: ")
nouns=input("Enter a plural noun: ")
noun3=input("Enter another noun: ")
number=input("Enter a number: ")
shape=input("Enter plural for a shape: ")
food1=input("Enter a food: ")
food2=input("Enter another food: ")
num2=input("Enter another number: ")
madlib=f'''Pizza was invented by a {adj1} {nation} chef named {person}. 
To make pizza, you need to take a lump of {noun1}, and make a thin round {adj2} {noun2}. 
Then you cover it with {adj3} sauce, {adj4} cheese, and fresh chopped {nouns}. 
Next you have to bake it in a very hot {noun3}.
When it is done, cut it into {number} {shape}.
Some kids like {food1} pizza the best, but my favourite is {food2} pizza.
If I could, I would eat pizza {num2} times a day! '''
print("Your paragraph is ready!!")
print(madlib)
print("Hope you found this game entertaining :)")


