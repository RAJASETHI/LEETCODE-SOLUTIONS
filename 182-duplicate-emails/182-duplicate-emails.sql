# Write your MySQL query statement below
select distinct e1.email from Person e1 join Person e2 on e1.id!=e2.id and e1.email=e2.email