<h2><a href="https://leetcode.com/problems/last-visited-integers/">2899. Last Visited Integers</a></h2><h3>Easy</h3><hr><div><p>Given a <strong>0-indexed</strong> array of strings <code>words</code> where <code>words[i]</code> is either a positive integer represented as a string or the string <code>"prev"</code>.</p>

<p>Start iterating from the beginning of the array; for every <code>"prev"</code> string seen in <code>words</code>, find the <strong>last visited integer</strong> in <code>words</code> which is defined as follows:</p>

<ul>
	<li>Let <code>k</code> be the number of consecutive <code>"prev"</code> strings seen so far (containing the current string). Let <code>nums</code> be the <strong>0-indexed </strong>array of <strong>integers</strong> seen so far and <code>nums_reverse</code> be the reverse of <code>nums</code>, then the integer at <code>(k - 1)<sup>th</sup></code> index of <code>nums_reverse</code> will be the <strong>last visited integer</strong> for this <code>"prev"</code>.</li>
	<li>If <code>k</code> is <strong>greater</strong> than the total visited integers, then the last visited integer will be <code>-1</code>.</li>
</ul>

<p>Return <em>an integer array containing the last visited integers.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["1","2","prev","prev","prev"]
<strong>Output:</strong> [2,1,-1]
<strong>Explanation:</strong> 
For "prev" at index = 2, last visited integer will be 2 as here the number of consecutive "prev" strings is 1, and in the array reverse_nums, 2 will be the first element.
For "prev" at index = 3, last visited integer will be 1 as there are a total of two consecutive "prev" strings including this "prev" which are visited, and 1 is the second last visited integer.
For "prev" at index = 4, last visited integer will be -1 as there are a total of three consecutive "prev" strings including this "prev" which are visited, but the total number of integers visited is two.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["1","prev","2","prev","prev"]
<strong>Output:</strong> [1,2,1]
<strong>Explanation:</strong>
For "prev" at index = 1, last visited integer will be 1.
For "prev" at index = 3, last visited integer will be 2.
For "prev" at index = 4, last visited integer will be 1 as there are a total of two consecutive "prev" strings including this "prev" which are visited, and 1 is the second last visited integer.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 100</code></li>
	<li><code>words[i] == "prev"</code> or <code>1 &lt;= int(words[i]) &lt;= 100</code></li>
</ul>
</div>