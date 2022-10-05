# DAY 3

### Question 1:

- For example, 2 is written as II in Roman numeral, just two ones added 
together. 12 is written as XII, which is simply X + II. The number 27 is 
written as XXVII, which is XX + V + II.

- Roman numerals are usually written largest to smallest from left to 
right. 
However, the numeral for four is not IIII. Instead, the number four is 
written as IV. Because the one is before the five we subtract it making 
four. The same principle applies to the number nine, which is written as 
IX. There are six instances where subtraction is used:

- I can be placed before V (5) and X (10) to make 4 and 9. 
- X can be placed before L (50) and C (100) to make 40 and 90. 
- C can be placed before D (500) and M (1000) to make 400 and 900.
- Given a roman numeral, convert it to an integer.

### Thought process:

- Initialize a dict with all the roman numeral to decimal value, and set i 
as 0, and number as 0
- Start from the ith letter in the given roman numeral
	- If ith letter is less than (i+1)th letter:
		- ```number += (i+1)th letter - ith letter```
		- ```i += 2```
	- Else:
		- ```number += ith letter```
		- ```i += 1```
- return number as the converted decimal
