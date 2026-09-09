
# Write your MySQL query statement below
select  id ,count(*) as num
from( 
   SELECT requester_id AS id, accepter_id AS friend_id FROM requestaccepted
    UNION ALL
    SELECT accepter_id AS id, requester_id AS friend_id FROM requestaccepted
) as all_friends
group by id 
order by num desc 
limit 1