<h2><a href="https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/">3085. Minimum Deletions to Make String K-Special</a></h2><h3>Medium</h3><hr><div><p>You are given a string <code>word</code> and an integer <code>k</code>.</p>

<p>We consider <code>word</code> to be <strong>k-special</strong> if <code>|freq(word[i]) - freq(word[j])| &lt;= k</code> for all indices <code>i</code> and <code>j</code> in the string.</p>

<p>Here, <code>freq(x)</code> denotes the <span data-keyword="frequency-letter">frequency</span> of the character <code>x</code> in <code>word</code>, and <code>|y|</code> denotes the absolute value of <code>y</code>.</p>

<p>Return <em>the <strong>minimum</strong> number of characters you need to delete to make</em> <code>word</code> <strong><em>k-special</em></strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "aabcaba", k = 0</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">3</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>0</code>-special by deleting <code>2</code> occurrences of <code>"a"</code> and <code>1</code> occurrence of <code>"c"</code>. Therefore, <code>word</code> becomes equal to <code>"baba"</code> where <code>freq('a') == freq('b') == 2</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "dabdcbdcdcd", k = 2</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">2</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>2</code>-special by deleting <code>1</code> occurrence of <code>"a"</code> and <code>1</code> occurrence of <code>"d"</code>. Therefore, <code>word</code> becomes equal to "bdcbdcdcd" where <code>freq('b') == 2</code>, <code>freq('c') == 3</code>, and <code>freq('d') == 4</code>.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block" style="border-color: var(--border-tertiary); border-left-width: 2px; color: var(--text-secondary); font-size: .875rem; margin-bottom: 1rem; margin-top: 1rem; overflow: visible; padding-left: 1rem;">
<p><strong>Input: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">word = "aaabaaa", k = 2</span></p>

<p><strong>Output: </strong><span class="example-io" style="font-family: Menlo,sans-serif; font-size: 0.85rem;">1</span></p>

<p><strong>Explanation:</strong> We can make <code>word</code> <code>2</code>-special by deleting <code>1</code> occurrence of <code>"b"</code>. Therefore, <code>word</code> becomes equal to <code>"aaaaaa"</code> where each letter's frequency is now uniformly <code>6</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= word.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>5</sup></code></li>
	<li><code>word</code> consists only of lowercase English letters.</li>
</ul>
</div>