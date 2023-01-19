# Write your MySQL query statement below
# select customer_id, count(visit_id) as count_no_trans from Visits 
# where visit_id not in (select visit_id from Transactions)
# group by customer_id;


select v.customer_id, count(v.visit_id) as count_no_trans 
from Visits v
left join Transactions t on v.visit_id = t.visit_id
where t.visit_id is NULL
group by customer_id;