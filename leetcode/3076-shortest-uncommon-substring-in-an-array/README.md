<h2><a href="https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/">3076. Shortest Uncommon Substring in an Array</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>arr</code> of size <code>n</code> consisting of <strong>non-empty</strong> strings.</p>

<p>Find a string array <code>answer</code> of size <code>n</code> such that:</p>

<ul>
	<li><code>answer[i]</code> is the <strong>shortest</strong> <span data-keyword="substring">substring</span> of <code>arr[i]</code> that does <strong>not</strong> occur as a substring in any other string in <code>arr</code>. If multiple such substrings exist, <code>answer[i]</code> should be the <span data-keyword="lexicographically-smaller-string">lexicographically smallest</span>. And if no such substring exists, <code>answer[i]</code> should be an empty string.</li>
</ul>

<p>Return <em>the array </em><code>answer</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> arr = ["cab","ad","bad","c"]
<strong>Output:</strong> ["ab","","ba",""]
<strong>Explanation:</strong> We have the following:
- For the string "cab", the shortest substring that does not occur in any other string is either "ca" or "ab", we choose the lexicographically smaller substring, which is "ab".
- For the string "ad", there is no substring that does not occur in any other string.
- For the string "bad", the shortest substring that does not occur in any other string is "ba".
- For the string "c", there is no substring that does not occur in any other string.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> arr = ["abc","bcd","abcd"]
<strong>Output:</strong> ["","","abcd"]
<strong>Explanation:</strong> We have the following:
- For the string "abc", there is no substring that does not occur in any other string.
- For the string "bcd", there is no substring that does not occur in any other string.
- For the string "abcd", the shortest substring that does not occur in any other string is "abcd".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == arr.length</code></li>
	<li><code>2 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= arr[i].length &lt;= 20</code></li>
	<li><code>arr[i]</code> consists only of lowercase English letters.</li>
</ul>
</div>