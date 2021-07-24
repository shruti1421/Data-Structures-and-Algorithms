//Full Concept: https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
//O(height of tree)=O(logn)

#include<bits/stdc++.h>
using namespace std;



class Node {
public:
        int key;
        Node *left;
        Node *right;
        int height;
};

Node * newNode(int key)
{
        Node *node = new Node();

        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;

        return node;
}

int height(Node *node)
{
        if (node == NULL)
                return 0;
        else return node->height;
}

int getBalance(Node *node)
{
        return height(node->left) - height(node->right);
}

Node *rightRotation(Node *x)
{
        Node *y = x->left;
        Node *t = y->right;

        y->right = x;
        x->left = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
}

Node *leftRotation(Node *x)
{
        Node *y = x->right;
        Node *t = y->left;

        y->left = x;
        x->right = t;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
}

Node *maxValue(Node *node)
{
        while (node->right != NULL)
                node = node->right;

        return node;
}

Node *deleteNode(Node *node, int key)
{
        if (node == NULL)
                return node;
        else if (key < node->key)
                node->left = deleteNode(node->left, key);
        else if (key > node->key)
                node->right = deleteNode(node->right, key);
        else {
                if (node->left == NULL || node->right == NULL)
                {
                        Node *temp;
                        if (node->left == NULL && node->right == NULL)
                        {
                                temp = node;
                                node = NULL;
                        }
                        else
                        {
                                temp = (node->left) ? node->left : node->right;
                                *node = *temp;
                        }
                        free(temp);
                }
                else
                {
                        Node *temp = maxValue(node->left);

                        node->key = temp->key;
                        node->left = deleteNode(node->left, temp->key);

                        free(temp);
                }
        }

        if (node == NULL)
                return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);


        if (balance > 1 && getBalance(node->left) >= 0)
                return rightRotation(node);
        if (balance > 1 && getBalance(node->left) < 0)
        {
                node->left = leftRotation(node->left);
                return rightRotation(node);
        }
        if (balance < -1 && getBalance(node->right) >= 0)
                return leftRotation(node);
        if (balance < -1 && getBalance(node->right) < 0)
        {
                node->right = rightRotation(node->right);
                return leftRotation(node);
        }


        return node;
}

Node *insert(Node *node, int key)
{
        if (node == NULL)
                return (newNode(key));
        else if (key < node->key)
                node->left = insert(node->left, key);
        else if (key > node->key)
                node->right = insert(node->right, key);
        else return node;

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key < node->left->key)
                return rightRotation(node);
        if (balance > 1 && key > node->left->key)
        {
                node->left = leftRotation(node->left);
                return rightRotation(node);
        }
        if (balance < -1 && key > node->right->key)
                return leftRotation(node);
        if (balance < -1 && key < node->right->key)
        {
                node->right = rightRotation(node->right);
                return leftRotation(node);
        }





        return node;
}

void preOrder(Node *root)
{
        if (root != NULL)
        {
                cout << root->key << " ";
                preOrder(root->left);
                preOrder(root->right);
        }
}

int main()
{
        Node *root;

        root = NULL;

        root = insert(root, 9);
        root = insert(root, 5);
        root = insert(root, 10);
        root = insert(root, 0);
        root = insert(root, 6);
        root = insert(root, 11);
        root = insert(root, -1);
        root = insert(root, 1);
        root = insert(root, 2);

        preOrder(root);

        root = deleteNode(root, 10);

        cout << "\n";

        preOrder(root);

        return 0;

}