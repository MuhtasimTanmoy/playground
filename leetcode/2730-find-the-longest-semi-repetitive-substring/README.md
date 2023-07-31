<h2><a href="https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/">2730. Find the Longest Semi-Repetitive Substring</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> string <code>s</code> that consists of digits from <code>0</code> to <code>9</code>.</p>

<p>A string <code>t</code> is called a <strong>semi-repetitive</strong> if there is at most one consecutive pair of the same digits inside <code>t</code>. For example, <code>0010</code>, <code>002020</code>, <code>0123</code>, <code>2002</code>, and <code>54944</code> are semi-repetitive while&nbsp;<code>00101022</code>, and <code>1101234883</code> are not.</p>

<p>Return <em>the length of the longest semi-repetitive substring inside</em> <code>s</code>.</p>

<p>A <b>substring</b> is a contiguous <strong>non-empty</strong> sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "52233"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest semi-repetitive substring is "5223", which starts at i = 0 and ends at j = 3. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "5494"
<strong>Output:</strong> 4
<strong>Explanation:</strong> s is a semi-reptitive string, so the answer is 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "1111111"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The longest semi-repetitive substring is "11", which starts at i = 0 and ends at j = 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '9'</code></li>
</ul>
</div>