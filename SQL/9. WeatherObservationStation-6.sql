-- https://www.hackerrank.com/challenges/weather-observation-station-6/problem
/*
Enter your query here.
*/
select city
from station
where 
    city regexp '^[aeiou]';
-- https://www.geeksforgeeks.org/mysql-regular-expressions-regexp/