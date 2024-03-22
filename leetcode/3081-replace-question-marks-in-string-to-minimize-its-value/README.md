<h2><a href="https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/">3081. Replace Question Marks in String to Minimize Its Value</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>s</code>. <code>s[i]</code> is either a lowercase English letter or <code>'?'</code>.</p>

<p>For a string <code>t</code> having length <code>m</code> containing <strong>only</strong> lowercase English letters, we define the function <code>cost(i)</code> for an index <code>i</code>&nbsp;as the number of characters <strong>equal</strong> to <code>t[i]</code>&nbsp;that appeared before it, i.e. in the range <code>[0, i - 1]</code>.</p>

<p>The <strong>value</strong> of <code>t</code> is the <strong>sum</strong> of <code>cost(i)</code> for all indices <code>i</code>.</p>

<p>For example, for the string <code>t = "aab"</code>:</p>

<ul>
	<li><code>cost(0) = 0</code></li>
	<li><code>cost(1) = 1</code></li>
	<li><code>cost(2) = 0</code></li>
	<li>Hence, the value of <code>"aab"</code> is <code>0 + 1 + 0 = 1</code>.</li>
</ul>

<p>Your task is to <strong>replace all</strong> occurrences of <code>'?'</code> in <code>s</code> with any lowercase English letter so that the <strong>value</strong> of <code>s</code> is <strong>minimized</strong>.</p>

<p>Return <em>a string denoting the modified string with replaced occurrences of </em><code>'?'</code><em>. If there are multiple strings resulting in the <strong>minimum value</strong>, return the <span data-keyword="lexicographically-smaller-string">lexicographically smallest</span> one.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> s = "???" </span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;"> "abc" </span></p>

<p><strong>Explanation: </strong> In this example, we can replace the occurrences of <code>'?'</code> to make <code>s</code> equal to <code>"abc"</code>.</p>

<p>For <code>"abc"</code>, <code>cost(0) = 0</code>, <code>cost(1) = 0</code>, and <code>cost(2) = 0</code>.</p>

<p>The value of <code>"abc"</code> is <code>0</code>.</p>

<p>Some other modifications of <code>s</code> that have a value of <code>0</code> are <code>"cba"</code>, <code>"abz"</code>, and, <code>"hey"</code>.</p>

<p>Among all of them, we choose the lexicographically smallest.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">s = "a?a?"</span></p>

<p><strong>Output: </strong> <span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">"abac"</span></p>

<p><strong>Explanation: </strong> In this example, the occurrences of <code>'?'</code> can be replaced to make <code>s</code> equal to <code>"abac"</code>.</p>

<p>For <code>"abac"</code>, <code>cost(0) = 0</code>, <code>cost(1) = 0</code>, <code>cost(2) = 1</code>, and <code>cost(3) = 0</code>.</p>

<p>The value of <code>"abac"</code> is&nbsp;<code>1</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s[i]</code> is either a lowercase English letter or <code>'?'</code>.</li>
</ul>
</div>