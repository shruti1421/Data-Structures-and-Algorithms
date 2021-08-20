//https://practice.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

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
        if (i >= ip.size()) break;
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
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    bool pathofnode(Node* root, int a, vector<int> &path)
    {
        if(root==NULL)
        return 0;
        
        path.push_back(root->data);
        
        if(root->data==a)
        return 1;
        
        if(pathofnode(root->left,a,path)||pathofnode(root->right,a,path))
        return true;
        
        path.pop_back();
        return false;
    }
    
    int LCA(Node* root,int a, int b)
    {
        vector<int> pathA;
        
        bool fa=pathofnode(root,a,pathA);
        
        vector<int> pathB;
        
        bool fb=pathofnode(root,b,pathB);
        
        if(!fa||!fb)
        return -1;
        
        int i;
        for(i=0;i<pathA.size()&&i<pathB.size();i++)
        {
            if(pathA[i]!=pathB[i])
            break;
        }
        return pathA[i-1];
        
    }
    int dist(Node* root, int d, int a)
    {
        if(root==NULL)
        return -1;
        if(root->data==a)
        return d;
        
        return max(dist(root->left,d+1,a),dist(root->right,d+1,a));
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        
        // Your code here
        int lca=LCA(root,a,b);
        
        if(lca==-1)
        return INT_MAX;
        
        int da,db,dlca;
        
        da=dist(root,0,a);
        db=dist(root,0,b);
        dlca=dist(root,0,lca);
        
        
        
        return da+db-2*dlca;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
  // } Driver Code Ends