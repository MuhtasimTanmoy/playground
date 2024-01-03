<h2><a href="https://leetcode.com/problems/bikes-last-time-used/">2687. Bikes Last Time Used </a></h2><h3>Easy</h3><hr><div class="sql-schema-wrapper__3VBi"><a class="sql-schema-link__3cEg">SQL Schema<svg viewBox="0 0 24 24" width="1em" height="1em" class="icon__1Md2"><path fill-rule="evenodd" d="M10 6L8.59 7.41 13.17 12l-4.58 4.59L10 18l6-6z"></path></svg></a></div><div><p>Table: <code><font face="monospace">Bikes</font></code></p>

<pre>+-------------+----------+ 
| Column Name | Type     | 
+-------------+----------+ 
| ride_id     | int      | 
| bike_number | int      | 
| start_time  | datetime |
| end_time    | datetime |
+-------------+----------+
ride_id is the primary key for this table.
Each row contains a ride information that includes ride_id, bike number, start and end time of the ride.
</pre>

<p>Write an SQL query to find the <strong>last</strong> <strong>time</strong> when each bike was used.</p>

<p>Return<em> the result table ordered by the bikes that were <strong>most recently used</strong>.&nbsp;</em></p>

<p>The query result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:
</strong><code>Bikes</code> table:
+---------+-------------+---------------------+---------------------+ 
| ride_id | bike_number | start_time          | end_time            |  
+---------+-------------+---------------------+---------------------+
| 1       | W00576      | 2012-03-25 11:30:00 | 2012-03-25 12:40:00 |
| 2       | W00300      | 2012-03-25 10:30:00 | 2012-03-25 10:50:00 |
| 3       | W00455      | 2012-03-26 14:30:00 | 2012-03-26 17:40:00 |
| 4       | W00455      | 2012-03-25 12:30:00 | 2012-03-25 13:40:00 |
| 5       | W00576      | 2012-03-25 08:10:00 | 2012-03-25 09:10:00 |
| 6       | W00576      | 2012-03-28 02:30:00 | 2012-03-28 02:50:00 |
+---------+-------------+---------------------+---------------------+ 

<strong>Output:</strong>
+-------------+---------------------+ 
| bike_number | end_time            |  
+-------------+---------------------+
| W00576      | 2012-03-28 02:50:00 |
| W00455      | 2012-03-26 17:40:00 |
| W00300      | 2012-03-25 10:50:00 |
+-------------+---------------------+ 
<strong>Explanation:</strong> 
bike with number W00576 has three rides, out of that, most recent ride is with ride_id 6 which ended on 2012-03-28 02:50:00.
bike with number W00300 has only 1 ride so we will include end_time in output directly. 
bike with number W00455 has two rides, out of that, most recent ride is with ride_id 3 which ended on 2012-03-26 17:40:00. 
Returning output in order by the bike that were most recently used.
</pre>

<p>&nbsp;</p>
</div>