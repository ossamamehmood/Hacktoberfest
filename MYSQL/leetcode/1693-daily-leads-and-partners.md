# [1693] Daily Leads and Partners

**[database]**

### Statement

Table: `DailySales`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| date\_id     | date    |
| make\_name   | varchar |
| lead\_id     | int     |
| partner\_id  | int     |
+-------------+---------+
This table does not have a primary key.
This table contains the date and the name of the product sold and the IDs of the lead and partner it was sold to.
The name consists of only lowercase English letters.

```




Write an SQL query that will, for each `date_id` and `make_name`, return the number of **distinct** `lead_id`'s and **distinct** `partner_id`'s.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
DailySales table:
+-----------+-----------+---------+------------+
| date\_id   | make\_name | lead\_id | partner\_id |
+-----------+-----------+---------+------------+
| 2020-12-8 | toyota    | 0       | 1          |
| 2020-12-8 | toyota    | 1       | 0          |
| 2020-12-8 | toyota    | 1       | 2          |
| 2020-12-7 | toyota    | 0       | 2          |
| 2020-12-7 | toyota    | 0       | 1          |
| 2020-12-8 | honda     | 1       | 2          |
| 2020-12-8 | honda     | 2       | 1          |
| 2020-12-7 | honda     | 0       | 1          |
| 2020-12-7 | honda     | 1       | 2          |
| 2020-12-7 | honda     | 2       | 1          |
+-----------+-----------+---------+------------+
**Output:** 
+-----------+-----------+--------------+-----------------+
| date\_id   | make\_name | unique\_leads | unique\_partners |
+-----------+-----------+--------------+-----------------+
| 2020-12-8 | toyota    | 2            | 3               |
| 2020-12-7 | toyota    | 1            | 2               |
| 2020-12-8 | honda     | 2            | 2               |
| 2020-12-7 | honda     | 3            | 2               |
+-----------+-----------+--------------+-----------------+
**Explanation:** 
For 2020-12-8, toyota gets leads = [0, 1] and partners = [0, 1, 2] while honda gets leads = [1, 2] and partners = [1, 2].
For 2020-12-7, toyota gets leads = [0] and partners = [1, 2] while honda gets leads = [0, 1, 2] and partners = [1, 2].

```


<br>

### Hints

None

<br>

### Solution

```cpp
select
  date_id,
  make_name,
  count(distinct(lead_id)) as unique_leads,
  count(distinct(partner_id)) as unique_partners
from
  DailySales
group by
  date_id, make_name
```

<br>

### Statistics

- total accepted: 36586
- total submissions: 40113
- acceptance rate: 91.2%
- likes: 193
- dislikes: 17

<br>

### Similar Problems

None
