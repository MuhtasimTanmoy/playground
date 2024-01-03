<h2><a href="https://leetcode.com/problems/make-three-strings-equal/">2937. Make Three Strings Equal</a></h2><h3>Easy</h3><hr><div><p>You are given three strings <code>s1</code>, <code>s2</code>, and <code>s3</code>. You have to perform the following operation on these three strings <strong>as many times</strong> as you want<!-- notionvc: b5178de7-3318-4129-b7d9-726b47e90621 -->.</p>

<p>In one operation you can choose one of these three strings such that its length is at least <code>2</code><!-- notionvc: 3342ac46-33c8-4010-aacd-e58678ce31ef --> and delete the <strong>rightmost</strong> character of it.</p>

<p>Return <em>the <strong>minimum</strong> number of operations you need to perform to make the three strings equal if there is a way to make them equal, otherwise, return </em><code>-1</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "abc", s2 = "abb", s3 = "ab"
<strong>Output:</strong> 2
<strong>Explanation:</strong> Performing operations on s1 and s2 once will lead to three equal strings.
It can be shown that there is no way to make them equal with less than two operations.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "dac", s2 = "bac", s3 = "cac"
<strong>Output:</strong> -1
<strong>Explanation:</strong> Because the leftmost letters<!-- notionvc: 47239f7c-eec1-49f8-af79-c206ec88cb07 --> of s1 and s2 are not equal, they could not be equal after any number of operations. So the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length, s3.length &lt;= 100</code></li>
	<li><font face="monospace"><code>s1</code>,</font> <code><font face="monospace">s2</font></code><font face="monospace"> and</font> <code><font face="monospace">s3</font></code> consist only of lowercase English letters.</li>
</ul>
</div>