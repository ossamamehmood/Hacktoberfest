# DAY 6

### Question 1:

Given a string s consisting of words and spaces, return the length of the 
last word in the string.

A word is a maximal substring consisting of non-space characters only.

### Thought process:

- Strip to remove white space from the start and end
- Split string at " " as ```str.split(" ")```
- Return the length of the last element of split string using ```len``` 
function

### Question 2:

You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. The digits are 
ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of 
digits.

### Thought process:

- Convert the list of number into a single number and add one to it
- Map the number into list again and return it
