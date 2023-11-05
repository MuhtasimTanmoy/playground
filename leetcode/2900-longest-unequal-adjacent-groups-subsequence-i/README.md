<h2><a href="https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/">2900. Longest Unequal Adjacent Groups Subsequence I</a></h2><h3>Medium</h3><hr><div><p>You are given an integer <code>n</code>, a <strong>0-indexed</strong> string array <code>words</code>, and a <strong>0-indexed</strong> <strong>binary</strong> array <code>groups</code>, both arrays having length <code>n</code>.</p>

<p>You need to select the <strong>longest</strong> <strong>subsequence</strong> from an array of indices <code>[0, 1, ..., n - 1]</code>, such that for the subsequence denoted as <code>[i<sub>0</sub>, i<sub>1</sub>, ..., i<sub>k - 1</sub>]</code> having length <code>k</code>, <code>groups[i<sub>j</sub>] != groups[i<sub>j + 1</sub>]</code>, for each <code>j</code> where <code>0 &lt; j + 1 &lt; k</code>.</p>

<p>Return <em>a string array containing the words corresponding to the indices <strong>(in order)</strong> in the selected subsequence</em>. If there are multiple answers, return<em> any of them</em>.</p>

<p>A <strong>subsequence</strong> of an array is a new array that is formed from the original array by deleting some (possibly none) of the elements without disturbing the relative positions of the remaining elements.</p>

<p><strong>Note:</strong> strings in <code>words</code> may be <strong>unequal</strong> in length.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 3, words = ["e","a","b"], groups = [0,0,1]
<strong>Output:</strong> ["e","b"]
<strong>Explanation: </strong>A subsequence that can be selected is [0,2] because groups[0] != groups[2].
So, a valid answer is [words[0],words[2]] = ["e","b"].
Another subsequence that can be selected is [1,2] because groups[1] != groups[2].
This results in [words[1],words[2]] = ["a","b"].
It is also a valid answer.
It can be shown that the length of the longest subsequence of indices that satisfies the condition is 2.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 4, words = ["a","b","c","d"], groups = [1,0,1,1]
<strong>Output:</strong> ["a","b","c"]
<strong>Explanation:</strong> A subsequence that can be selected is [0,1,2] because groups[0] != groups[1] and groups[1] != groups[2].
So, a valid answer is [words[0],words[1],words[2]] = ["a","b","c"].
Another subsequence that can be selected is [0,1,3] because groups[0] != groups[1] and groups[1] != groups[3].
This results in [words[0],words[1],words[3]] = ["a","b","d"].
It is also a valid answer.
It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n == words.length == groups.length &lt;= 100</code></li>
	<li><code>1 &lt;= words[i].length &lt;= 10</code></li>
	<li><code>0 &lt;= groups[i] &lt; 2</code></li>
	<li><code>words</code> consists of <strong>distinct</strong> strings.</li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
</ul>
</div>