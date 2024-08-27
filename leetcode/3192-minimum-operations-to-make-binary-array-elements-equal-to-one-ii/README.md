<h2><a href="https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/">3192. Minimum Operations to Make Binary Array Elements Equal to One II</a></h2><h3>Medium</h3><hr><div><p>You are given a <span data-keyword="binary-array">binary array</span> <code>nums</code>.</p>

<p>You can do the following operation on the array <strong>any</strong> number of times (possibly zero):</p>

<ul>
	<li>Choose <strong>any</strong> index <code>i</code> from the array and <strong>flip</strong> <strong>all</strong> the elements from index <code>i</code> to the end of the array.</li>
</ul>

<p><strong>Flipping</strong> an element means changing its value from 0 to 1, and from 1 to 0.</p>

<p>Return the <strong>minimum</strong> number of operations required to make all elements in <code>nums</code> equal to 1.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [0,1,1,0,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong><br>
We can do the following operations:</p>

<ul>
	<li>Choose the index <code>i = 1</code><span class="example-io">. The resulting array will be <code>nums = [0,<u><strong>0</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>]</code>.</span></li>
	<li>Choose the index <code>i = 0</code><span class="example-io">. The resulting array will be <code>nums = [<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>0</strong></u>,<u><strong>1</strong></u>]</code>.</span></li>
	<li>Choose the index <code>i = 4</code><span class="example-io">. The resulting array will be <code>nums = [1,1,1,0,<u><strong>0</strong></u>]</code>.</span></li>
	<li>Choose the index <code>i = 3</code><span class="example-io">. The resulting array will be <code>nums = [1,1,1,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>.</span></li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io" style="position: relative;">nums = [1,0,0,0]<button class="lazy-felix lazy-felix-download-btn" data-name="[1,0,0,0]"><svg xmlns="http://www.w3.org/2000/svg" class="lazyfelix-icon" width="27" height="25" viewBox="0 0 27 25" fill="none">    <path d="M13.4518 13.0377C11.4186 12.7365 6.4864 16.878 5.39453 21.7726V22.0362C5.48795 24.1899 7.75902 24.9194 10.9292 24.0316C13.0111 23.1639 14.1728 23.1375 16.125 24.0316C17.9698 25.1612 20.41 23.7051 20.643 22.0362C20.3191 18.4517 16.3154 13.1956 13.4518 13.0377Z" fill="#7A7A7A" fill-opacity="0.7"></path>    <ellipse cx="4.85476" cy="11.946" rx="2.97265" ry="4.24369" transform="rotate(-21.5283 4.85476 11.946)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="22.0599" cy="13.5489" rx="2.97265" ry="4.24369" transform="rotate(22.9527 22.0599 13.5489)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="10.1354" cy="5.66514" rx="2.92739" ry="4.7215" transform="rotate(-9.76985 10.1354 5.66514)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="17.552" cy="5.95842" rx="2.92739" ry="4.7215" transform="rotate(14.6303 17.552 5.95842)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>
  </svg></button></span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong><br>
We can do the following operation:</p>

<ul>
	<li>Choose the index <code>i = 1</code><span class="example-io">. The resulting array will be <code>nums = [1,<u><strong>1</strong></u>,<u><strong>1</strong></u>,<u><strong>1</strong></u>]</code>.</span></li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1</code></li>
</ul>
</div>