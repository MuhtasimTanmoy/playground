<h2><a href="https://leetcode.com/problems/count-anagrams/">2514. Count Anagrams</a></h2><h3>Hard</h3><hr><div><p>You are given a string <code>s</code> containing one or more words. Every consecutive pair of words is separated by a single space <code>' '</code>.</p>

<p>A string <code>t</code> is an <strong>anagram</strong> of string <code>s</code> if the <code>i<sup>th</sup></code> word of <code>t</code> is a <strong>permutation</strong> of the <code>i<sup>th</sup></code> word of <code>s</code>.</p>

<ul>
	<li>For example, <code>"acb dfe"</code> is an anagram of <code>"abc def"</code>, but <code>"def cab"</code>&nbsp;and <code>"adc bef"</code> are not.</li>
</ul>

<p>Return <em>the number of <strong>distinct anagrams</strong> of </em><code>s</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "too hot"
<strong>Output:</strong> 18
<strong>Explanation:</strong> Some of the anagrams of the given string are "too hot", "oot hot", "oto toh", "too toh", and "too oht".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "aa"
<strong>Output:</strong> 1
<strong>Explanation:</strong> There is only one anagram possible for the given string.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consists of lowercase English letters and spaces <code>' '</code>.</li>
	<li>There is single space between consecutive words.</li>
</ul>
</div>