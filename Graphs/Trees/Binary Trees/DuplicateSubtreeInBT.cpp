//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *left;
	struct Node *right;

	Node(char x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

struct Node* buildTree(string str)
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
	Node *root = new Node(stoi(ip[0]));

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

			// Create the left child for the current Node
			currNode->left = new Node(stoi(currVal));

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
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}
		i++;
	}

	return root;
}


 // } Driver Code Ends
/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
   vector<int> preorder(Node* root)
   {
       vector<int> ans;
       
       if(root==NULL)
       return ans;
       
       stack<Node*> st;
       
       st.push(root);
       
       while(!st.empty())
       {
           Node* temp=st.top();
           
           st.pop();
           
           ans.push_back(temp->data);
           
           if(temp->right)
           st.push(temp->right);
           
           if(temp->left)
           st.push(temp->left);
       }
       
       return ans;
   }
   
   vector<int> inorder(Node* root)
   {
       vector<int> ans;
       
       if(root==NULL)
       return ans;
       
       Node* curr=root;
       
       stack<Node*> st;
       
       while(!st.empty()||curr!=NULL)
       {
           if(curr!=NULL)
           {
               st.push(curr);
               curr=curr->left;
           }
           else{
               Node* temp=st.top();
               st.pop();
               
               ans.push_back(temp->data);
               curr=temp->right;
           }
       }
       
       return ans;
   }
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int finddup(set<vector<int>> s, vector<int>pre, vector<int> in, int n)
    {
        if(n<=1)
        return 0;
        
        int ele=pre[0];
         
        vector<int> leftin(n,0),rightin(n,0);
        int leftsize=0,rightsize=0; 
         
        int i=0; 
        while(ele!=in[i]&&i<n)
        {
            leftin[i]=in[i];
            i++;
        }
        
        leftsize=i;
        int j=0;
        i++;
        if(i<n&&ele==in[i])
        {
            leftsize=i;
            i++;
        }
        while(i<n)
        {
            rightin[j++]=in[i];
            i++;
        }
        
        rightsize=j;
        
        vector<int> leftpre(leftsize,0),rightpre(rightsize,0);
         
         j=1;
        for(i=0;i<leftsize;i++)
        leftpre[i]=pre[j++];
        
        for(i=0;i<rightsize;i++)
        rightpre[i]=pre[j++];
        
        if(s.find(leftpre)!=s.end()||s.find(rightpre)!=s.end())
        return 1;
        else
        {
            if(leftsize>1)
            s.insert(leftpre);
            if(rightsize>1)
            s.insert(rightpre);
        }
        
        return finddup(s,leftpre,leftin,leftsize)||finddup(s,rightpre,rightin,rightsize);
        
    }
    int dupSub(Node *root) {
         // code here
         if(root==NULL)
         return 0;
         
         vector<int> pre,in;
         
         set<vector<int>> s;
         
         pre=preorder(root);
         in=inorder(root);
         
         return finddup(s, pre,in,pre.size());
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin >> t;
	//cout << t << "\n";
	while (t--)
	{
		string treeString;
		getline(cin >> ws, treeString);
		struct Node* root = buildTree(treeString);
		Solution ob;
		cout << ob.dupSub(root) << "\n";
	}
	return 0;
}  // } Driver Code Ends