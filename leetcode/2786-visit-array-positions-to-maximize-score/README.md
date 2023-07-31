<h2><a href="https://leetcode.com/problems/visit-array-positions-to-maximize-score/">2786. Visit Array Positions to Maximize Score</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> and a positive integer <code>x</code>.</p>

<p>You are <strong>initially</strong> at position <code>0</code> in the array and you can visit other positions according to the following rules:</p>

<ul>
	<li>If you are currently in position <code>i</code>, then you can move to <strong>any</strong> position <code>j</code> such that <code>i &lt; j</code>.</li>
	<li>For each position <code>i</code> that you visit, you get a score of <code>nums[i]</code>.</li>
	<li>If you move from a position <code>i</code> to a position <code>j</code> and the <strong>parities</strong> of <code>nums[i]</code> and <code>nums[j]</code> differ, then you lose a score of <code>x</code>.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> total score you can get</em>.</p>

<p><strong>Note</strong> that initially you have <code>nums[0]</code> points.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,6,1,9,2], x = 5
<strong>Output:</strong> 13
<strong>Explanation:</strong> We can visit the following positions in the array: 0 -&gt; 2 -&gt; 3 -&gt; 4.
The corresponding values are 2, 6, 1 and 9. Since the integers 6 and 1 have different parities, the move 2 -&gt; 3 will make you lose a score of x = 5.
The total score will be: 2 + 6 + 1 + 9 - 5 = 13.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,4,6,8], x = 3
<strong>Output:</strong> 20
<strong>Explanation:</strong> All the integers in the array have the same parities, so we can visit all of them without losing any score.
The total score is: 2 + 4 + 6 + 8 = 20.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i], x &lt;= 10<sup>6</sup></code></li>
</ul>
</div>