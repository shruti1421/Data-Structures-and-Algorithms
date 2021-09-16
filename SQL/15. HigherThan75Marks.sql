-- https://www.hackerrank.com/challenges/more-than-75-marks/problem
/*
Enter your query here.
*/
select name 
from students
where
    marks > 75
order by right(name,3),id;

-- RIGHT() function in MySQL is used to extract a specified number of characters from the right side of a given string. Second argument is used to decide, how many characters it should return.

-- Syntax :

-- RIGHT( str, len )

-- Parameter : This function accepts two parameter as mentioned above and described below :

--     str : The given string from whose right side a number of characters are to be extracted.
--     len : The number of characters to extract. If this parameter is larger than the number of characters in string, this function will return the actual string.