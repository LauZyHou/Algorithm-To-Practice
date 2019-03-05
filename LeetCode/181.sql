# Write your MySQL query statement below
select Name Employee from Employee AS a
where Salary > (
    select Salary from Employee AS b
    where Id = a.ManagerId)