<h2><a href="https://leetcode.com/problems/check-if-string-is-decomposable-into-value-equal-substrings/">1933. Check if String Is Decomposable Into Value-Equal Substrings</a></h2><h3>Easy</h3><hr><div><p>A <strong>value-equal</strong> string is a string where <strong>all</strong> characters are the same.</p>

<ul>
	<li>For example, <code>"1111"</code> and <code>"33"</code> are value-equal strings.</li>
	<li>In contrast, <code>"123"</code> is not a value-equal string.</li>
</ul>

<p>Given a digit string <code>s</code>, decompose the string into some number of <strong>consecutive value-equal</strong> substrings where <strong>exactly one</strong> substring has a <strong>length of </strong><code>2</code> and the remaining substrings have a <strong>length of </strong><code>3</code>.</p>

<p>Return <code>true</code><em> if you can decompose </em><code>s</code><em> according to the above rules. Otherwise, return </em><code>false</code>.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "000111000"
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because ["000", "111", "000"] does not have a substring of length 2.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00011111222"
<strong>Output:</strong> true
<strong>Explanation: </strong>s can be decomposed into ["000", "111", "11", "222"].
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "011100022233"
<strong>Output:</strong> false
<strong>Explanation: </strong>s cannot be decomposed according to the rules because of the first '0'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> consists of only digits <code>'0'</code> through <code>'9'</code>.</li>
</ul>
</div>