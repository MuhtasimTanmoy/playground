<h2><a href="https://leetcode.com/problems/high-access-employees/">2933. High-Access Employees</a></h2><h3>Medium</h3><hr><div><p>You are given a 2D <strong>0-indexed</strong> array of strings, <code>access_times</code>, with size <code>n</code>. For each <code>i</code> where <code>0 &lt;= i &lt;= n - 1</code>, <code>access_times[i][0]</code> represents the name of an employee, and <code>access_times[i][1]</code> represents the access time of that employee. All entries in <code>access_times</code> are within the same day.</p>

<p>The access time is represented as <strong>four digits</strong> using a <strong>24-hour</strong> time format, for example, <code>"0800"</code> or <code>"2250"</code>.</p>

<p>An employee is said to be <strong>high-access</strong> if he has accessed the system <strong>three or more</strong> times within a <strong>one-hour period</strong>.</p>

<p>Times with exactly one hour of difference are <strong>not</strong> considered part of the same one-hour period. For example, <code>"0815"</code> and <code>"0915"</code> are not part of the same one-hour period.</p>

<p>Access times at the start and end of the day are <strong>not</strong> counted within the same one-hour period. For example, <code>"0005"</code> and <code>"2350"</code> are not part of the same one-hour period.</p>

<p>Return <em>a list that contains the names of <strong>high-access</strong> employees with any order you want.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]
<strong>Output:</strong> ["a"]
<strong>Explanation:</strong> "a" has three access times in the one-hour period of [05:32, 06:31] which are 05:32, 05:49, and 06:21.
But "b" does not have more than two access times at all.
So the answer is ["a"].</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> access_times = [["d","0002"],["c","0808"],["c","0829"],["e","0215"],["d","1508"],["d","1444"],["d","1410"],["c","0809"]]
<strong>Output:</strong> ["c","d"]
<strong>Explanation:</strong> "c" has three access times in the one-hour period of [08:08, 09:07] which are 08:08, 08:09, and 08:29.
"d" has also three access times in the one-hour period of [14:10, 15:09] which are 14:10, 14:44, and 15:08.
However, "e" has just one access time, so it can not be in the answer and the final answer is ["c","d"].</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> access_times = [["cd","1025"],["ab","1025"],["cd","1046"],["cd","1055"],["ab","1124"],["ab","1120"]]
<strong>Output:</strong> ["ab","cd"]
<strong>Explanation:</strong> "ab" has three access times in the one-hour period of [10:25, 11:24] which are 10:25, 11:20, and 11:24.
"cd" has also three access times in the one-hour period of [10:25, 11:24] which are 10:25, 10:46, and 10:55.
So the answer is ["ab","cd"].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= access_times.length &lt;= 100</code></li>
	<li><code>access_times[i].length == 2</code></li>
	<li><code>1 &lt;= access_times[i][0].length &lt;= 10</code></li>
	<li><code>access_times[i][0]</code> consists only of English small letters.</li>
	<li><code>access_times[i][1].length == 4</code></li>
	<li><code>access_times[i][1]</code> is in 24-hour time format.</li>
	<li><code>access_times[i][1]</code> consists only of <code>'0'</code> to <code>'9'</code>.</li>
</ul>
</div>