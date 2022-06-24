# Write your MySQL query statement below
select e.name as Employee  from Employee as e inner join employee as f on e.managerid=f.id and e.salary>f.salary;