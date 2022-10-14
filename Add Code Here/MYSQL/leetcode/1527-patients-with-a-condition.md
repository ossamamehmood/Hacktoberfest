# [1527] Patients With a Condition

**[database]**

### Statement

Table: `Patients`

```

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| patient_id   | int     |
| patient_name | varchar |
| conditions   | varchar |
+--------------+---------+
patient_id is the primary key for this table.
'conditions' contains 0 or more code separated by spaces. 
This table contains information of the patients in the hospital.

```




Write an SQL query to report the patient\_id, patient\_name all conditions of patients who have Type I Diabetes. Type I Diabetes always starts with `DIAB1` prefix

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Patients table:
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 1          | Daniel       | YFEV COUGH   |
| 2          | Alice        |              |
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 |
| 5          | Alain        | DIAB201      |
+------------+--------------+--------------+
**Output:** 
+------------+--------------+--------------+
| patient_id | patient_name | conditions   |
+------------+--------------+--------------+
| 3          | Bob          | DIAB100 MYOP |
| 4          | George       | ACNE DIAB100 | 
+------------+--------------+--------------+
**Explanation:** Bob and George both have a condition that starts with DIAB1.

```


<br>

### Hints

None

<br>

### Solution

```mysql
select
  *
from
  patients
where
  conditions like 'DIAB1%'
    or
  conditions like '% DIAB1%'
```

<br>

### Statistics

- total accepted: 63379
- total submissions: 147487
- acceptance rate: 43.0%
- likes: 230
- dislikes: 273

<br>

### Similar Problems

None
