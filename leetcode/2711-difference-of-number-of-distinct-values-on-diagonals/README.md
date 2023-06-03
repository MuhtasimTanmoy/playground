<h2><a href="https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/">2711. Difference of Number of Distinct Values on Diagonals</a></h2><h3>Easy</h3><hr><div><p>Given a <strong>0-indexed</strong> 2D <code>grid</code> of size <code>m x n</code>, you should find the matrix <code>answer</code> of size <code>m x n</code>.</p>

<p>The value of each cell <code>(r, c)</code> of the matrix <code>answer</code> is calculated in the following way:</p>

<ul>
	<li>Let <code>topLeft[r][c]</code> be the number of <strong>distinct</strong> values in the top-left diagonal of the cell <code>(r, c)</code> in the matrix <code>grid</code>.</li>
	<li>Let <code>bottomRight[r][c]</code> be the number of <strong>distinct</strong> values in the bottom-right diagonal of the cell <code>(r, c)</code> in the matrix <code>grid</code>.</li>
</ul>

<p>Then <code>answer[r][c] = |topLeft[r][c] - bottomRight[r][c]|</code>.</p>

<p>Return <em>the matrix</em> <code>answer</code>.</p>

<p>A <strong>matrix diagonal</strong> is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end.</p>

<p>A cell <code>(r<sub>1</sub>, c<sub>1</sub>)</code> belongs to the top-left diagonal of the cell <code>(r, c)</code>, if both belong to the same diagonal and <code>r<sub>1</sub> &lt; r</code>. Similarly is defined bottom-right diagonal.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2023/04/19/ex2.png" style="width: 786px; height: 121px;">
<pre><strong>
Input:</strong> grid = [[1,2,3],[3,1,5],[3,2,1]]
<strong>Output:</strong> [[1,1,0],[1,0,1],[0,1,1]]
<strong>Explanation:</strong> The 1<sup>st</sup> diagram denotes the initial grid.&nbsp;
The 2<sup>nd</sup> diagram denotes a grid for cell (0,0), where blue-colored cells are cells on its bottom-right diagonal.
The 3<sup>rd</sup> diagram denotes a grid for cell (1,2), where red-colored cells are cells on its top-left diagonal.
The 4<sup>th</sup> diagram denotes a grid for cell (1,1), where blue-colored cells are cells on its bottom-right diagonal and red-colored cells are cells on its top-left diagonal.
- The cell (0,0) contains [1,1] on its bottom-right diagonal and [] on its top-left diagonal. The answer is |1 - 0| = 1.
- The cell (1,2) contains [] on its bottom-right diagonal and [2] on its top-left diagonal. The answer is |0 - 1| = 1.
- The cell (1,1) contains [1] on its bottom-right diagonal and [1] on its top-left diagonal. The answer is |1 - 1| = 0.
The answers of other cells are similarly calculated.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [[1]]
<strong>Output:</strong> [[0]]
<strong>Explanation:</strong> - The cell (0,0) contains [] on its bottom-right diagonal and [] on its top-left diagonal. The answer is |0 - 0| = 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 &lt;= m, n, grid[i][j] &lt;= 50</code></li>
</ul>
</div>