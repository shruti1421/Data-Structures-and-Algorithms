-- https://www.hackerrank.com/challenges/symmetric-pairs/problem
-- IMP
/*
The INNER JOIN keyword selects records that have matching values in both tables.
INNER JOIN Syntax
SELECT column_name(s)
FROM table1
INNER JOIN table2
ON table1.column_name = table2.column_name;

https://www.w3schools.com/sql/sql_join_inner.asp

The SQL GROUP BY Statement

The GROUP BY statement groups rows that have the same values into summary rows, like "find the number of customers in each country".

The GROUP BY statement is often used with aggregate functions (COUNT(), MAX(), MIN(), SUM(), AVG()) to group the result-set by one or more columns.

GROUP BY Syntax
SELECT column_name(s)
FROM table_name
WHERE condition
GROUP BY column_name(s)
ORDER BY column_name(s); 

https://www.w3schools.com/sql/sql_groupby.asp
*/

select f1.x, f1.y 
from functions f1
inner join functions f2
on 
    f1.x=f2.y and f1.y=f2.x
group by f1.x,f1.y
having count(f1.x)>1 or f1.x<f1.y
order by f1.x;

-- The criteria in the having clause allows us to prevent duplication in our output while still achieving our goal of finding mirrored pairs. We have to treat our pairs where f1.x = f1.y and f1.x <> f1.y differently to capture both. The first criteria handles pairs where f1.x = f1.y and the 2nd criteria handles pairs where f1.x <> f1.y, which is why the or operator is used.

-- The first part captures records where f1.x = f1.y. The 'count(f1.x) > 1' requires there to be at least two records of a mirrored pair to be pulled through. Without this a pair would simply match with itself (since it's already it's own mirrored pair) and be pulled through incorrectly when you join the table on itself.

-- The 2nd part matches the remaining mirrored pairs. It's important to note that for this challenge, the mirrored match of (f1.x,f1.y) is considered a duplicate and excluded from the final output. You can see this in the sample output where (20, 21) is outputted, but not (21,20). The 'or f1.x < f1.y' criteria allows us to pull all those pairs where f1.x does not equal f1.y, but where f1.x is also less than f1.y so we don't end up with the mirrored paired duplicate.