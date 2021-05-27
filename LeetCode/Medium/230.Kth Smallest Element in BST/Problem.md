Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

 ![image](https://user-images.githubusercontent.com/64346825/119887236-80daa100-bf51-11eb-8782-899516a211e1.png)


Example 1:

Input: root = [3,1,4,null,2], k = 1
Output: 1

![image](https://user-images.githubusercontent.com/64346825/119887269-8c2dcc80-bf51-11eb-9314-cf83b1e41fa1.png)


Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3

 

Constraints:

    The number of nodes in the tree is n.
    1 <= k <= n <= 104
    0 <= Node.val <= 104

 
Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
