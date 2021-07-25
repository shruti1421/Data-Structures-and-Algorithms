//https://leetcode.com/problems/sort-integers-by-the-power-value/submissions/
class Solution {
public:
    int getpower(int x, vector<int> &dp)
    {
        if(dp[x]!=-1)
            return dp[x];
        
        if(x==1)
        {
            dp[x]=0;
            return dp[x];
        }
        
        if(x%2==0)
        {
            dp[x]=1+getpower(x/2,dp);
            return dp[x];
        }
        else
        {
            dp[x]=1+getpower(3*x+1,dp);
            return dp[x];
        }
    }
    
//     bool cmp(const pair<int,int> &a,const pair<int,int> &b)
//     {
//         if(a.first==b.first)
//             return a.second<b.second;
//         else
//             return a.first<b.first;
//     }
    
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,int>> power;
        vector<int> dp(1000000,-1);
        dp[1]=0;
        
        for(int i=lo;i<=hi;i++)
        {
            power.push_back(make_pair(getpower(i,dp),i));
        }
        
        sort(power.begin(),power.end());
        
        return power[k-1].second;
    }
};