<h2><a href="https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/">2808. Minimum Seconds to Equalize a Circular Array</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> array <code>nums</code> containing <code>n</code> integers.</p>

<p>At each second, you perform the following operation on the array:</p>

<ul>
	<li>For every index <code>i</code> in the range <code>[0, n - 1]</code>, replace <code>nums[i]</code> with either <code>nums[i]</code>, <code>nums[(i - 1 + n) % n]</code>, or <code>nums[(i + 1) % n]</code>.</li>
</ul>

<p><strong>Note</strong> that all the elements get replaced simultaneously.</p>

<p>Return <em>the <strong>minimum</strong> number of seconds needed to make all elements in the array</em> <code>nums</code> <em>equal</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,1,2]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can equalize the array in 1 second in the following way:
- At 1<sup>st</sup> second, replace values at each index with [nums[3],nums[1],nums[3],nums[3]]. After replacement, nums = [2,2,2,2].
It can be proven that 1 second is the minimum amount of seconds needed for equalizing the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,1,3,3,2]
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can equalize the array in 2 seconds in the following way:
- At 1<sup>st</sup> second, replace values at each index with [nums[0],nums[2],nums[2],nums[2],nums[3]]. After replacement, nums = [2,3,3,3,3].
- At 2<sup>nd</sup> second, replace values at each index with [nums[1],nums[1],nums[2],nums[3],nums[4]]. After replacement, nums = [3,3,3,3,3].
It can be proven that 2 seconds is the minimum amount of seconds needed for equalizing the array.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,5,5,5]
<strong>Output:</strong> 0
<strong>Explanation:</strong> We don't need to perform any operations as all elements in the initial array are the same.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>