//O(26*n)

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length(),ans=0;
        
        unordered_map<string,int> mp;
        
        vector<int> first(26,INT_MAX),last(26,INT_MAX);
        
        for(int i=0;i<n;i++)
        {
            first[s[i]-'a']=min(first[s[i]-'a'],i);
            last[s[i]-'a']=i;
        }
        
        for(int i=0;i<26;i++)
        {
            if(first[i]<last[i])
            {
                unordered_set<char>st;
                
                for(int j=first[i]+1;j<last[i];j++)
                {
                    st.insert(s[j]);
                }
                
                ans+=st.size();
            }
        }
        
     
        return ans;
    }
};