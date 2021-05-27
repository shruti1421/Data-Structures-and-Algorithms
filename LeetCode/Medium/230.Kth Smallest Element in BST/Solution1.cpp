#include<bits/stdc++.h>
using namespace std;
//Recursive Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    void fillVector(TreeNode* root){
        if(root==NULL)
            return;
        
        v.push_back(root->val);
        
        fillVector(root->left);
        fillVector(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        fillVector(root);
        
        sort(v.begin(),v.end());
        
        
        return v[k-1];
        
    }
};
