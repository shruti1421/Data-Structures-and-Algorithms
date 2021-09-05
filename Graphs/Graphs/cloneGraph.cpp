//https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL)
            return NULL;
        Node* clone = new Node(node->val);
        
        queue<Node*> original, cloned;
        
        original.push(node);
        
        unordered_map<int,Node*> vis;
        vis[node->val]=clone;

        
        while(!original.empty())
        {
            Node* temp=original.front();
            original.pop();
            
            vector<Node*> v;
            
            for(auto &x: temp->neighbors)
            {
                if(!vis[x->val])
                {
                    original.push(x);
                    Node* child = new Node(x->val);
                    vis[child->val]=child;
                    v.push_back(child);
                }
                else
                {
                    v.push_back(vis[x->val]);
                }
            }
            
            vis[temp->val]->neighbors=v;
        }
        
        return clone;
    }
};