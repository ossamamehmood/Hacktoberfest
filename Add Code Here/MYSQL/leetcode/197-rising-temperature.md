# [197] Rising Temperature

**[database]**

### Statement

Table: `Weather`

```

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| recordDate    | date    |
| temperature   | int     |
+---------------+---------+
id is the primary key for this table.
This table contains information about the temperature on a certain day.

```




Write an SQL query to find all dates' `Id` with higher temperatures compared to its previous dates (yesterday).

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Weather table:
+----+------------+-------------+
| id | recordDate | temperature |
+----+------------+-------------+
| 1  | 2015-01-01 | 10          |
| 2  | 2015-01-02 | 25          |
| 3  | 2015-01-03 | 20          |
| 4  | 2015-01-04 | 30          |
+----+------------+-------------+
**Output:** 
+----+
| id |
+----+
| 2  |
| 4  |
+----+
**Explanation:** 
In 2015-01-02, the temperature was higher than the previous day (10 -> 25).
In 2015-01-04, the temperature was higher than the previous day (20 -> 30).

```


<br>

### Hints

None

<br>

### Solution

```mysql
select
  id
from
  weather as w1
where
  temperature > (
    select
      temperature
    from
      weather as w2
    where
      w2.recorddate = date_sub(w1.recorddate, interval 1 day)
  );
```

or

```mysql
select
  w1.id
from
  weather as w1,
  weather as w2
where
  w2.recorddate = date_sub(w1.recorddate, interval 1 day)
    and
  w1.temperature > w2.temperature;
```

<br>

### Statistics

- total accepted: 270480
- total submissions: 609806
- acceptance rate: 44.4%
- likes: 1212
- dislikes: 412

<br>

### Similar Problems

None
