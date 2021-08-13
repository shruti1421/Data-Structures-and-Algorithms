//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
        int data;
        Node* left;
        Node* right;
};

vector<int> leftView(struct Node *root);

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

        // for(string i:ip)
        //     cout<<i<<" ";
        // cout<<endl;
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


int main() {
        int t;
        scanf("%d ", &t);
        while (t--)
        {
                string s;
                getline(cin, s);
                Node* root = buildTree(s);
                vector<int> vec = leftView(root);
                for (int x : vec)
                        cout << x << " ";
                cout << endl;
        }
        return 0;
}

// } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{       vector<int> ans;
        if (root == NULL)
                return ans;
        // Your code here
        deque<Node*> q;
        q.push_back(root);

        unordered_map<Node*, int> nh;
        vector<int> h[101];

        nh.insert({root, 0});
        h[nh[root]].push_back(root->data);

        while (!q.empty() && q.front() != NULL)
        {
                Node *temp = q.front();
                q.pop_front();
                if (temp->left)
                {
                        q.push_back(temp->left);
                        nh.insert({temp->left, nh[temp] + 1});
                        h[nh[temp->left]].push_back(temp->left->data);
                }

                if (temp->right)
                {
                        q.push_back(temp->right);
                        nh.insert({temp->right, nh[temp] + 1});
                        h[nh[temp->right]].push_back(temp->right->data);
                }

        }




        for (int i = 0; i <= 100; i++)
        {
                if (h[i].size() > 0)
                {
                        ans.push_back(h[i][0]);
                }
        }

        return ans;


}