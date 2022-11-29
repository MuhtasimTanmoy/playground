<h2><a href="https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/">2380. Time Needed to Rearrange a Binary String</a></h2><h3>Medium</h3><hr><div><p>You are given a binary string <code>s</code>. In one second, <strong>all</strong> occurrences of <code>"01"</code> are <strong>simultaneously</strong> replaced with <code>"10"</code>. This process <strong>repeats</strong> until no occurrences of <code>"01"</code> exist.</p>

<p>Return<em> the number of seconds needed to complete this process.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "0110101"
<strong>Output:</strong> 4
<strong>Explanation:</strong> 
After one second, s becomes "1011010".
After another second, s becomes "1101100".
After the third second, s becomes "1110100".
After the fourth second, s becomes "1111000".
No occurrence of "01" exists any longer, and the process needed 4 seconds to complete,
so we return 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "11100"
<strong>Output:</strong> 0
<strong>Explanation:</strong>
No occurrence of "01" exists in s, and the processes needed 0 seconds to complete,
so we return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s[i]</code> is either <code>'0'</code> or <code>'1'</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<p>Can you solve this problem in O(n) time complexity?</p>
</div>