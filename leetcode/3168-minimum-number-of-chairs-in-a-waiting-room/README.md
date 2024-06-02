<h2><a href="https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/">3168. Minimum Number of Chairs in a Waiting Room</a></h2><h3>Easy</h3><hr><div><p>You are given a string <code>s</code>. Simulate events at each second <code>i</code>:</p>

<ul>
	<li>If <code>s[i] == 'E'</code>, a person enters the waiting room and takes one of the chairs in it.</li>
	<li>If <code>s[i] == 'L'</code>, a person leaves the waiting room, freeing up a chair.</li>
</ul>

<p>Return the <strong>minimum </strong>number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially <strong>empty</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "EEEEEEE"</span></p>

<p><strong>Output:</strong> <span class="example-io">7</span></p>

<p><strong>Explanation:</strong></p>

<p>After each second, a person enters the waiting room and no person leaves it. Therefore, a minimum of 7 chairs is needed.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "ELELEEL"</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<p>Let's consider that there are 2 chairs in the waiting room. The table below shows the state of the waiting room at each second.</p>
</div>

<table>
	<tbody>
		<tr>
			<th>Second</th>
			<th>Event</th>
			<th>People in the Waiting Room</th>
			<th>Available Chairs</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Leave</td>
			<td>0</td>
			<td>2</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Enter</td>
			<td>1</td>
			<td>1</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>0</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Leave</td>
			<td>1</td>
			<td>1</td>
		</tr>
	</tbody>
</table>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = "ELEELEELLL"</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>Let's consider that there are 3 chairs in the waiting room. The table below shows the state of the waiting room at each second.</p>
</div>

<table>
	<tbody>
		<tr>
			<th>Second</th>
			<th>Event</th>
			<th>People in the Waiting Room</th>
			<th>Available Chairs</th>
		</tr>
		<tr>
			<td>0</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Enter</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>5</td>
			<td>Enter</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>6</td>
			<td>Enter</td>
			<td>3</td>
			<td>0</td>
		</tr>
		<tr>
			<td>7</td>
			<td>Leave</td>
			<td>2</td>
			<td>1</td>
		</tr>
		<tr>
			<td>8</td>
			<td>Leave</td>
			<td>1</td>
			<td>2</td>
		</tr>
		<tr>
			<td>9</td>
			<td>Leave</td>
			<td>0</td>
			<td>3</td>
		</tr>
	</tbody>
</table>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>s</code> consists only of the letters <code>'E'</code> and <code>'L'</code>.</li>
	<li><code>s</code> represents a valid sequence of entries and exits.</li>
</ul>
</div>