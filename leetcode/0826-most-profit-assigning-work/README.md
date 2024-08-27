<h2><a href="https://leetcode.com/problems/most-profit-assigning-work/">826. Most Profit Assigning Work</a></h2><h3>Medium</h3><hr><div><p>You have <code>n</code> jobs and <code>m</code> workers. You are given three arrays: <code>difficulty</code>, <code>profit</code>, and <code>worker</code> where:</p>

<ul>
	<li><code>difficulty[i]</code> and <code>profit[i]</code> are the difficulty and the profit of the <code>i<sup>th</sup></code> job, and</li>
	<li><code>worker[j]</code> is the ability of <code>j<sup>th</sup></code> worker (i.e., the <code>j<sup>th</sup></code> worker can only complete a job with difficulty at most <code>worker[j]</code>).</li>
</ul>

<p>Every worker can be assigned <strong>at most one job</strong>, but one job can be <strong>completed multiple times</strong>.</p>

<ul>
	<li>For example, if three workers attempt the same job that pays <code>$1</code>, then the total profit will be <code>$3</code>. If a worker cannot complete any job, their profit is <code>$0</code>.</li>
</ul>

<p>Return the maximum profit we can achieve after assigning the workers to the jobs.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker = [4,5,6,7]
<strong>Output:</strong> 100
<strong>Explanation:</strong> Workers are assigned jobs of difficulty [4,4,6,6] and they get a profit of [20,20,30,30] separately.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre class="" style="position: relative;"><strong>Input:</strong> difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
<strong>Output:</strong> 0
<button class="lazy-felix lazy-felix-download-btn" data-name="[85,47,57]"><svg xmlns="http://www.w3.org/2000/svg" class="lazyfelix-icon" width="27" height="25" viewBox="0 0 27 25" fill="none">    <path d="M13.4518 13.0377C11.4186 12.7365 6.4864 16.878 5.39453 21.7726V22.0362C5.48795 24.1899 7.75902 24.9194 10.9292 24.0316C13.0111 23.1639 14.1728 23.1375 16.125 24.0316C17.9698 25.1612 20.41 23.7051 20.643 22.0362C20.3191 18.4517 16.3154 13.1956 13.4518 13.0377Z" fill="#7A7A7A" fill-opacity="0.7"></path>    <ellipse cx="4.85476" cy="11.946" rx="2.97265" ry="4.24369" transform="rotate(-21.5283 4.85476 11.946)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="22.0599" cy="13.5489" rx="2.97265" ry="4.24369" transform="rotate(22.9527 22.0599 13.5489)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="10.1354" cy="5.66514" rx="2.92739" ry="4.7215" transform="rotate(-9.76985 10.1354 5.66514)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="17.552" cy="5.95842" rx="2.92739" ry="4.7215" transform="rotate(14.6303 17.552 5.95842)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>
  </svg></button><button class="lazy-felix lazy-felix-download-btn" data-name="[24,66,99]"><svg xmlns="http://www.w3.org/2000/svg" class="lazyfelix-icon" width="27" height="25" viewBox="0 0 27 25" fill="none">    <path d="M13.4518 13.0377C11.4186 12.7365 6.4864 16.878 5.39453 21.7726V22.0362C5.48795 24.1899 7.75902 24.9194 10.9292 24.0316C13.0111 23.1639 14.1728 23.1375 16.125 24.0316C17.9698 25.1612 20.41 23.7051 20.643 22.0362C20.3191 18.4517 16.3154 13.1956 13.4518 13.0377Z" fill="#7A7A7A" fill-opacity="0.7"></path>    <ellipse cx="4.85476" cy="11.946" rx="2.97265" ry="4.24369" transform="rotate(-21.5283 4.85476 11.946)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="22.0599" cy="13.5489" rx="2.97265" ry="4.24369" transform="rotate(22.9527 22.0599 13.5489)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="10.1354" cy="5.66514" rx="2.92739" ry="4.7215" transform="rotate(-9.76985 10.1354 5.66514)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="17.552" cy="5.95842" rx="2.92739" ry="4.7215" transform="rotate(14.6303 17.552 5.95842)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>
  </svg></button><button class="lazy-felix lazy-felix-download-btn" data-name="[40,25,25]"><svg xmlns="http://www.w3.org/2000/svg" class="lazyfelix-icon" width="27" height="25" viewBox="0 0 27 25" fill="none">    <path d="M13.4518 13.0377C11.4186 12.7365 6.4864 16.878 5.39453 21.7726V22.0362C5.48795 24.1899 7.75902 24.9194 10.9292 24.0316C13.0111 23.1639 14.1728 23.1375 16.125 24.0316C17.9698 25.1612 20.41 23.7051 20.643 22.0362C20.3191 18.4517 16.3154 13.1956 13.4518 13.0377Z" fill="#7A7A7A" fill-opacity="0.7"></path>    <ellipse cx="4.85476" cy="11.946" rx="2.97265" ry="4.24369" transform="rotate(-21.5283 4.85476 11.946)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="22.0599" cy="13.5489" rx="2.97265" ry="4.24369" transform="rotate(22.9527 22.0599 13.5489)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="10.1354" cy="5.66514" rx="2.92739" ry="4.7215" transform="rotate(-9.76985 10.1354 5.66514)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>    <ellipse cx="17.552" cy="5.95842" rx="2.92739" ry="4.7215" transform="rotate(14.6303 17.552 5.95842)" fill="#7A7A7A" fill-opacity="0.7"></ellipse>
  </svg></button></pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == difficulty.length</code></li>
	<li><code>n == profit.length</code></li>
	<li><code>m == worker.length</code></li>
	<li><code>1 &lt;= n, m &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= difficulty[i], profit[i], worker[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>