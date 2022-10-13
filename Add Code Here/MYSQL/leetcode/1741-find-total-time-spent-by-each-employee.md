# [1741] Find Total Time Spent by Each Employee

**[database]**

### Statement

Table: `Employees`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| emp\_id      | int  |
| event\_day   | date |
| in\_time     | int  |
| out\_time    | int  |
+-------------+------+
(emp\_id, event\_day, in\_time) is the primary key of this table.
The table shows the employees' entries and exits in an office.
event\_day is the day at which this event happened, in\_time is the minute at which the employee entered the office, and out\_time is the minute at which they left the office.
in\_time and out\_time are between 1 and 1440.
It is guaranteed that no two events on the same day intersect in time, and in\_time < out\_time.

```




Write an SQL query to calculate the total time **in minutes** spent by each employee on each day at the office. Note that within one day, an employee can enter and leave more than once. The time spent in the office for a single entry is `out_time - in_time`.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Employees table:
+--------+------------+---------+----------+
| emp\_id | event\_day  | in\_time | out\_time |
+--------+------------+---------+----------+
| 1      | 2020-11-28 | 4       | 32       |
| 1      | 2020-11-28 | 55      | 200      |
| 1      | 2020-12-03 | 1       | 42       |
| 2      | 2020-11-28 | 3       | 33       |
| 2      | 2020-12-09 | 47      | 74       |
+--------+------------+---------+----------+
**Output:** 
+------------+--------+------------+
| day        | emp\_id | total\_time |
+------------+--------+------------+
| 2020-11-28 | 1      | 173        |
| 2020-11-28 | 2      | 30         |
| 2020-12-03 | 1      | 41         |
| 2020-12-09 | 2      | 27         |
+------------+--------+------------+
**Explanation:** 
Employee 1 has three events: two on day 2020-11-28 with a total of (32 - 4) + (200 - 55) = 173, and one on day 2020-12-03 with a total of (42 - 1) = 41.
Employee 2 has two events: one on day 2020-11-28 with a total of (33 - 3) = 30, and one on day 2020-12-09 with a total of (74 - 47) = 27.

```


<br>

### Hints

None

<br>

### Solution

```cpp
select
  event_day as day,
  emp_id,
  sum(out_time - in_time) as total_time
from
  Employees
group by
  event_day,
  emp_id
```

<br>

### Statistics

- total accepted: 39221
- total submissions: 42629
- acceptance rate: 92.0%
- likes: 238
- dislikes: 5

<br>

### Similar Problems

None
