# Write your MySQL query statement below

select Employee.name, Bonus.bonus from Employee
left join Bonus on Employee.empId = Bonus.empId
where Bonus.bonus < 1000 or Bonus.bonus is NULL;
