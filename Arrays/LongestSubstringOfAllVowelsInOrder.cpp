//https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n=word.size();
        int start=-1,end=-1;
        
        unordered_map<char,int> mp;
        
        mp.insert({'a',1});
        mp.insert({'e',2});
        mp.insert({'i',3});
        mp.insert({'o',4});
        mp.insert({'u',5});
        
        int index=0;
        
        int ans=-1;
        
        for(int i=0;i<n;i++)
        {
            if(mp[word[i]]-index==1)
            {
                index++;
                if(index==1)
                    start=i;
                
                if(index==5)
                {
                    end=i;
                    ans=max(ans,end-start+1);
                }
            }
            else if(mp[word[i]]-index==0)
            {
                if(index==5)
                {
                    end=i;
                    ans=max(ans,end-start+1);
                }
            }
            else
            {
                index=0;
                start=-1;
                end=-1;
                if(word[i]=='a')
                 i--;
            }
        }
        
        if(ans==-1)
            return 0;
        else
            return ans;
    }
};