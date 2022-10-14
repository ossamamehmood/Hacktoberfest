# [596] Classes More Than 5 Students

**[database]**

### Statement

Table: `Courses`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| student     | varchar |
| class       | varchar |
+-------------+---------+
(student, class) is the primary key column for this table.
Each row of this table indicates the name of a student and the class in which they are enrolled.

```




Write an SQL query to report all the classes that have **at least five students**.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Courses table:
+---------+----------+
| student | class    |
+---------+----------+
| A       | Math     |
| B       | English  |
| C       | Math     |
| D       | Biology  |
| E       | Math     |
| F       | Computer |
| G       | Math     |
| H       | Math     |
| I       | Math     |
+---------+----------+
**Output:** 
+---------+
| class   |
+---------+
| Math    |
+---------+
**Explanation:** 
- Math has 6 students, so we include it.
- English has 1 student, so we do not include it.
- Biology has 1 student, so we do not include it.
- Computer has 1 student, so we do not include it.

```


<br>

### Hints

None

<br>

### Solution

Nested query

```mysql
select
  class
from (
  select
    class, count(student) as count
  from
    courses
  group by
    class
) as class_counts
where
  class_counts.count >= 5;
```

Using `having`

```mysql
select
  class
from
  courses
group by
  class
having
  count(distinct student) >= 5;
```

<br>

### Statistics

- total accepted: 204920
- total submissions: 442575
- acceptance rate: 46.3%
- likes: 576
- dislikes: 965

<br>

### Similar Problems

None
