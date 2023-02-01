# Write your MySQL query statement below

select d.name as Department,
       e.name as Employee,
       salary as Salary
from Employee e join Department d
       on e.departmentId = d.id
where (departmentId, salary) in (
    select departmentId, max(salary) from Employee
    group by departmentId
)
;