'''
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
'''

people = [3, 2, 2, 1]
limit = 3
people.sort()
low = 0
high = len(people) - 1

boat_count = 0


# using while loop
while low <= high:
    if low == high:
        boat_count += 1
        break
    if people[low] + people[high] <= limit:
        low += 1
    high -= 1
    boat_count += 1


# using for loop
'''for i in range(low,high+1):
    if low==high:
        boat_count +=1
        break
    if people[low]+people[high]<=limit:
        low +=1
    high -=1
    boat_count +=1'''

print(boat_count)