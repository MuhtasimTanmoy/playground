# Write your MySQL query statement below

select id, count(*) num from 
(
      (select requester_id id from RequestAccepted) 
      union all 
      (select accepter_id id from RequestAccepted)
) tb 
group by id order by num desc limit 1