<h2><a href="https://leetcode.com/problems/find-products-with-valid-serial-numbers">3803. Find Products with Valid Serial Numbers</a></h2><h3>Easy</h3><hr><p>Table: <code>products</code></p>

<pre>
+--------------+------------+
| Column Name  | Type       |
+--------------+------------+
| product_id   | int        |
| product_name | varchar    |
| description  | varchar    |
+--------------+------------+
(product_id) is the unique key for this table.
Each row in the table represents a product with its unique ID, name, and description.
</pre>

<p>Write a solution to find all products whose description <strong>contains a valid serial number</strong> pattern. A valid serial number follows these rules:</p>

<ul>
	<li>It starts with the letters <strong>SN</strong>&nbsp;(case-sensitive).</li>
	<li>Followed by exactly <code>4</code> digits.</li>
	<li>It must have a hyphen (-) <strong>followed by exactly</strong> <code>4</code> digits.</li>
	<li>The serial number must be within the description (it may not necessarily start at the beginning).</li>
</ul>

<p>Return <em>the result table&nbsp;ordered by</em> <code>product_id</code> <em>in <strong>ascending</strong> order</em>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example:</strong></p>

<div class="example-block">
<p><strong>Input:</strong></p>

<p>products table:</p>

<pre class="example-io">
+------------+--------------+------------------------------------------------------+
| product_id | product_name | description                                          |
+------------+--------------+------------------------------------------------------+
| 1          | Widget A     | This is a sample product with SN1234-5678            |
| 2          | Widget B     | A product with serial SN9876-1234 in the description |
| 3          | Widget C     | Product SN1234-56789 is available now                |
| 4          | Widget D     | No serial number here                                |
| 5          | Widget E     | Check out SN4321-8765 in this description            |
+------------+--------------+------------------------------------------------------+
    </pre>

<p><strong>Output:</strong></p>

<pre class="example-io">
+------------+--------------+------------------------------------------------------+
| product_id | product_name | description                                          |
+------------+--------------+------------------------------------------------------+
| 1          | Widget A     | This is a sample product with SN1234-5678            |
| 2          | Widget B     | A product with serial SN9876-1234 in the description |
| 5          | Widget E     | Check out SN4321-8765 in this description            |
+------------+--------------+------------------------------------------------------+
    </pre>

<p><strong>Explanation:</strong></p>

<ul>
	<li><strong>Product 1:</strong> Valid serial number SN1234-5678</li>
	<li><strong>Product 2:</strong> Valid serial number SN9876-1234</li>
	<li><strong>Product 3:</strong> Invalid serial number SN1234-56789 (contains 5 digits after the hyphen)</li>
	<li><strong>Product 4:</strong> No serial number in the description</li>
	<li><strong>Product 5:</strong> Valid serial number SN4321-8765</li>
</ul>

<p>The result table is ordered by product_id in ascending order.</p>
</div>
