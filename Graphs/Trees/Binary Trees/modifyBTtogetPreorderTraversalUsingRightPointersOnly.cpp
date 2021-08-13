//https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/
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

vector<Node*> PreOrder(Node *root)
{
        vector<Node*> ans;
        if (root == NULL)
                return ans;


        stack<Node*> s;

        s.push(root);

        while (!s.empty())
        {
                Node *temp = s.top();

                s.pop();
                ans.push_back(temp);

                if (temp->right != NULL)
                {
                        s.push(temp->right);
                }

                if (temp->left != NULL)
                {
                        s.push(temp->left);
                }
        }

        return ans;

}

void modify(Node* root)
{
        if (root == NULL)
                return;

        stack<Node*> s;
        Node* pre = NULL;

        s.push(root);

        while (!s.empty())
        {
                Node *temp = s.top();
                s.pop();

                if (temp->right != NULL)
                {
                        s.push(temp->right);
                }

                if (temp->left != NULL)
                {
                        s.push(temp->left);
                }

                if (pre != NULL)
                {
                        pre->right = temp;
                }

                pre = temp;
        }
}

void print(Node *root)
{
        if (root == NULL)
                return;

        while (root != NULL)
        {
                cout << root->data << " ";
                root = root->right;
        }
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


        modify(root);

        print(root);

        return 0;
}