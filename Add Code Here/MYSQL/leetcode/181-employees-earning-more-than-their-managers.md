# [181] Employees Earning More Than Their Managers

**[database]**

### Statement

Table: `Employee`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.

```




Write an SQL query to find the employees who earn more than their managers.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Employee table:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
**Output:** 
+----------+
| Employee |
+----------+
| Joe      |
+----------+
**Explanation:** Joe is the only employee who earns more than his manager.

```


<br>

### Hints

None

<br>

### Solution

Using cartesian product

```cpp
select
  e1.name as 'Employee'
from
  employee as e1,
  employee as e2
where
  e1.managerid = e2.id
    and
  e1.salary > e2.salary;
```

Using join

```mysql
select
  e1.name as 'Employee'
from
  employee as e1
join
  employee as e2
on
  e1.managerid = e2.id
    and
  e1.salary > e2.salary;
```

<br>

### Statistics

- total accepted: 416319
- total submissions: 609409
- acceptance rate: 68.3%
- likes: 1734
- dislikes: 181

<br>

### Similar Problems

None
