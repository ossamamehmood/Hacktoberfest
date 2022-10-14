# [183] Customers Who Never Order

**[database]**

### Statement

Table: `Customers`

```

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
+-------------+---------+
id is the primary key column for this table.
Each row of this table indicates the ID and name of a customer.

```




Table: `Orders`

```

+-------------+------+
| Column Name | Type |
+-------------+------+
| id          | int  |
| customerId  | int  |
+-------------+------+
id is the primary key column for this table.
customerId is a foreign key of the ID from the Customers table.
Each row of this table indicates the ID of an order and the ID of the customer who ordered it.

```




Write an SQL query to report all customers who never order anything.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Customers table:
+----+-------+
| id | name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders table:
+----+------------+
| id | customerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
**Output:** 
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

```


<br>

### Hints

None

<br>

### Solution

```mysql
select
  name as 'Customers'
from
  customers
where id not in (
  select customerid from orders
);
```

<br>

### Statistics

- total accepted: 476345
- total submissions: 706114
- acceptance rate: 67.5%
- likes: 1597
- dislikes: 93

<br>

### Similar Problems

None
