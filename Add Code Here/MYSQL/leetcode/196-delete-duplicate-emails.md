# [196] Delete Duplicate Emails

**[database]**

### Statement

Table: `Person`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table contains an email. The emails will not contain uppercase letters.

```




Write an SQL query to **delete** all the duplicate emails, keeping only one unique email with the smallest `id`. Note that you are supposed to write a `DELETE` statement and not a `SELECT` one.

After running your script, the answer shown is the `Person` table. The driver will first compile and run your piece of code and then show the `Person` table. The final order of the `Person` table **does not matter**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Person table:
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
+----+------------------+
**Output:** 
+----+------------------+
| id | email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
**Explanation:** john@example.com is repeated two times. We keep the row with the smallest Id = 1.

```


<br>

### Hints

None

<br>

### Solution

```cpp
delete
  person1
from
  person as person1,
  person as person2
where
  person1.email = person2.email
    and
  person1.id > person2.id;
```

<br>

### Statistics

- total accepted: 294221
- total submissions: 506610
- acceptance rate: 58.1%
- likes: 617
- dislikes: 116

<br>

### Similar Problems

None
