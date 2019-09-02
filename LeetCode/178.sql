# Write your MySQL query statement below
select
	A.score as score,
	(
		select count(distinct B.score)
		from Scores as B
		where B.score >= A.score
	) as rank
from Scores as A
order by A.score desc