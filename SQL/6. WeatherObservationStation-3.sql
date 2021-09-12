-- https://www.hackerrank.com/challenges/weather-observation-station-3/problem
select distinct(city)
from station
where
    id%2=0;

/*
For Oracle
select distinct(city)
from station
where
    mod(id,2)=0;
*/