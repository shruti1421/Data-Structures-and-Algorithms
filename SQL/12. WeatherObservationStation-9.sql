-- https://www.hackerrank.com/challenges/weather-observation-station-9/problem
/*
Enter your query here.
*/
select distinct(city)
from station
where 
    city regexp '^[^aeiou]';
--  ^        caret(^) matches Beginning of string
-- [^abc]    Any character not listed between the square brackets