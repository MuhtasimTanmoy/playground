<h2><a href="https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/">3038. Maximum Number of Operations With the Same Score I</a></h2><h3>Easy</h3><hr><div><p>Given an array of integers called <code>nums</code>, you can perform the following operation while <code>nums</code> contains <strong>at least</strong> <code>2</code> elements:</p>

<ul>
	<li>Choose the first two elements of <code>nums</code> and delete them.</li>
</ul>

<p>The<strong> score</strong> of the operation is the sum of the deleted elements.</p>

<p>Your task is to find the <strong>maximum</strong> number of operations that can be performed, such that <strong>all operations have the same score</strong>.</p>

<p>Return <em>the <strong>maximum</strong> number of operations possible that satisfy the condition mentioned above</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1,4,5]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [1,4,5].
- Delete the first two elements, with score 1 + 4 = 5, nums = [5].
We are unable to perform any more operations as nums contain only 1 element.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,6,1,4]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We perform the following operations:
- Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
We are unable to perform any more operations as the score of the next operation isn't the same as the previous one.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 1000</code></li>
</ul>
</div>