# Problem #967 ([Numbers With Same Consecutive Differences](https://leetcode.com/problems/numbers-with-same-consecutive-differences/) | Backtracking, Breadth First Search)

Return all **non-negative** integers of length `n` such that the absolute difference between every two consecutive digits is `k`.

Note that `every` number in the answer `must not` have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in `any order`.

## Example 1

**Input:**

    n = 3, k = 7
<br/>

**Output:**

    [181,292,707,818,929]
<br/>

**Explanation:**

    Note that 070 is not a valid number, because it has leading zeroes.

## Example 2

**Input:**

    n = 2, k = 1
<br/>

**Output:**

    [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

## Constraints
- `2 <= n <= 9`
- `0 <= k <= 9`

# Solutions

### Basic Idea

The problem asks us to return a list of values(*integers*) in which each value is `n` digits and the **absolute difference** of each *two consecutive digits* is `k`. If `n` is `3`, then the values inside the `Queue` should be `3` digits.

**Sample** <br/>

    n = 3, k = 4
- This means that the numbers in the list should have a length of `3` and each *two consecutive digits* of a number has an **absolute difference** of `4`.
<br/>

```
Output: [151,159,262,373,404,484,515,595,626,737,840,848,951,959]
```
- Notice that some number has *consecutive digits* that has the same first digit but different second digit. Numbers such as:
    - `[151,159]`
    - `[404,484]`
    - `[840,848]`
    - `[951,959]`

- From these numbers we can conclude that two numbers with same first digit but different second digit can have the same *absolute difference*. Pairs such as(*where `k = 4`*):
    - `(5, 1)` and `(5, 9)`
    - `(4, 0)` and `(4, 8)`

- To find whether the first digit can be paired to `2` different second digits, it must satisfy these conditions:
    1. `k > 0` and `x - k >= 0`
    2. `x + k < 10`

```
NOTE: If it only satisfies one then it only has 1 pair.
```

***Example:***

    k = 4
    x = 5, this refers to the first digit
    
    1. k > 0 and x - k >= 0
        5 - 4 >= 0, true
        5 - 4 = 1, a pair
        
        | 5 - 1 | = 4, absolute difference = k
        
        Therefore, 1 is a pair of 5.

    2. x + k < 10
        5 + 4 < 10, true
        5 + 4 = 9, a pair
        
        | 5 - 9 | = 4, absolute difference = k
        
        Therefore, 9 is a pair of 5.

## Breadth First Search(Iterative)

The basic idea in an *iterative* **BFS** is to create a `List` where we will store the `n` digit numbers. We will use a ***for loop*** to loop from `1 - 9` which corresponds to the beginning of a number(`num`). For each iteration, we will create a `Queue` where we will first add(`i`) then process it inside a ***while loop***. Inside the ***while loop*** we will determine all possible combination of numbers until our number reaches `n` digits. When the number satisfies all condition and rule, add it to te `List`.

***Code Structure***
```cpp
vector<int> list;
min = pow(10, n - 1);
```
- Create a `list` where we will store our results. Our `min` is basically the *minimum value* of the values inside the `list`.
<br/>

```cpp
for(int i = 0; i < 10; i++){
    queue<int> q;
    q.push(i);
}
```
- We will iterate from `1 - 9`, these numbers are assigned to `i` which corresponds to the beginning of our number. We will then create a `Queue` where we will store the numbers, where for each number, we will determine the next digit where the ***absolute difference*** of the next digit and preceded digit is `k`. By default, the `Queue` first contains the first digit of our number which is `i`.

![image](https://user-images.githubusercontent.com/89616705/188290251-3d6b405e-d0de-49c0-aa61-0b0f8b19bd35.png)
***
<br/>

```cpp
for(int i = 0; i < 10; i++){
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int num = q.front();
        q.pop();
    }
}
```
- for each iteration, we will execute a **while loop** until our `Queue` is empty. Inside the ***while loop***, we will get the first value in our `Queue` and assign it to `num` and remove it from our `Queue`.

![image](https://user-images.githubusercontent.com/89616705/188290260-959a5fca-0fb7-4d1e-bcc0-b60f481e5823.png)
***
<br/>

```cpp
for(int i = 0; i < 10; i++){
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        if(num >= min){
            list.push_back(num);
            continue;
        }
        int x = num % 10;
        if (k > 0 && x - k >= 0)
            q.push(num * 10 + x - k)
        if (x + k < 10)
            q.push(num * 10 + x + k)
    }
```
- Once we pop a number from our `Queue` and assign to `num`, we will check whether that `num` is greater than or equal to our `min`, if it is, then add it to our `List` and `continue`. If not, then get the last digit of our `num` then find its pair/s of number in which their `absolute difference` is `k`. `x` should satisfy these conditions:
    1. `k > 0` and `x - k >= 0`
    2. `x + k < 10`

- If only one of the conditions is satisfied then `x` only has one pair.
- Add the resulting number to our `Queue` when that pair of `x` is added as a last digit of our number.
    
    `num = num * 10 + {pair}`, `pair` can either be `x + k = pair` or `x - k = pair` or both depending on the conditions satisfied by `x`.

- Once the new `num` is added to our `Queue`, our ***while loop*** still hold thus continue executing its statements for each values in the `Queue` until all values are greater than `min`, which will then satisfy the if condition where we will add the values to our list and ***empty*** our `Queue`. Once the `Queue` is empty, exit the ***while loop*** and increment `i` thus beginning another iteration for a number starting at `2`, repeat loop until `i = 9`.

![image](https://user-images.githubusercontent.com/89616705/188290842-0c0c870e-ecf7-40a7-8b29-971efff780a7.png)
***
<br/>

- `Queue` after getting the next digit of `1`.

![image](https://user-images.githubusercontent.com/89616705/188290778-c5e81856-64a3-4633-a099-ff05f95d5119.png)
***
<br/>

- `Queue` is popped, `num = 15`.

![image](https://user-images.githubusercontent.com/89616705/188290797-fc6b999a-440a-4c9d-82a0-0729cb2f4cef.png)
***
<br/>

- `num` is less than `min` thus find its next digit.
- There are two digits that can be paired with the last digit of `num`. Add the resulting numbers to the `Queue`.

![image](https://user-images.githubusercontent.com/89616705/188291019-02b8e6ec-a3c9-4ea5-802d-6a2c05e2669f.png)
***
<br/>

- `Queue` now has two values.

![image](https://user-images.githubusercontent.com/89616705/188290952-428da4ae-5d85-43c2-9d62-beb4cfcaaef0.png)
***
<br/>

- `151` is popped and assigned to `num`.

![image](https://user-images.githubusercontent.com/89616705/188291001-ccc4abdd-ca20-4efe-874b-eeaf7ce9afdb.png)
***
<br/>

- `151` is greater than `min` thus add it to the `List`.

![image](https://user-images.githubusercontent.com/89616705/188291056-8ef040f9-19f3-4dad-b466-70bcec178080.png)
***
<br/>

- `Queue` has one value.
- `List` has one value.

![image](https://user-images.githubusercontent.com/89616705/188291098-6a91f9eb-c4a3-4913-8be5-79142901801a.png)
***
<br/>

- `159` is popped and assigned to `num`.

![image](https://user-images.githubusercontent.com/89616705/188291106-c24c4b6f-757e-40ab-bb0b-c00aaf958d0c.png)
***
<br/>

- `159` is greater than `min` thus add it to the `List`.

![image](https://user-images.githubusercontent.com/89616705/188291346-0337b25b-66f7-42eb-951d-8eede6e3a230.png)
***
<br/>

- `Queue` is empty.
- `List` has two values.

![image](https://user-images.githubusercontent.com/89616705/188291356-e35e8376-bfbf-4fe1-b68b-022c6e914557.png)
***
<br/>

- `Queue` is empty thus exit the ***while loop***.

![image](https://user-images.githubusercontent.com/89616705/188291364-a40b1826-4870-43ec-b92d-30017e7e997b.png)
***
<br/>

- do another iteration, number begins at `2`.

![image](https://user-images.githubusercontent.com/89616705/188291389-7a250b05-b203-4384-be7b-6d23fa0a01e0.png)
***
<br/>

***Keep doing this until `i = 9`.***
***
<br>

- **Final List**
![image](https://user-images.githubusercontent.com/89616705/188291521-5e259f2f-4bc2-416b-9fde-8d2c25312e77.png)
<br/>
```cpp
return list;
```
- Once we exit the ***for loop***, return our `List` which should contain all values that are `n` digits and for each ***two consecutive digits***, they have an ***absolute difference*** of `k`.

### Code
- **Java**
```java
class Solution {
    public int[] numsSameConsecDiff(int n, int k) {
        if(n == 1) return new int[]{k};
        List<Integer> list = new ArrayList<Integer>();
        int min = (int) Math.pow(10, n - 1);
        for(int i = 1; i < 10; i++){
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(i);
            while(!q.isEmpty()){
                int num = q.poll();
                if (num >= min){
                    list.add(num);
                    continue;
                }
                int x = num%10;
                if(k > 0 && x - k >= 0)
                    q.add(num * 10 + x - k);
                if(x + k < 10)
                    q.add(num * 10 + x + k);
            }
        }
        return list.stream()
                   .mapToInt(i -> i)
                   .toArray();
    }
}
```
![image](https://user-images.githubusercontent.com/89616705/188256992-ad7db9e5-fd3b-4e19-808a-5d4b69ddae29.png)

- **C++**
```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n == 1) return vector<int>{k};
        vector<int> list;
        int min = pow(10, n - 1);
        for(int i = 1; i < 10; i++){
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int num = q.front();
                q.pop();
                if(num >= min){
                    list.push_back(num);
                    continue;
                }
                int x = num % 10;
                if(k > 0 && x - k >= 0)
                    q.push(num * 10 + x - k);
                if(x + k < 10)
                    q.push(num * 10 + x + k);
            }
        }
        return list;
    }
};
```
![image](https://user-images.githubusercontent.com/89616705/188256807-018745eb-59e1-4be9-b809-e3347ccd281d.png)

- **Python**
```python3
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        list = []
        min = pow(10, n - 1)
        for i in range (1, 10):
            q = [i]
            while len(q):
                num = q.pop(0)
                if num >= min:
                    list.append(num)
                    continue
                x = num % 10
                if k > 0 and x - k >= 0:
                    q.append(num * 10 + x - k)
                if x + k < 10:
                    q.append(num * 10 + x + k)
        return list
```
![image](https://user-images.githubusercontent.com/89616705/188257741-439d2469-cdf0-4e62-ad89-8f86642cfac6.png)

### Complexity
- **Time:** `O(n)`
- **Space:** `O(2^n)`
