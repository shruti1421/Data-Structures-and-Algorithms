/*
https://www.hackerrank.com/challenges/revising-the-select-query/problem
For this challenge, we must:

    Select all columns using the all-column wildcard (*).
    Restrict the selected rows using the WHERE clause so that only records satisfying both of the following two conditions are returned:
        COUNTRYCODE is USA, meaning the cities are American.
        POPULATION is greater than 100000.
*/
Select * 
from CITY 
where 
    COUNTRYCODE='USA' 
    and 
    POPULATION>100000;