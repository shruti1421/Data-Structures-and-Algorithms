//https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
vector<int> verticalOrder(Node* root)
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
        
        vector<int> ans;

        for (int i = mini; i > 0; i--)
        {
                if (nw[i].size() > 0)
                {
                        ans.push_back(nw[i][0]);
                }


        }

        for (int i = 0; i <= maxi; i++)
        {
                if (pw[i].size() > 0)
                {
                       ans.push_back(pw[i][0]); 
                }
        }
        
        return ans;
}
    vector<int> topView(Node *root)
    {
        //Your code here
        
        vector<int> ans=verticalOrder(root);
        
        
        return ans;
    }

};