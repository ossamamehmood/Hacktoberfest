# [1148] Article Views I

**[database]**

### Statement

Table: `Views`

```

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| article_id    | int     |
| author_id     | int     |
| viewer_id     | int     |
| view_date     | date    |
+---------------+---------+
There is no primary key for this table, it may have duplicate rows.
Each row of this table indicates that some viewer viewed an article (written by some author) on some date. 
Note that equal author_id and viewer_id indicate the same person.

```




Write an SQL query to find all the authors that viewed at least one of their own articles.

Return the result table sorted by `id` in ascending order.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Views table:
+------------+-----------+-----------+------------+
| article_id | author_id | viewer_id | view_date  |
+------------+-----------+-----------+------------+
| 1          | 3         | 5         | 2019-08-01 |
| 1          | 3         | 6         | 2019-08-02 |
| 2          | 7         | 7         | 2019-08-01 |
| 2          | 7         | 6         | 2019-08-02 |
| 4          | 7         | 1         | 2019-07-22 |
| 3          | 4         | 4         | 2019-07-21 |
| 3          | 4         | 4         | 2019-07-21 |
+------------+-----------+-----------+------------+
**Output:** 
+------+
| id   |
+------+
| 4    |
| 7    |
+------+

```


<br>

### Hints

None

<br>

### Solution

```cpp
select
  distinct author_id as id
from
  `views`
where
  author_id = viewer_id
order by
  id asc;
```

<br>

### Statistics

- total accepted: 74679
- total submissions: 96961
- acceptance rate: 77.0%
- likes: 248
- dislikes: 25

<br>

### Similar Problems

None
