# [627] Swap Salary

**[database]**

### Statement

Table: `Salary`

```

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id is the primary key for this table.
The sex column is ENUM value of type ('m', 'f').
The table contains information about an employee.

```




Write an SQL query to swap all `'f'` and `'m'` values (i.e., change all `'f'` values to `'m'` and vice versa) with a **single update statement** and no intermediate temporary tables.

Note that you must write a single update statement, **do not** write any select statement for this problem.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Salary table:
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
+----+------+-----+--------+
**Output:** 
+----+------+-----+--------+
| id | name | sex | salary |
+----+------+-----+--------+
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
+----+------+-----+--------+
**Explanation:** 
(1, A) and (3, C) were changed from 'm' to 'f'.
(2, B) and (4, D) were changed from 'f' to 'm'.

```


<br>

### Hints

None

<br>

### Solution

```mysql
update
  salary
set
  sex =
  case sex
    when 'm' then 'f'
    when 'f' then 'm'
  end;
```

```mysql
update
  salary
set
  sex = char(
    ascii('m') + ascii('f') - ascii(sex)
  );
```

<br>

### Statistics

- total accepted: 263526
- total submissions: 318648
- acceptance rate: 82.7%
- likes: 1232
- dislikes: 537

<br>

### Similar Problems

None
