//https://leetcode.com/problems/replace-the-substring-for-balanced-string/
class Solution {
public:
    int balancedString(string s) {
        int n=s.length();
        int start=0,end=0;
        
        unordered_map<char,int> mp;
        
        int k=n/4;
        
        mp.insert({'Q',0});
        mp.insert({'W',0});
        mp.insert({'R',0});
        mp.insert({'E',0});
        
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        
        if(mp['Q']==k&&mp['R']==k&&mp['E']==k&&mp['W']==k)
            return 0;
        
        int ans=n;
        
        start=0;
        for(int end=0;end<n;end++)
        {
            mp[s[end]]--;
            
            while(start<n)
            {
                if(mp['Q']>k||mp['R']>k||mp['W']>k||mp['E']>k)
                    break;
                
                ans=min(ans,end-start+1);
                mp[s[start]]++;
                start++;  
               
            }
        }
        
        return ans;
    }
};
//https://shengqianliu.me/two-pointers/replace-the-substring-for-balanced-string