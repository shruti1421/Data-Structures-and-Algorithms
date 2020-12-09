Given a string, print all permutations of it.

Input : str = "ABC"
Output : ABC ACB BAC BCA CAB CBA

Idea: We iterate from first to last index. For every index i, we swap the i-th character with the first index. This is how we fix characters at the current first index, then we recursively generate all permutations beginning with fixed characters (by parent recursive calls). After we have recursively generated all permutations with the first character fixed, then we move the first character back to its original position so that we can get the original string back and fix the next character at first position.

Illustration: We swap 'A' with 'A'. Then we recursively generate all permutations beginning with A. While returning from the recursive calls, we revert the changes made by them using the same swap again. So we get the original string "ABC".
Then we swap 'A' with 'B' and generate all permutations beginning with 'B'.
Similarly, we generate all permutations beginning with 'C'

![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif)
