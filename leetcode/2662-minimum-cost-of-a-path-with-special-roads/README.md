<h2><a href="https://leetcode.com/problems/minimum-cost-of-a-path-with-special-roads/">2662. Minimum Cost of a Path With Special Roads</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>start</code> where <code>start = [startX, startY]</code> represents your initial position <code>(startX, startY)</code> in a 2D space. You are also given the array <code>target</code> where <code>target = [targetX, targetY]</code> represents your target position <code>(targetX, targetY)</code>.</p>

<p>The cost of going from a position <code>(x1, y1)</code> to any other position in the space <code>(x2, y2)</code> is <code>|x2 - x1| + |y2 - y1|</code>.</p>

<p>There are also some special roads. You are given a 2D array <code>specialRoads</code> where <code>specialRoads[i] = [x1<sub>i</sub>, y1<sub>i</sub>, x2<sub>i</sub>, y2<sub>i</sub>, cost<sub>i</sub>]</code> indicates that the <code>i<sup>th</sup></code> special road can take you from <code>(x1<sub>i</sub>, y1<sub>i</sub>)</code> to <code>(x2<sub>i</sub>, y2<sub>i</sub>)</code> with a cost equal to <code>cost<sub>i</sub></code>. You can use each special road any number of times.</p>

<p>Return <em>the minimum cost required to go from</em> <code>(startX, startY)</code> to <code>(targetX, targetY)</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
<strong>Output:</strong> 5
<strong>Explanation:</strong> The optimal path from (1,1) to (4,5) is the following:
- (1,1) -&gt; (1,2). This move has a cost of |1 - 1| + |2 - 1| = 1.
- (1,2) -&gt; (3,3). This move uses the first special edge, the cost is 2.
- (3,3) -&gt; (3,4). This move has a cost of |3 - 3| + |4 - 3| = 1.
- (3,4) -&gt; (4,5). This move uses the second special edge, the cost is 1.
So the total cost is 1 + 2 + 1 + 1 = 5.
It can be shown that we cannot achieve a smaller total cost than 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> start = [3,2], target = [5,7], specialRoads = [[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
<strong>Output:</strong> 7
<strong>Explanation:</strong> It is optimal to not use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>start.length == target.length == 2</code></li>
	<li><code>1 &lt;= startX &lt;= targetX &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= startY &lt;= targetY &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= specialRoads.length &lt;= 200</code></li>
	<li><code>specialRoads[i].length == 5</code></li>
	<li><code>startX &lt;= x1<sub>i</sub>, x2<sub>i</sub> &lt;= targetX</code></li>
	<li><code>startY &lt;= y1<sub>i</sub>, y2<sub>i</sub> &lt;= targetY</code></li>
	<li><code>1 &lt;= cost<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
</ul>
</div>