<h2><a href="https://leetcode.com/problems/missing-number-in-arithmetic-progression/">1228. Missing Number In Arithmetic Progression</a></h2><h3>Easy</h3><hr><div><p>In some array <code>arr</code>, the values were in arithmetic progression: the values <code>arr[i + 1] - arr[i]</code> are all equal for every <code>0 &lt;= i &lt; arr.length - 1</code>.</p>

<p>A value from <code>arr</code> was removed that <strong>was not the first or last value in the array</strong>.</p>

<p>Given <code>arr</code>, return <em>the removed value</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = [5,7,11,13]
<strong>Output:</strong> 9
<strong>Explanation:</strong> The previous array was [5,7,<strong>9</strong>,11,13].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = [15,13,12]
<strong>Output:</strong> 14
<strong>Explanation:</strong> The previous array was [15,<strong>14</strong>,13,12].</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= arr.length &lt;= 1000</code></li>
	<li><code>0 &lt;= arr[i] &lt;= 10<sup>5</sup></code></li>
	<li>The given array is <strong>guaranteed</strong> to be a valid array.</li>
</ul>
</div>