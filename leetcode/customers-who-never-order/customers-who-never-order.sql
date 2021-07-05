# Write your MySQL query statement below
select Customers.Name as Customers from Customers where Customers.Id not in (Select CustomerId from Orders);