<h2><a href="https://leetcode.com/problems/minimum-impossible-or/">2568. Minimum Impossible OR</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong>&nbsp;integer array <code>nums</code>.</p>

<p>We say that an integer x is <strong>expressible</strong> from <code>nums</code> if there exist some integers <code>0 &lt;= index<sub>1</sub> &lt; index<sub>2</sub> &lt; ... &lt; index<sub>k</sub> &lt; nums.length</code> for which <code>nums[index<sub>1</sub>] | nums[index<sub>2</sub>] | ... | nums[index<sub>k</sub>] = x</code>. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of <code>nums</code>.</p>

<p>Return <em>the minimum <strong>positive non-zero integer</strong>&nbsp;that is not </em><em>expressible from </em><code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> 1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. Since 4 is not expressible, we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,3,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can show that 1 is the smallest number that is not expressible.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>