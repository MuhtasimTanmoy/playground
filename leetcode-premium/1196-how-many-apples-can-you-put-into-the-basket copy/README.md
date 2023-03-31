<h2><a href="https://leetcode.com/problems/how-many-apples-can-you-put-into-the-basket/">1196. How Many Apples Can You Put into the Basket</a></h2><h3>Easy</h3><hr><div><p>You have some apples and a basket that can carry up to <code>5000</code> units of weight.</p>

<p>Given an integer array <code>weight</code> where <code>weight[i]</code> is the weight of the <code>i<sup>th</sup></code> apple, return <em>the maximum number of apples you can put in the basket</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> weight = [100,200,150,1000]
<strong>Output:</strong> 4
<strong>Explanation:</strong> All 4 apples can be carried by the basket since their sum of weights is 1450.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> weight = [900,950,800,1000,700,800]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= weight.length &lt;= 10<sup>3</sup></code></li>
	<li><code>1 &lt;= weight[i] &lt;= 10<sup>3</sup></code></li>
</ul>
</div>