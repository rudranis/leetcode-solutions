# Write your MySQL query statement below
select s.student_id ,s.student_name,e.subject_name , count(ee.subject_name) as attended_exams
from students s
cross join subjects e
left join examinations ee
on s.student_id=ee.student_id 
and ee.subject_name =e.subject_name
group by s.student_id,s.student_name , e.subject_name
order by s.student_id ,s.student_name
