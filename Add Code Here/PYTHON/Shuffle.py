# Program to shuffle a deck of cards using Python.

# importing modules
import itertools
import random

# make a deck of cards
deck = list(itertools.product(range(1, 14), [
            'Spade', 'heart', 'Diamond', 'Club']))

# Shuffle the cards

random.shuffle(deck)

# draw five cards
print("You got: ")
for i in range(5):
    print(deck[i][0], "of", deck[i][1])
