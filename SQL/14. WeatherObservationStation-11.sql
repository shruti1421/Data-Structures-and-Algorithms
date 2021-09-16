-- https://www.hackerrank.com/challenges/weather-observation-station-11/problem
/*
Enter your query here.
*/
select distinct(city)
from station
where
    city regexp '^[^aeiou]' or city regexp '[^aeiou]$';