# [1050] Actors and Directors Who Cooperated At Least Three Times

**[database]**

### Statement

Table: `ActorDirector`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| actor_id    | int     |
| director_id | int     |
| timestamp   | int     |
+-------------+---------+
timestamp is the primary key column for this table.

```




Write a SQL query for a report that provides the pairs `(actor_id, director_id)` where the actor has cooperated with the director at least three times.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
ActorDirector table:
+-------------+-------------+-------------+
| actor_id    | director_id | timestamp   |
+-------------+-------------+-------------+
| 1           | 1           | 0           |
| 1           | 1           | 1           |
| 1           | 1           | 2           |
| 1           | 2           | 3           |
| 1           | 2           | 4           |
| 2           | 1           | 5           |
| 2           | 1           | 6           |
+-------------+-------------+-------------+
**Output:** 
+-------------+-------------+
| actor_id    | director_id |
+-------------+-------------+
| 1           | 1           |
+-------------+-------------+
**Explanation:** The only pair is (1, 1) where they cooperated exactly 3 times.

```


<br>

### Hints

None

<br>

### Solution

```cpp
select
  actor_id, director_id
from
  actordirector
group by
  actor_id, director_id
having
  count(timestamp) >= 3;
```

<br>

### Statistics

- total accepted: 80247
- total submissions: 110751
- acceptance rate: 72.5%
- likes: 311
- dislikes: 35

<br>

### Similar Problems

None
