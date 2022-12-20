# Write your MySQL query statement below
SELECT person_id, CONCAT(name, "(",substr(profession,1,1),")") as name FROM Person
Order by person_id desc