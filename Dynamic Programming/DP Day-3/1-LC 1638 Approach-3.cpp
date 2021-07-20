//DP form of 2nd approach
class Solution {
public:
    int countSubstrings(string s, string t) {
        multimap<string,int> substrS,substrT;
        
        int n=s.length(),m=t.length(),cnt=0;
        
        vector<vector<int>> dpl(101,vector<int>(101,0)),dpr(101,vector<int>(101,0));
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(s[i-1]==t[j-1])
                    dpl[i][j]=dpl[i-1][j-1]+1;
            }
        }
        
         for(int i=n;i>0;i--)
        {
            for(int j=m;j>0;j--)
            {
                if(s[i-1]==t[j-1])
                    dpr[i-1][j-1]=dpr[i][j]+1;
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(s[i]!=t[j])
                cnt+=(dpl[i][j]+1)*(dpr[i+1][j+1]+1);
            }
        }
        
        return cnt;
    }
};