<h2><a href="https://leetcode.com/problems/find-the-encrypted-string/">3210. Find the Encrypted String</a></h2><h3>Easy</h3><hr><div><p>You are given a string <code>s</code> and an integer <code>k</code>. Encrypt the string using the following algorithm:</p>

<ul>
	<li>For each character <code>c</code> in <code>s</code>, replace <code>c</code> with the <code>k<sup>th</sup></code> character after <code>c</code> in the string (in a cyclic manner).</li>
</ul>

<p>Return the <em>encrypted string</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "dart", k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">"tdar"</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>For <code>i = 0</code>, the 3<sup>rd</sup> character after <code>'d'</code> is <code>'t'</code>.</li>
	<li>For <code>i = 1</code>, the 3<sup>rd</sup> character after <code>'a'</code> is <code>'d'</code>.</li>
	<li>For <code>i = 2</code>, the 3<sup>rd</sup> character after <code>'r'</code> is <code>'a'</code>.</li>
	<li>For <code>i = 3</code>, the 3<sup>rd</sup> character after <code>'t'</code> is <code>'r'</code>.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "aaa", k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">"aaa"</span></p>

<p><strong>Explanation:</strong></p>

<p>As all the characters are the same, the encrypted string will also be the same.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>s</code> consists only of lowercase English letters.</li>
</ul>
</div>