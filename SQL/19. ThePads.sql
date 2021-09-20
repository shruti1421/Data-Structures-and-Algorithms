-- https://www.hackerrank.com/challenges/the-pads/problem
/*The syntax is ‘CONCAT(str1, str2, …)’ and it returns the string that results from concatenating the arguments.
And we can use SUBSTR() or LEFT() function to get first letter of Occupation. Syntax of SUBSTR() I use here is ‘SUBSTR(str, pos, len)’ and it returns a substring len characters long from string str, starting at position pos. Syntax of LEFT() is ‘LEFT(str, len)’ and it returns the leftmost len characters from the string str, or NULL if any argument is NULL.
Additionally,

    from OCCUPATIONS table ==> FROM OCCUPATIONS
    alphabetically ordered list of names ==> ORDER BY Name
    occupation_count ==> COUNT(Occupation) … GROUP BY Occupation
    lowercase occupation name ==> LOWER(Occupation)
    sort occurrences in ascending order ==> ORDER BY COUNT(Occupation)
    order alphabetically if having the same occupation_count ==>
    ORDER BY COUNT(Occupation), Occupation
*/
/*
Enter your query here.
*/
select concat(name,'(',substr(occupation,1,1),')') 
from occupations
order by name;

select concat('There are a total of ',count(occupation), ' ', lower(occupation), 's.')
from occupations
group by occupation
order by count(occupation),occupation;