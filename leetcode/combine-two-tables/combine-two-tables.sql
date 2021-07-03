# Write your MySQL query statement below

select FirstName, LastName, City, State from Person as P left join Address as A on P.PersonId = A.PersonId