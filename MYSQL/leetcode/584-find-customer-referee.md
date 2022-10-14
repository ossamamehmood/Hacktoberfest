# [584] Find Customer Referee

**[database]**

### Statement

Table: `Customer`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| referee_id  | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.

```




Write an SQL query to report the names of the customer that are **not referred by** the customer with `id = 2`.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Customer table:
+----+------+------------+
| id | name | referee_id |
+----+------+------------+
| 1  | Will | null       |
| 2  | Jane | null       |
| 3  | Alex | 2          |
| 4  | Bill | null       |
| 5  | Zack | 1          |
| 6  | Mark | 2          |
+----+------+------------+
**Output:** 
+------+
| name |
+------+
| Will |
| Jane |
| Bill |
| Zack |
+------+

```


<br>

### Hints

- Be careful of the NULL value

<br>

### Solution

```cpp
select
  name
from
  customer
where
  referee_id is null
    or
  referee_id != 2;
```

<br>

### Statistics

- total accepted: 184761
- total submissions: 240537
- acceptance rate: 76.8%
- likes: 623
- dislikes: 234

<br>

### Similar Problems

None
