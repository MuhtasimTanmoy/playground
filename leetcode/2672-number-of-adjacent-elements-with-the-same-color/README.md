<h2><a href="https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/">2672. Number of Adjacent Elements With the Same Color</a></h2><h3>Medium</h3><hr><div><p>There is a <strong>0-indexed</strong> array <code>nums</code> of length <code>n</code>. Initially, all elements are <strong>uncolored </strong>(has a value of <code>0</code>).</p>

<p>You are given a 2D integer array <code>queries</code> where <code>queries[i] = [index<sub>i</sub>, color<sub>i</sub>]</code>.</p>

<p>For each query, you color the index <code>index<sub>i</sub></code> with the color <code>color<sub>i</sub></code> in the array <code>nums</code>.</p>

<p>Return <em>an array </em><code>answer</code><em> of the same length as </em><code>queries</code><em> where </em><code>answer[i]</code><em> is the number of adjacent elements with the same color <strong>after</strong> the </em><code>i<sup>th</sup></code><em> query</em>.</p>

<p>More formally, <code>answer[i]</code> is the number of indices <code>j</code>, such that <code>0 &lt;= j &lt; n - 1</code> and <code>nums[j] == nums[j + 1]</code> and <code>nums[j] != 0</code> after the <code>i<sup>th</sup></code> query.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 4, queries = [[0,2],[1,2],[3,1],[1,1],[2,1]]
<strong>Output:</strong> [0,1,1,0,2]
<strong>Explanation:</strong> Initially array nums = [0,0,0,0], where 0 denotes uncolored elements of the array.
- After the 1<sup>st</sup> query nums = [2,0,0,0]. The count of adjacent elements with the same color is 0.
- After the 2<sup>nd</sup> query nums = [2,2,0,0]. The count of adjacent elements with the same color is 1.
- After the 3<sup>rd</sup>&nbsp;query nums = [2,2,0,1]. The count of adjacent elements with the same color is 1.
- After the 4<sup>th</sup>&nbsp;query nums = [2,1,0,1]. The count of adjacent elements with the same color is 0.
- After the 5<sup>th</sup>&nbsp;query nums = [2,1,1,1]. The count of adjacent elements with the same color is 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 1, queries = [[0,100000]]
<strong>Output:</strong> [0]
<strong>Explanation:</strong> Initially array nums = [0], where 0 denotes uncolored elements of the array.
- After the 1<sup>st</sup> query nums = [100000]. The count of adjacent elements with the same color is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>queries[i].length&nbsp;== 2</code></li>
	<li><code>0 &lt;= index<sub>i</sub>&nbsp;&lt;= n - 1</code></li>
	<li><code>1 &lt;=&nbsp; color<sub>i</sub>&nbsp;&lt;= 10<sup>5</sup></code></li>
</ul>
</div>