<h2><a href="https://leetcode.com/problems/maximum-profit-from-trading-stocks/">2291. Maximum Profit From Trading Stocks</a></h2><h3>Medium</h3><hr><div><p>You are given two <strong>0-indexed</strong> integer arrays of the same length <code>present</code> and <code>future</code> where <code>present[i]</code> is the current price of the <code>i<sup>th</sup></code> stock and <code>future[i]</code> is the price of the <code>i<sup>th</sup></code> stock a year in the future. You may buy each stock at most <strong>once</strong>. You are also given an integer <code>budget</code> representing the amount of money you currently have.</p>

<p>Return <em>the maximum amount of profit you can make.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> present = [5,4,6,2,3], future = [8,5,4,3,5], budget = 10
<strong>Output:</strong> 6
<strong>Explanation:</strong> One possible way to maximize your profit is to:
Buy the 0<sup>th</sup>, 3<sup>rd</sup>, and 4<sup>th</sup> stocks for a total of 5 + 2 + 3 = 10.
Next year, sell all three stocks for a total of 8 + 3 + 5 = 16.
The profit you made is 16 - 10 = 6.
It can be shown that the maximum profit you can make is 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> present = [2,2,5], future = [3,4,10], budget = 6
<strong>Output:</strong> 5
<strong>Explanation:</strong> The only possible way to maximize your profit is to:
Buy the 2<sup>nd</sup> stock, and make a profit of 10 - 5 = 5.
It can be shown that the maximum profit you can make is 5.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> present = [3,3,12], future = [0,3,15], budget = 10
<strong>Output:</strong> 0
<strong>Explanation:</strong> One possible way to maximize your profit is to:
Buy the 1<sup>st</sup> stock, and make a profit of 3 - 3 = 0.
It can be shown that the maximum profit you can make is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == present.length == future.length</code></li>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= present[i], future[i] &lt;= 100</code></li>
	<li><code>0 &lt;= budget &lt;= 1000</code></li>
</ul>
</div>