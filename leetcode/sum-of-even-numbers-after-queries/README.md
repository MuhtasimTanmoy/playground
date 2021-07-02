<h2>985. Sum of Even Numbers After Queries</h2><h3>Easy</h3><hr><div><p>We have an array <code>nums</code> of integers, and an array <code>queries</code>&nbsp;of queries.</p>

<p>For the <code>i</code>-th&nbsp;query <code>val =&nbsp;queries[i][0], index&nbsp;= queries[i][1]</code>, we add <font face="monospace">val</font>&nbsp;to <code>nums[index]</code>.&nbsp; Then, the answer to the <code>i</code>-th query is the sum of the even values of <code>A</code>.</p>

<p><em>(Here, the given <code>index = queries[i][1]</code> is a 0-based index, and each query permanently modifies the array <code>nums</code>.)</em></p>

<p>Return the answer to all queries.&nbsp; Your <code>answer</code> array should have&nbsp;<code>answer[i]</code>&nbsp;as&nbsp;the answer to the <code>i</code>-th query.</p>

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong>nums = <span id="example-input-1-1">[1,2,3,4]</span>, queries = <span id="example-input-1-2">[[1,0],[-3,1],[-4,0],[2,3]]</span>
<strong>Output: </strong><span id="example-output-1">[8,6,2,4]</span>
<strong>Explanation: </strong>
At the beginning, the array is [1,2,3,4].
After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even values is 2 + 2 + 4 = 8.
After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even values is 2 + 4 = 6.
After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even values is -2 + 4 = 2.
After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even values is -2 + 6 = 4.
</pre>

<p>&nbsp;</p>

<p><strong>Note:</strong></p>

<ol>
	<li><code>1 &lt;= nums.length &lt;= 10000</code></li>
	<li><code>-10000 &lt;= nums[i] &lt;= 10000</code></li>
	<li><code>1 &lt;= queries.length &lt;= 10000</code></li>
	<li><code>-10000 &lt;= queries[i][0] &lt;= 10000</code></li>
	<li><code>0 &lt;= queries[i][1] &lt; nums.length</code></li>
</ol>
</div>