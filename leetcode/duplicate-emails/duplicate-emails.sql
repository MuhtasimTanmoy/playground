# Write your MySQL query statement below

select Email from 
    ( select Email, count(Email) emailCount from Person group by Email) as T
where T.emailCount >= 2;