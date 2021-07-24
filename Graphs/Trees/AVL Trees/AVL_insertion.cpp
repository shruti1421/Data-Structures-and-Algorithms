//Full Concept: https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
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

Node *newNode(int key)
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
        else
                return node->height;
}

int getBalance(Node *node)
{
        if (node == NULL)
                return 0;
        else return height(node->left) - height(node->right);
}

Node *rightRotate(Node *x)
{
        Node *y = x->left;
        Node *t = y->right;

        y->right = x;
        x->left = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
}

Node *leftRotate(Node *x)
{
        Node *y = x->right;
        Node *t = y->left;

        y->left = x;
        x->right = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
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
                return rightRotate(node);
        if (balance < -1 && key > node->right->key)
                return leftRotate(node);
        if (balance > 1 && key > node->left->key)
        {
                node->left = leftRotate(node->left);
                return rightRotate(node);
        }
        if (balance < -1 && key < node->right->key)
        {
                node->right = rightRotate(node->right);
                return leftRotate(node);
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

int main() {
        Node *root;
        root = NULL;


        root = insert(root, 10);
        root = insert(root, 20);
        root = insert(root, 25);
        root = insert(root, 30);
        root = insert(root, 40);
        root = insert(root, 50);

        preOrder(root);

        return 0;
}

//Time Complexity: The rotation operations (left and right rotate) take constant time as only a few pointers are being changed there. Updating the height and getting the balance factor also takes constant time. So the time complexity of AVL insert remains same as BST insert which is O(h) where h is the height of the tree. Since AVL tree is balanced, the height is O(Logn). So time complexity of AVL insert is O(Logn).