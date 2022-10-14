# [1757] Recyclable and Low Fat Products

**[database]**

### Statement

Table: `Products`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| product\_id  | int     |
| low\_fats    | enum    |
| recyclable  | enum    |
+-------------+---------+
product\_id is the primary key for this table.
low\_fats is an ENUM of type ('Y', 'N') where 'Y' means this product is low fat and 'N' means it is not.
recyclable is an ENUM of types ('Y', 'N') where 'Y' means this product is recyclable and 'N' means it is not.
```




Write an SQL query to find the ids of products that are both low fat and recyclable.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Products table:
+-------------+----------+------------+
| product\_id  | low\_fats | recyclable |
+-------------+----------+------------+
| 0           | Y        | N          |
| 1           | Y        | Y          |
| 2           | N        | Y          |
| 3           | Y        | Y          |
| 4           | N        | N          |
+-------------+----------+------------+
**Output:** 
+-------------+
| product\_id  |
+-------------+
| 1           |
| 3           |
+-------------+
**Explanation:** Only products 1 and 3 are both low fat and recyclable.

```


<br>

### Hints

None

<br>

### Solution

```cpp
select
  product_id
from
  Products
where
  low_fats = 'Y' and recyclable = 'Y';
```

<br>

### Statistics

- total accepted: 125690
- total submissions: 133719
- acceptance rate: 94.0%
- likes: 414
- dislikes: 62

<br>

### Similar Problems

None
