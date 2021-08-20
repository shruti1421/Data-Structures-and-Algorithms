//Different method from https://www.techiedelight.com/inorder-tree-traversal-iterative-recursive/
#include<bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        Node *left;
        Node *right;
};

Node *newNode(int x)
{
        Node* temp = new Node;
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
}

void traverseInorder(Node* root)
{
        stack<pair<Node*, int>> s;

        if (root == NULL)
                return;

        s.push({root, 0});


        while (!s.empty() && s.top().first != NULL)
        {
                Node *temp = s.top().first;

                if (temp->left != NULL && s.top().second == 0)
                {
                        s.pop();
                        s.push({temp, 1});
                        s.push({temp->left, 0});

                }
                else
                {
                        s.pop();
                        cout << temp->data << " ";

                        if (temp->right != NULL)
                        {
                                s.push({temp->right, 0});
                        }
                }
        }

        cout << "\n";

}

int main()
{
        Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->right->left = newNode(5);
        root->right->right = newNode(6);
        root->right->left->left = newNode(7);
        root->right->left->right = newNode(8);

           /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

        traverseInorder(root);

        return 0;
}