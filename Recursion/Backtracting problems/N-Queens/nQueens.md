Backtracking:

So, while solving a problem using recursion, we break the given problem into smaller ones. Let's say we have a problem  and we divided it into three smaller problems ,  and . Now it may be the case that the solution to  does not depend on all the three subproblems, in fact we don't even know on which one it depends.
Let's take a situation. Suppose you are standing in front of three tunnels, one of which is having a bag of gold at its end, but you don't know which one. So you'll try all three. First go in tunnel , if that is not the one, then come out of it, and go into tunnel , and again if that is not the one, come out of it and go into tunnel . So basically in backtracking we attempt solving a subproblem, and if we don't reach the desired solution, then undo whatever we did for solving that subproblem, and try solving another subproblem.

Let's take a standard problem.
N-Queens Problem: Given a chess board having NxN cells, we need to place N queens in such a way that no queen is attacked by any other queen. A queen can attack horizontally, vertically and diagonally.

So initially we are having NxN unattacked cells where we need to place N queens. Let's place the first queen at a cell , so now the number of unattacked cells is reduced, and number of queens to be placed is . Place the next queen at some unattacked cell. This again reduces the number of unattacked cells and number of queens to be placed becomes . Continue doing this, as long as following conditions hold.

The number of unattacked cells is not .
The number of queens to be placed is not .
If the number of queens to be placed becomes , then it's over, we found a solution. But if the number of unattacked cells become , then we need to backtrack, i.e. remove the last placed queen from its current cell, and place it at some other cell. We do this recursively.

Given a chess board having NxN cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input:
The only line of input consists of a single integer denoting N.

Output:
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print "YES" (without quotes) in first line, then print N lines having N integers. The integer in  line and  column will denote the cell  of the board and should be 1 if a queen is placed at  otherwise 0. If there are more than way of placing queens print any of them.

If it is not possible to place all N queens in the desired way, then print "NO" (without quotes).

Constraints:
1<=N<=10.

https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/tutorial/
