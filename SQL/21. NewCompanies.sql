-- https://www.hackerrank.com/challenges/the-company/problem
/*
Enter your query here.
*/
select c.company_code, c.founder, count(distinct l.lead_manager_code), count(distinct s.senior_manager_code), count(distinct m.manager_code), count(distinct e.employee_code)
from company c join lead_manager l on c.company_code=l.company_code
join senior_manager s on l.lead_manager_code=s.lead_manager_code
join manager m on s.senior_manager_code=m.senior_manager_code
join employee e on m.manager_code=e.manager_code
group by c.company_code, c.founder 
order by c.company_code;