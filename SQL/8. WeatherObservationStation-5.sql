-- //https://www.hackerrank.com/challenges/weather-observation-station-5/problem
/*
Enter your query here.
*/
select city,length(city)
from station
order by length(city), city --sort cities in ascending order and if length same=>alphabetical
limit 1;  
-- LIMIT clause to select a limited number of records

select city,length(city)
from station
order by length(city) desc, city
limit 1;