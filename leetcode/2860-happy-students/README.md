<h2><a href="https://leetcode.com/problems/happy-students/">2860. Happy Students</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>0-indexed</strong> integer array <code>nums</code> of length <code>n</code> where <code>n</code> is the total number of students in the class. The class teacher tries to select a group of students so that all the students remain happy.</p>

<p>The <code>i<sup>th</sup></code> student will become happy if one of these two conditions is met:</p>

<ul>
	<li>The student is selected and the total number of selected students is<strong> strictly greater than</strong> <code>nums[i]</code>.</li>
	<li>The student is not selected and the total number of selected students is <strong>strictly</strong> <strong>less than</strong> <code>nums[i]</code>.</li>
</ul>

<p>Return <em>the number of ways to select a group of students so that everyone remains happy.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 
The two possible ways are:
The class teacher selects no student.
The class teacher selects both students to form the group. 
If the class teacher selects just one student to form a group then the both students will not be happy. Therefore, there are only two possible ways.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [6,0,3,3,6,7,2,7]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 
The three possible ways are:
The class teacher selects the student with index = 1 to form the group.
The class teacher selects the students with index = 1, 2, 3, 6 to form the group.
The class teacher selects all the students to form the group.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt; nums.length</code></li>
</ul>
</div>