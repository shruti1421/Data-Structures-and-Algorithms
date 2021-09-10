/*
https://www.hackerrank.com/challenges/revising-the-select-query-2/problem
*/
select NAME
from CITY
where
    POPULATION>120000
    and
    COUNTRYCODE='USA';