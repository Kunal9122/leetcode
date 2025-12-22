# Write your MySQL query statement below
select max(T.salary) as SecondHighestSalary from
(select salary from Employee where salary not in
(select max(salary) as max from Employee)) as T