# Write your MySQL query statement below
SELECT MAX(salary) As SecondHighestSalary From Employee Where 
salary < (select Max(salary) from Employee);