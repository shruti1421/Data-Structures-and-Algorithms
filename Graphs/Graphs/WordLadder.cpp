//https://leetcode.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        
        queue<string> q;
        unordered_set<string> lists(wordList.begin(),wordList.end());
        
        q.push(beginWord);
        int depth=0;
        int lsize=1;
        
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            if(curr==endWord)
                return depth+1;
            
            
            lsize--;
            if(lsize==0)
                depth++;
            

            for(int i=0;i<curr.length();i++)
            {
                for(int j=0;j<26;j++)
                {
                    char temp=curr[i];
                    if(temp!=char(j+97))
                    {
                    curr[i]=char(j+97);
                    
                    if(lists.find(curr)!=lists.end())
                    {

                        q.push(curr);
                        lists.erase(lists.find(curr));
                    }
                    curr[i]=temp;
                    }
                }
            }
            
            if(lsize==0) lsize=q.size();
        }
        return 0;
    }
};