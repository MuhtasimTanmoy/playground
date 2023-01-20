# Write your MySQL query statement below
# select distinct p.product_id, p.product_name 
# from Product p right join Sales s on p.product_id = s.product_id
# where sale_date > "2019-01-01" and not (sale_date  > "2019-03-31")

SELECT s.product_id, product_name
FROM Sales s
LEFT JOIN Product p
ON s.product_id = p.product_id
GROUP BY s.product_id
HAVING MIN(sale_date) >= CAST('2019-01-01' AS DATE) AND
       MAX(sale_date) <= CAST('2019-03-31' AS DATE)