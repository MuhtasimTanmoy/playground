<h2><a href="https://leetcode.com/problems/most-frequent-ids/">3092. Most Frequent IDs</a></h2><h3>Medium</h3><hr><div><p>The problem involves tracking the frequency of IDs in a collection that changes over time. You have two integer arrays, <code>nums</code> and <code>freq</code>, of equal length <code>n</code>. Each element in <code>nums</code> represents an ID, and the corresponding element in <code>freq</code> indicates how many times that ID should be added to or removed from the collection at each step.</p>

<ul>
	<li><strong>Addition of IDs:</strong> If <code>freq[i]</code> is positive, it means <code>freq[i]</code> IDs with the value <code>nums[i]</code> are added to the collection at step <code>i</code>.</li>
	<li><strong>Removal of IDs:</strong> If <code>freq[i]</code> is negative, it means <code>-freq[i]</code> IDs with the value <code>nums[i]</code> are removed from the collection at step <code>i</code>.</li>
</ul>

<p>Return an array <code>ans</code> of length <code>n</code>, where <code>ans[i]</code> represents the <strong>count</strong> of the <em>most frequent ID</em> in the collection after the <code>i<sup>th</sup></code>&nbsp;step. If the collection is empty at any step, <code>ans[i]</code> should be 0 for that step.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,3,2,1], freq = [3,2,-3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[3,3,2,2]</span></p>

<p><strong>Explanation:</strong></p>

<p>After step 0, we have 3 IDs with the value of 2. So <code>ans[0] = 3</code>.<br>
After step 1, we have 3 IDs with the value of 2 and 2 IDs with the value of 3. So <code>ans[1] = 3</code>.<br>
After step 2, we have 2 IDs with the value of 3. So <code>ans[2] = 2</code>.<br>
After step 3, we have 2 IDs with the value of 3 and 1 ID with the value of 1. So <code>ans[3] = 2</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [5,5,3], freq = [2,-2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">[2,0,1]</span></p>

<p><strong>Explanation:</strong></p>

<p>After step 0, we have 2 IDs with the value of 5. So <code>ans[0] = 2</code>.<br>
After step 1, there are no IDs. So <code>ans[1] = 0</code>.<br>
After step 2, we have 1 ID with the value of 3. So <code>ans[2] = 1</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length == freq.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= freq[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>freq[i] != 0</code></li>
	<li>The input is generated<!-- notionvc: a136b55a-f319-4fa6-9247-11be9f3b1db8 --> such that the occurrences of an ID will not be negative in any step.</li>
</ul>
</div>