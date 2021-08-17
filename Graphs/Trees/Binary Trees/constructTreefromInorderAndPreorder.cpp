// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        if(n==0)
        return NULL;
        
        Node* node=new Node(pre[0]);
        
        int leftin[n],rightin[n],f=0,j=0,leftsize=0,rightsize=0;
        for(int i=0;i<n;i++)
        {
            if(in[i]==pre[0])
            {
                f=1;
                leftsize=j;
                j=0;
                continue;
            }
            
            if(f==0)
            {
                leftin[j]=in[i];
                j++;
            }
            else
            {
                rightin[j]=in[i]; 
                j++;
            }
        }
        
        rightsize=j;
    
        int i=1,leftpre[n],rightpre[n];
        
        for(int j=0;j<leftsize;j++)
        {
            leftpre[j]=pre[i++];
        }
        
        for(int j=0;j<rightsize;j++)
        {
            rightpre[j]=pre[i++];
        }
        
        node->left=buildTree(leftin,leftpre,leftsize);
        node->right=buildTree(rightin,rightpre,rightsize);
        
        return node;
    }
};

//https://practice.geeksforgeeks.org/problems/construct-tree-1/1#
// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends