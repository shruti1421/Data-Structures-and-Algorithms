-- https://www.hackerrank.com/challenges/weather-observation-station-10/problem
/*
Enter your query here.
*/
select distinct(city)
from station
where
    city regexp '[^aeiou]$';