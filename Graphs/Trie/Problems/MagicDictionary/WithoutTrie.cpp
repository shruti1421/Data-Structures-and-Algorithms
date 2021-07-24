//https://leetcode.com/problems/implement-magic-dictionary/
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> dict;
    
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        this->dict=dictionary;
    }
    
    bool search(string searchWord) {
        
        vector<string> temp=this->dict;
        
        int n=temp.size();
        
        for(int i=0;i<n;i++)
        {
            if(temp[i].size()==searchWord.size())
            {
                int m=temp[i].size(),cnt=0;
                
                string str=temp[i];
                
                for(int j=0;j<m;j++)
                {
                    if(str[j]!=searchWord[j])
                        cnt++;
                }
                
                if(cnt==1)
                    return true;
            }
        }
        
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */