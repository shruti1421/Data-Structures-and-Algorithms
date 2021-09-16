-- https://www.hackerrank.com/challenges/what-type-of-triangle/problem
/*
Enter your query here.
*/
select 
if(a+b>c and b+c>a and a+c>b,
  if(a=b and b=c,
     'Equilateral',
     if(a=b or b=c or c=a,
        'Isosceles','Scalene')
     ),
  'Not A Triangle'
  )
from triangles;

-- The syntax is ‘IF(condition, A, B)’. When condition is satisfied, it will execute A otherwise B.