<h2><a href="https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/">2734. Lexicographically Smallest String After Substring Operation</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code> consisting of only lowercase English letters. In one operation, you can do the following:</p>

<ul>
	<li>Select any non-empty substring of <code>s</code>, possibly the entire string, then replace each one of its characters with the previous character of the English alphabet. For example, 'b' is converted to 'a', and 'a' is converted to 'z'.</li>
</ul>

<p>Return <em>the <strong>lexicographically smallest</strong> string you can obtain after performing the above operation <strong>exactly once</strong>.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>
A string <code>x</code> is <strong>lexicographically smaller</strong> than a string <code>y</code> of the same length if <code>x[i]</code> comes before <code>y[i]</code> in alphabetic order for the first position <code>i</code> such that <code>x[i] != y[i]</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "cbabc"
<strong>Output:</strong> "baabc"
<strong>Explanation:</strong> We apply the operation on the substring starting at index 0, and ending at index 1 inclusive. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "acbbc"
<strong>Output:</strong> "abaab"
<strong>Explanation:</strong> We apply the operation on the substring starting at index 1, and ending at index 4 inclusive. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "leetcode"
<strong>Output:</strong> "kddsbncd"
<strong>Explanation:</strong> We apply the operation on the entire string. 
It can be proven that the resulting string is the lexicographically smallest. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters</li>
</ul>
</div>