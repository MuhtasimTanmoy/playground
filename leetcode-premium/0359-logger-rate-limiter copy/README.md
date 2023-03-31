<h2><a href="https://leetcode.com/problems/logger-rate-limiter/">359. Logger Rate Limiter</a></h2><h3>Easy</h3><hr><div><p>Design a logger system that receives a stream of messages along with their timestamps. Each <strong>unique</strong> message should only be printed <strong>at most every 10 seconds</strong> (i.e. a message printed at timestamp <code>t</code> will prevent other identical messages from being printed until timestamp <code>t + 10</code>).</p>

<p>All messages will come in chronological order. Several messages may arrive at the same timestamp.</p>

<p>Implement the <code>Logger</code> class:</p>

<ul>
	<li><code>Logger()</code> Initializes the <code>logger</code> object.</li>
	<li><code>bool shouldPrintMessage(int timestamp, string message)</code> Returns <code>true</code> if the <code>message</code> should be printed in the given <code>timestamp</code>, otherwise returns <code>false</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["Logger", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage", "shouldPrintMessage"]
[[], [1, "foo"], [2, "bar"], [3, "foo"], [8, "bar"], [10, "foo"], [11, "foo"]]
<strong>Output</strong>
[null, true, true, false, false, false, true]

<strong>Explanation</strong>
Logger logger = new Logger();
logger.shouldPrintMessage(1, "foo");  // return true, next allowed timestamp for "foo" is 1 + 10 = 11
logger.shouldPrintMessage(2, "bar");  // return true, next allowed timestamp for "bar" is 2 + 10 = 12
logger.shouldPrintMessage(3, "foo");  // 3 &lt; 11, return false
logger.shouldPrintMessage(8, "bar");  // 8 &lt; 12, return false
logger.shouldPrintMessage(10, "foo"); // 10 &lt; 11, return false
logger.shouldPrintMessage(11, "foo"); // 11 &gt;= 11, return true, next allowed timestamp for "foo" is 11 + 10 = 21
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= timestamp &lt;= 10<sup>9</sup></code></li>
	<li>Every <code>timestamp</code> will be passed in non-decreasing order (chronological order).</li>
	<li><code>1 &lt;= message.length &lt;= 30</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>shouldPrintMessage</code>.</li>
</ul>
</div>