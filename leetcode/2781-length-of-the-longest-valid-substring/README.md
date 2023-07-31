<h2><a href="https://leetcode.com/problems/length-of-the-longest-valid-substring/">2781. Length of the Longest Valid Substring</a></h2><h3>Hard</h3><hr><div><p>You are given a string <code>word</code> and an array of strings <code>forbidden</code>.</p>

<p>A string is called <strong>valid</strong> if none of its substrings are present in <code>forbidden</code>.</p>

<p>Return <em>the length of the <strong>longest valid substring</strong> of the string </em><code>word</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string, possibly empty.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> word = "cbaaaabc", forbidden = ["aaa","cb"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 9 valid substrings in word: "c", "b", "a", "ba", "aa", "bc", "baa", "aab", and "aabc". The length of the longest valid substring is 4. 
It can be shown that all other substrings contain either "aaa" or "cb" as a substring. </pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> word = "leetcode", forbidden = ["de","le","e"]
<strong>Output:</strong> 4
<strong>Explanation:</strong> There are 11 valid substrings in word: "l", "t", "c", "o", "d", "tc", "co", "od", "tco", "cod", and "tcod". The length of the longest valid substring is 4.
It can be shown that all other substrings contain either "de", "le", or "e" as a substring. 
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
	<li><code>1 &lt;= forbidden.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= forbidden[i].length &lt;= 10</code></li>
	<li><code>forbidden[i]</code> consists only of lowercase English letters.</li>
</ul>
</div>