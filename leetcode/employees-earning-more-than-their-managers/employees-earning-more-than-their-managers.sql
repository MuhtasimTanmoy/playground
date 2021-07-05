# Write your MySQL query statement below

select E.Name as Employee from Employee as E left join Employee as M 
on E.ManagerId = M.Id 
where E.Salary > M.Salary

# Alternate approach

select name `Employee` from Employee e
where ManagerId is not null and
Salary > (select Salary from Employee where Id = e.ManagerId)
