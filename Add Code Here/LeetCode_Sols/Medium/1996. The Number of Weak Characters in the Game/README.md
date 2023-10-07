# Problem #1996 ([The Number of Weak Characters in the Game](https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/) | Array, Greedy, Monotonic Stack, Sorting, Stack)

You are playing a game that contains multiple characters, and each of the characters has **two** main properties: **attack** and **defense**. You are given a 2D integer array `properties` where `properties[i] = [attackᵢ, defenseⱼ]` represents the properties of the `iᵗʰ` character in the game.

A character is said to be **weak** if any other character has **both** attack and defense levels **strictly greater** than this character's attack and defense levels. More formally, a character `i` is said to be **weak** if there exists another character `j` where `attackⱼ > attackᵢ` and `defenseⱼ > defenseᵢ`.

*Return the number of **weak** characters.*

## Example 1

### Input: 

    properties = [[5,5],[6,3],[3,6]]

### Output: 

    0

### Explanation: 

    No character has strictly greater attack and defense than the other.

## Example 2

### Input:

    properties = [[2,2],[3,3]]

### Output:

    1

### Explanation:

    The first character is weak because the second character has a strictly greater attack and defense.

## Example 3

### Input:

    properties = [[1,5],[10,4],[4,3]]

### Output:

    1

### Explanation:

    The third character is weak because the second character has a strictly greater attack and defense.

## Constraints
- `2 <= properties.length <= 105`
- `properties[i].length == 2`
- `1 <= attacki, defensei <= 105`

# Solutions

## Sorting

### Codes

- **Java**
```java
class Solution {
    public int numberOfWeakCharacters(int[][] properties) {
        int n = properties.length;
        int count = 0;
        int maxN = Integer.MIN_VALUE;
        Arrays.sort(properties, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        for(int i = 0; i < n; i++){
            if(properties[i][1] < maxN)
                count++;
            maxN = Math.max(maxN, properties[i][1]);
        }
        return count;
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/189258325-5cbea14a-3d25-48fc-838a-b4253c703082.png)
<br/>

- **C++**
```cpp
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b){
        if(a[0] == b[0])
            return a[1] < b[1];
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();
        int count = 0;
        int maxN = INT_MIN;
        sort(properties.begin(), properties.end(), compare);
        for(int i = 0; i < n; i++){
            if(properties[i][1] < maxN)
                count++;
            maxN = max(maxN, properties[i][1]);
        }
        return count;
    }
};
```
![image](https://user-images.githubusercontent.com/89616705/189256594-878bbd1c-cee3-4386-ae0d-7ab9a206d4a4.png)
<br/>

- **Python**
```python
class Solution(object):
    def numberOfWeakCharacters(self, properties):
        count = 0
        maxN = ~sys.maxint
        properties.sort(key=lambda x: (-x[0], x[1]))
        for i in range(len(properties)):
            if(properties[i][1] < maxN):
                count+=1
            maxN = max(maxN, properties[i][1])
        return count
```
![image](https://user-images.githubusercontent.com/89616705/189260393-e9f340fe-7958-4585-917b-cba87894c128.png)

### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(n)`
