//Using map and level order traversal
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

void verticalOrder(Node* root)
{
        vector<int> pw[100001], nw[100001];

        deque<pair<int, Node*>> q;

        q.push_back({0, root});

        int mini = INT_MAX, maxi = INT_MIN;

        while (!q.empty())
        {
                Node *temp = q.front().second;
                int w = q.front().first;
                q.pop_front();

                mini = min(w, mini);
                maxi = max(w, maxi);

                if (w >= 0)
                {
                        pw[w].push_back(temp->data);
                }
                else
                {
                        int x = abs(w);
                        nw[x].push_back(temp->data);
                }


                if (temp->left != NULL)
                        q.push_back({w - 1, temp->left});

                if (temp->right != NULL)
                        q.push_back({w + 1, temp->right});
        }

        mini = abs(mini);

        for (int i = mini; i > 0; i--)
        {
                if (nw[i].size() > 0)
                {
                        for (int j = 0; j < nw[i].size(); j++)
                                cout << nw[i][j] << " ";
                        cout << "\n";
                }


        }

        for (int i = 0; i <= maxi; i++)
        {
                if (pw[i].size() > 0)
                {
                        for (int j = 0; j < pw[i].size(); j++)
                                cout << pw[i][j] << " ";
                        cout << "\n";
                }


        }
}

int main()
{
        Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->left->right = newNode(5);
        root->right->left = newNode(6);
        root->right->right = newNode(7);
        root->right->left->right = newNode(8);
        root->right->right->right = newNode(9);
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


        verticalOrder(root);

        return 0;
}