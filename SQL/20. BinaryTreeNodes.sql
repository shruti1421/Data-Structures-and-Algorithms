-- https://www.hackerrank.com/challenges/binary-search-tree-1/problem

select n, if(P is null, 'Root', 
             if((select count(*) 
                 from BST where p=b.n)>0, 'Inner', 'Leaf')) 
from BST as b order by n;