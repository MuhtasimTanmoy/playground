# Write your MySQL query statement below

select E.Name as Employee from Employee as E left join Employee as M 
on E.ManagerId = M.Id 
where E.Salary > M.Salary