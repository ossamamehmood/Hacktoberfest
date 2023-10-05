<h2><a href="https://leetcode.com/problems/richest-customer-wealth/">1672. Richest Customer Wealth</a></h2><h3>Easy</h3><hr><p>Given <code>mxn</code> integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​ bank.&nbsp;</p>

<p>A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.&nbsp;</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> accounts = [[1,2,3],[3,2,1]]
<strong>Output:</strong> 6
<strong>Explanation:</strong> 1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6
Both customers are considered the richest with a wealth of 6 each, so return 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> [[1,5],[7,3],[3,5]]
<strong>Output:</strong> 10
<strong>Explanation:</strong> 1st customer has wealth = 6
2nd customer has wealth = 10 
3rd customer has wealth = 8
The 2nd customer is the richest with a wealth of 10.

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> [[2,8,7],[7,1,3],[1,9,5]]
<strong>Output:</strong> 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<p>m == accounts.length
n == accounts[i].length
1 <= m, n <= 50
1 <= accounts[i][j] <= 100
</p>
