<h2><a href="https://leetcode.com/problems/maximum-total-reward-using-operations-i/">3180. Maximum Total Reward Using Operations I</a></h2><h3>Medium</h3><hr><div><p>You are given an integer array <code>rewardValues</code> of length <code>n</code>, representing the values of rewards.</p>

<p>Initially, your total reward <code>x</code> is 0, and all indices are <strong>unmarked</strong>. You are allowed to perform the following operation <strong>any</strong> number of times:</p>

<ul>
	<li>Choose an <strong>unmarked</strong> index <code>i</code> from the range <code>[0, n - 1]</code>.</li>
	<li>If <code>rewardValues[i]</code> is <strong>greater</strong> than your current total reward <code>x</code>, then add <code>rewardValues[i]</code> to <code>x</code> (i.e., <code>x = x + rewardValues[i]</code>), and <strong>mark</strong> the index <code>i</code>.</li>
</ul>

<p>Return an integer denoting the <strong>maximum </strong><em>total reward</em> you can collect by performing the operations optimally.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">rewardValues = [1,1,3,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>During the operations, we can choose to mark the indices 0 and 2 in order, and the total reward will be 4, which is the maximum.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">rewardValues = [1,6,4,3,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">11</span></p>

<p><strong>Explanation:</strong></p>

<p>Mark the indices 0, 2, and 1 in order. The total reward will then be 11, which is the maximum.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= rewardValues.length &lt;= 2000</code></li>
	<li><code>1 &lt;= rewardValues[i] &lt;= 2000</code></li>
</ul>
</div>