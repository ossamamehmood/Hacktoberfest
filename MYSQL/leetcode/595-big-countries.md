# [595] Big Countries

**[database]**

### Statement

Table: `World`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| name        | varchar |
| continent   | varchar |
| area        | int     |
| population  | int     |
| gdp         | int     |
+-------------+---------+
name is the primary key column for this table.
Each row of this table gives information about the name of a country, the continent to which it belongs, its area, the population, and its GDP value.

```




A country is **big** if:

* it has an area of at leastthree million (i.e., `3000000 km2`), or
* it has a population of at leasttwenty-five million (i.e., `25000000`).



Write an SQL query to report the name, population, and area of the **big countries**.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
World table:
+-------------+-----------+---------+------------+--------------+
| name        | continent | area    | population | gdp          |
+-------------+-----------+---------+------------+--------------+
| Afghanistan | Asia      | 652230  | 25500100   | 20343000000  |
| Albania     | Europe    | 28748   | 2831741    | 12960000000  |
| Algeria     | Africa    | 2381741 | 37100000   | 188681000000 |
| Andorra     | Europe    | 468     | 78115      | 3712000000   |
| Angola      | Africa    | 1246700 | 20609294   | 100990000000 |
+-------------+-----------+---------+------------+--------------+
**Output:** 
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan | 25500100   | 652230  |
| Algeria     | 37100000   | 2381741 |
+-------------+------------+---------+

```


<br>

### Hints

None

<br>

### Solution

```mysql
select
  name,
  population,
  area
from
  world
where
  area >= 3000000
    or
  population >= 25000000;
```

Using `union`

```mysql
select
  name,
  population,
  area
from
  world
where
  area >= 3000000

union

select
  name,
  population,
  area
from
  world
where
  population >= 25000000;
```

<br>

### Statistics

- total accepted: 441675
- total submissions: 597594
- acceptance rate: 73.9%
- likes: 1316
- dislikes: 1021

<br>

### Similar Problems

None
