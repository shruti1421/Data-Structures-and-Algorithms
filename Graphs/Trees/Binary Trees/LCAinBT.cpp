//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1#
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

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)
       return NULL;
       
       unordered_map<int,pair<int,int>> mp;
       
       queue<Node*> q;
       
       q.push(root);
       
       mp.insert({root->data,{0,-1}});
       
       while(!q.empty())
       {
           Node* temp=q.front();
           q.pop();
           
           if(temp->left)
           {
               q.push(temp->left);
               pair<int,int> x=mp[temp->data];
               mp.insert({temp->left->data,{x.first+1,temp->data}});
           }
            if(temp->right)
           {
               q.push(temp->right);
               pair<int,int> x=mp[temp->data];
               mp.insert({temp->right->data,{x.first+1,temp->data}});
           }
       }
       
       if(mp[n1].first>mp[n2].first)
       swap(n1,n2);
       
       while(mp[n1].first!=mp[n2].first)
       {
           n2=mp[n2].second;
       }
       
       int res;
       
       if(n1==n2)
       res=n1;
       
       while(n1!=n2)
       {
           n1=mp[n1].second;
           n2=mp[n2].second;
       }
       
       res=n1;
       
        q.push(root);
       
       while(!q.empty())
       {
           Node* temp=q.front();
           q.pop();
           
           if(temp->data==res)
           return temp;
           
           if(temp->left)
           {
               q.push(temp->left);
           }
            if(temp->right)
           {
               q.push(temp->right);
           }
       }
    }
};

// { Driver Code Starts.

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
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
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
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;

    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
  // } Driver Code Ends
        scanf("%d %d ",&a,&b);
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        Solution ob;
        cout<<ob.lca(root,a,b)->data<<endl;
    }
    return 0;
}