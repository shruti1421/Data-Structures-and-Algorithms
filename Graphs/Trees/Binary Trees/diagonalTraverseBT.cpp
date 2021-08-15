//https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
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

void TraverseDiagonal(Node* root)
{
        Node* node = root;

        deque<Node*> leftQ;

        leftQ.push_back(root);

        vector<vector<int>> result;

        while (!leftQ.empty())
        {
                int size = leftQ.size();

                vector<int> ans;

                while (size--)
                {
                        Node* temp = leftQ.front();
                        leftQ.pop_front();

                        while (temp != NULL)
                        {
                                ans.push_back(temp->data);

                                if (temp->left != NULL)
                                        leftQ.push_back(temp->left);

                                temp = temp->right;
                        }

                }

                result.push_back(ans);
        }


        for (int i = 0; i < result.size(); i++)
        {
                for (int j = 0; j < result[i].size(); j++)
                {
                        cout << result[i][j] << " ";
                }

                cout << "\n";
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


        TraverseDiagonal(root);

        return 0;
}