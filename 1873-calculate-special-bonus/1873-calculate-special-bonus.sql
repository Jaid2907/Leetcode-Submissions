# Write your MySQL query statement below
select employee_id, (IF(employee_id %2 != 0 and name not like 'M%', salary,0)) as bonus from Employees order by employee_id;

# insert into Employees (bonus) values ;
# select employee_id, () from Employees order by employee_id;