//https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
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

int maxSum(Node* root, unordered_map<Node*, int>&mp)
{

        if (root == NULL)
                return 0;

        if (mp.find(root) != mp.end())
                return mp[root];

        int sum1 = maxSum(root->left, mp) + maxSum(root->right, mp);

        int sum2 = root->data;

        if (root->left)
                sum2 += maxSum(root->left->left, mp) + maxSum(root->left->right, mp);

        if (root->right)
                sum2 += maxSum(root->right->left, mp) + maxSum(root->right->right, mp);

        return mp[root] = max(sum1, sum2);
}

int main()
{
        unordered_map<Node*, int> mp;

        Node* root = newNode(4);
        root->left = newNode(2);
        root->right = newNode(6);
        root->right->left = newNode(5);
        root->left->right = newNode(1);
        root->left->left = newNode(3);

        cout << maxSum(root, mp) << "\n";

        return 0;
}