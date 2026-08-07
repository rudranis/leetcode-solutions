# Write your MySQL query statement below
SELECT DISTINCT num AS ConsecutiveNums
FROM
(
SELECT *,
LAG(num,1) OVER() prev1,
LAG(num,2) OVER() prev2
FROM Logs
)t
WHERE num=prev1
AND num=prev2;