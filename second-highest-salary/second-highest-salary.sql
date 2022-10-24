# Write your MySQL query statement below

select max(salary) as SecondHighestSalary from Employee where Salary 
not in (select max(Salary) from Employee);