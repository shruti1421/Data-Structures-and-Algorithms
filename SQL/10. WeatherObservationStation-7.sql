-- https://www.hackerrank.com/challenges/weather-observation-station-7/problem
/*
Enter your query here.
*/
select distinct(city)
from station
where 
    city regexp '[aeiou]$';
-- $    End of string