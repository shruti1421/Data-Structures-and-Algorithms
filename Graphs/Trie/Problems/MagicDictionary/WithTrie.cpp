//https://leetcode.com/problems/sort-integers-by-the-power-value/
struct TrieNode {
    TrieNode *child[26];
    int wordCnt;
};

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode *root = new TrieNode();
    
    MagicDictionary() {
        this->root->wordCnt=0;
    }
    
    void insert(TrieNode *node,string str)
    {
        int n=str.length();
        
        for(int i=0;i<n;i++)
        {
            if(node->child[str[i]-'a']==NULL)
            {
                TrieNode *temp = new TrieNode();
                temp->wordCnt=0;
                node->child[str[i]-'a']=temp;
            }
            node=node->child[str[i]-'a'];
        }
        
        node->wordCnt+=1;
    }
    
    void buildDict(vector<string> dictionary) {
        
        int n=dictionary.size();
        
        for(int i=0;i<n;i++)
        {
            insert(this->root,dictionary[i]);
        }
    }
    
    bool extendWord(TrieNode *node,string str,int index,int j)
    {
        int n=str.length();
        
        
        for(int i=index;i<n;i++)
        {
            if(node->child[str[i]-'a']==NULL)
            {
                return false;
            }
            node=node->child[str[i]-'a'];
        }
        
        if(node->wordCnt>0)
            return true;
        else
            return false;
    }

    
    bool search(string searchWord) {
        
        TrieNode *node=root;
        
        int n=searchWord.length(),z=0;
        
        bool f=false;
        
        for(int i=0;i<n;i++)
        {
               
            
            if(node!=NULL)
            {
            
            for(int j=0;j<26;j++)
            {
                char c=char(97+j);
             
                if(node->child[j]!=NULL&&c!=searchWord[i])
                {
                    f+=extendWord(node->child[j],searchWord,i+1,j);
                }
            }
                 
            if(node->child[searchWord[i]-'a']!=NULL)
            {
                node=node->child[searchWord[i]-'a'];
            }
            else return f;
                
            }
            
        }
        
        return f;
        
        
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */