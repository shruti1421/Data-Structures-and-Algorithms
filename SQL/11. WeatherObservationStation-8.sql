-- https://www.hackerrank.com/challenges/weather-observation-station-8/problem
/*
Enter your query here.
*/
select distinct(city)
from station
where 
    city regexp '^[aeiou]' and city regexp '[aeiou]$';