# Write your MySQL query statement below

# select employee_id from Employees full outer join Salaries on employee_id where name is NULL or salary is NULL;

SELECT employee_id from Employees e WHERE employee_id not in (Select employee_id from Salaries)
UNION 
SELECT employee_id from Salaries s WHERE employee_id not in (Select employee_id from Employees)
ORDER BY employee_id;