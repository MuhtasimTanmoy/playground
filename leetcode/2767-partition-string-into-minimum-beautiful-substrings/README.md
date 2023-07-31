<h2><a href="https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/">2767. Partition String Into Minimum Beautiful Substrings</a></h2><h3>Medium</h3><hr><div><p>Given a binary string <code>s</code>, partition the string into one or more <strong>substrings</strong> such that each substring is <strong>beautiful</strong>.</p>

<p>A string is <strong>beautiful</strong> if:</p>

<ul>
	<li>It doesn't contain leading zeros.</li>
	<li>It's the <strong>binary</strong> representation of a number that is a power of <code>5</code>.</li>
</ul>

<p>Return <em>the <strong>minimum</strong> number of substrings in such partition. </em>If it is impossible to partition the string <code>s</code> into beautiful substrings,&nbsp;return <code>-1</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1011"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can paritition the given string into ["101", "1"].
- The string "101" does not contain leading zeros and is the binary representation of integer 5<sup>1</sup> = 5.
- The string "1" does not contain leading zeros and is the binary representation of integer 5<sup>0</sup> = 1.
It can be shown that 2 is the minimum number of beautiful substrings that s can be partitioned into.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "111"
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can paritition the given string into ["1", "1", "1"].
- The string "1" does not contain leading zeros and is the binary representation of integer 5<sup>0</sup> = 1.
It can be shown that 3 is the minimum number of beautiful substrings that s can be partitioned into.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "0"
<strong>Output:</strong> -1
<strong>Explanation:</strong> We can not partition the given string into beautiful substrings.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 15</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>
</div>