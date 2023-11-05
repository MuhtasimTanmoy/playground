<h2><a href="https://leetcode.com/problems/find-indices-with-index-and-value-difference-ii/">2905. Find Indices With Index and Value Difference II</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> having length <code>n</code>, an integer <code>indexDifference</code>, and an integer <code>valueDifference</code>.</p>

<p>Your task is to find <strong>two</strong> indices <code>i</code> and <code>j</code>, both in the range <code>[0, n - 1]</code>, that satisfy the following conditions:</p>

<ul>
	<li><code>abs(i - j) &gt;= indexDifference</code>, and</li>
	<li><code>abs(nums[i] - nums[j]) &gt;= valueDifference</code></li>
</ul>

<p>Return <em>an integer array</em> <code>answer</code>, <em>where</em> <code>answer = [i, j]</code> <em>if there are two such indices</em>, <em>and</em> <code>answer = [-1, -1]</code> <em>otherwise</em>. If there are multiple choices for the two indices, return <em>any of them</em>.</p>

<p><strong>Note:</strong> <code>i</code> and <code>j</code> may be <strong>equal</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [5,1,4,1], indexDifference = 2, valueDifference = 4
<strong>Output:</strong> [0,3]
<strong>Explanation:</strong> In this example, i = 0 and j = 3 can be selected.
abs(0 - 3) &gt;= 2 and abs(nums[0] - nums[3]) &gt;= 4.
Hence, a valid answer is [0,3].
[3,0] is also a valid answer.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,1], indexDifference = 0, valueDifference = 0
<strong>Output:</strong> [0,0]
<strong>Explanation:</strong> In this example, i = 0 and j = 0 can be selected.
abs(0 - 0) &gt;= 0 and abs(nums[0] - nums[0]) &gt;= 0.
Hence, a valid answer is [0,0].
Other valid answers are [0,1], [1,0], and [1,1].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3], indexDifference = 2, valueDifference = 4
<strong>Output:</strong> [-1,-1]
<strong>Explanation:</strong> In this example, it can be shown that it is impossible to find two indices that satisfy both conditions.
Hence, [-1,-1] is returned.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>0 &lt;= indexDifference &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= valueDifference &lt;= 10<sup>9</sup></code></li>
</ul>
</div>