# Write your MySQL query statement below

# select name from SalesPerson where sales_id not in
# (select sales_id from Orders where com_id in 
# (select com_id from Company where name = 'RED'))


select salesperson.name
from orders o join company c on (o.com_id = c.com_id and c.name = 'RED')
right join salesperson on salesperson.sales_id = o.sales_id
where o.sales_id is null


# Runtime: 1581 ms, faster than 43.68% of MySQL online submissions for Sales Person.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Sales Person.

# select name from SalesPerson where sales_id NOT IN
#   ( select sales_id from orders where com_id IN
#     ( select com_id from company as c where c.name = "RED") 
#   group by sales_id)
  
  
# Runtime: 1242 ms, faster than 68.56% of MySQL online submissions for Sales Person.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Sales Person.
# select name from SalesPerson where sales_id NOT IN (
#   select sales_id from orders o LEFT JOIN company c ON 
#   o.com_id = c.com_id WHERE c.name = "RED"
# );