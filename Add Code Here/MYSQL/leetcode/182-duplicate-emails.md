# [182] Duplicate Emails

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




Write an SQL query to report all the duplicate emails.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Person table:
+----+---------+
| id | email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+
**Output:** 
+---------+
| Email   |
+---------+
| a@b.com |
+---------+
**Explanation:** a@b.com is repeated two times.

```


<br>

### Hints

None

<br>

### Solution

Nested query

```mysql
select
  email
from (
  select
    email, count(email) as 'count'
  from
    person
  group by
    email
) as email_counts
where
  email_counts.count > 1;
```

Self join

```mysql
select
  distinct person1.email
from
  person as person1,
  person as person2
where
  person1.email = person2.email
    and
  person1.id != person2.id;
```

Group By and Having

```mysql
select
  email
from
  person
group by
  email
having
  count(email) > 1;
```

<br>

### Statistics

- total accepted: 418363
- total submissions: 593911
- acceptance rate: 70.4%
- likes: 1384
- dislikes: 52

<br>

### Similar Problems

None
