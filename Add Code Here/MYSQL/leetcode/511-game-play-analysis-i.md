# [511] Game Play Analysis I

**[database]**

### Statement

Table: `Activity`

```

+--------------+---------+
| Column Name  | Type    |
+--------------+---------+
| player_id    | int     |
| device_id    | int     |
| event_date   | date    |
| games_played | int     |
+--------------+---------+
(player_id, event_date) is the primary key of this table.
This table shows the activity of players of some games.
Each row is a record of a player who logged in and played a number of games (possibly 0) before logging out on someday using some device.

```




Write an SQL query to report the **first login date** for each player.

Return the result table in **any order**.

The query result format is in the following example.


**Example 1:**

```

**Input:** 
Activity table:
+-----------+-----------+------------+--------------+
| player_id | device_id | event_date | games_played |
+-----------+-----------+------------+--------------+
| 1         | 2         | 2016-03-01 | 5            |
| 1         | 2         | 2016-05-02 | 6            |
| 2         | 3         | 2017-06-25 | 1            |
| 3         | 1         | 2016-03-02 | 0            |
| 3         | 4         | 2018-07-03 | 5            |
+-----------+-----------+------------+--------------+
**Output:** 
+-----------+-------------+
| player_id | first_login |
+-----------+-------------+
| 1         | 2016-03-01  |
| 2         | 2017-06-25  |
| 3         | 2016-03-02  |
+-----------+-------------+

```


<br>

### Hints

None

<br>

### Solution

```mysql
select
  player_id,
  min(event_date) as first_login
from
  activity
group by
  player_id;
```

<br>

### Statistics

- total accepted: 119042
- total submissions: 150963
- acceptance rate: 78.9%
- likes: 395
- dislikes: 14

<br>

### Similar Problems

- [Game Play Analysis II](https://leetcode.com/problems/game-play-analysis-ii) (Easy)
