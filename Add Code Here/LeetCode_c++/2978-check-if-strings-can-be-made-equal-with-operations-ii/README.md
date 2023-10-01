<h2><a href="https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii">2978. Check if Strings Can be Made Equal With Operations II</a></h2><h3>Medium</h3><hr><p>You are given two strings <code>s1</code> and <code>s2</code>, both of length <code>n</code>, consisting of <strong>lowercase</strong> English letters.</p>

<p>You can apply the following operation on <strong>any</strong> of the two strings <strong>any</strong> number of times:</p>

<ul>
	<li>Choose any two indices <code>i</code> and <code>j</code> such that <code>i &lt; j</code> and the difference <code>j - i</code> is <strong>even</strong>, then <strong>swap</strong> the two characters at those indices in the string.</li>
</ul>

<p>Return <code>true</code><em> if you can make the strings </em><code>s1</code><em> and </em><code>s2</code><em> equal, and&nbsp;</em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;abcdba&quot;, s2 = &quot;cabdab&quot;
<strong>Output:</strong> true
<strong>Explanation:</strong> We can apply the following operations on s1:
- Choose the indices i = 0, j = 2. The resulting string is s1 = &quot;cbadba&quot;.
- Choose the indices i = 2, j = 4. The resulting string is s1 = &quot;cbbdaa&quot;.
- Choose the indices i = 1, j = 5. The resulting string is s1 = &quot;cabdab&quot; = s2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s1 = &quot;abe&quot;, s2 = &quot;bea&quot;
<strong>Output:</strong> false
<strong>Explanation:</strong> It is not possible to make the two strings equal.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == s1.length == s2.length</code></li>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist only of lowercase English letters.</li>
</ul>
