<h2><a href="https://leetcode.com/problems/number-of-valid-clock-times/">2437. Number of Valid Clock Times</a></h2><h3>Easy</h3><hr><div><p>You are given a string of length <code>5</code> called <code>time</code>, representing the current time on a digital clock in the format <code>"hh:mm"</code>. The <strong>earliest</strong> possible time is <code>"00:00"</code> and the <strong>latest</strong> possible time is <code>"23:59"</code>.</p>

<p>In the string <code>time</code>, the digits represented by the <code>?</code>&nbsp;symbol are <strong>unknown</strong>, and must be <strong>replaced</strong> with a digit from <code>0</code> to <code>9</code>.</p>

<p>Return<em> an integer </em><code>answer</code><em>, the number of valid clock times that can be created by replacing every </em><code>?</code><em>&nbsp;with a digit from </em><code>0</code><em> to </em><code>9</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> time = "?5:00"
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can replace the ? with either a 0 or 1, producing "05:00" or "15:00". Note that we cannot replace it with a 2, since the time "25:00" is invalid. In total, we have two choices.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> time = "0?:0?"
<strong>Output:</strong> 100
<strong>Explanation:</strong> Each ? can be replaced by any digit from 0 to 9, so we have 100 total choices.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> time = "??:??"
<strong>Output:</strong> 1440
<strong>Explanation:</strong> There are 24 possible choices for the hours, and 60 possible choices for the minutes. In total, we have 24 * 60 = 1440 choices.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>time</code> is a valid string of length <code>5</code> in the format <code>"hh:mm"</code>.</li>
	<li><code>"00" &lt;= hh &lt;= "23"</code></li>
	<li><code>"00" &lt;= mm &lt;= "59"</code></li>
	<li>Some of the digits might be replaced with <code>'?'</code> and need to be replaced with digits from <code>0</code> to <code>9</code>.</li>
</ul>
</div>