<h2><a href="https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/">2046. Sort Linked List Already Sorted Using Absolute Values</a></h2><h3>Medium</h3><hr><div>Given the <code>head</code> of a singly linked list that is sorted in <strong>non-decreasing</strong> order using the <strong>absolute values</strong> of its nodes, return <em>the list sorted in <strong>non-decreasing</strong> order using the <strong>actual values</strong> of its nodes</em>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/10/17/image-20211017201240-3.png" style="width: 621px; height: 250px;">
<pre><strong>Input:</strong> head = [0,2,-5,5,10,-10]
<strong>Output:</strong> [-10,-5,0,2,5,10]
<strong>Explanation:</strong>
The list sorted in non-descending order using the absolute values of the nodes is [0,2,-5,5,10,-10].
The list sorted in non-descending order using the actual values is [-10,-5,0,2,5,10].
</pre>

<p><strong class="example">Example 2:</strong></p>
<img src="https://assets.leetcode.com/uploads/2021/10/17/image-20211017201318-4.png" style="width: 338px; height: 250px;">
<pre><strong>Input:</strong> head = [0,1,2]
<strong>Output:</strong> [0,1,2]
<strong>Explanation:</strong>
The linked list is already sorted in non-decreasing order.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> head = [1]
<strong>Output:</strong> [1]
<strong>Explanation:</strong>
The linked list is already sorted in non-decreasing order.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[1, 10<sup>5</sup>]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
	<li><code>head</code> is sorted in non-decreasing order using the absolute value of its nodes.</li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong>
<ul>
	<li>Can you think of a solution with <code>O(n)</code> time complexity?</li>
</ul>
</div>