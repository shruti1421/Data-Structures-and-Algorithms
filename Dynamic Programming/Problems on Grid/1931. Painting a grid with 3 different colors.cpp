//https://leetcode.com/problems/painting-a-grid-with-three-different-colors/
class Solution {
public:
    const long long MOD = 1000000007;
    
    int dp[1001][4][4][4][4][4]={};
    
    int dfs(int n, int m, int a0, int b0, int c0, int d0, int e0)
    {
        if(n==0)
            return 1;
        
        if(dp[n][a0][b0][c0][d0][e0]!=0)
            return dp[n][a0][b0][c0][d0][e0];
        
        vector<int> colors={1,2,3};
        
        int ans=0;
        
        for(auto a: colors)
        {
            if(a==a0) continue;
            if(m==1)
            {
                ans+=dfs(n-1,m,a,0,0,0,0);
                ans%=MOD;
                continue;
            }
            for(auto b: colors)
            {
                if(b==b0||b==a) continue;
                 if(m==2)
                 {
                   ans+=dfs(n-1,m,a,b,0,0,0);
                   ans%=MOD;
                   continue;
                  }
                for(auto c: colors)
                {
                    if(c==c0||c==b)continue;
                     if(m==3)
                     {
                        ans+=dfs(n-1,m,a,b,c,0,0);
                        ans%=MOD;
                        continue;
                     }
                    for(auto d: colors)
                    {
                        if(d==d0||d==c) continue;
                         if(m==4)
                        {
                            ans+=dfs(n-1,m,a,b,c,d,0);
                            ans%=MOD;
                            continue;
                        }
                        for(auto e: colors)
                        {
                            if(e==e0||e==d) continue;
                            
                            ans+=dfs(n-1,m,a,b,c,d,e);
                            ans%=MOD;
                        }
                            
                    }
                }
            }
        }
        
        return dp[n][a0][b0][c0][d0][e0]=ans;
    }
    
 
    
    int colorTheGrid(int m, int n) {
        
        return dfs(n,m,0,0,0,0,0);
        
    }
};