//Precomputing power and using nth_element & iota
 vector<int> dp(1000001,-1);
class Solution {
       
    
     int getpower(int x)
    {
        if(dp[x]!=-1)
            return dp[x];
        
        if(x==1||x==0)
        {
            dp[x]=0;
            return dp[x];
        }
        
        if(x%2==0)
        {
            dp[x]=1+getpower(x/2);
            return dp[x];
        }
        else
        {
            dp[x]=1+getpower(3*x+1);
            return dp[x];
        }
    }


    
public:
    
    static bool cmp(int i,int j)
    {
        if(dp[i]==dp[j])
            return i<j;
        else
            return dp[i]<dp[j];
    }
    
    int getKth(int lo, int hi, int k) {
        
        
        
        for(int i=2;i<1001;i++)
        {
            dp[i]=getpower(i);
        }
        vector<int> sorted(hi-lo+1);
        iota(sorted.begin(),sorted.end(),lo);
        
        nth_element(sorted.begin(),sorted.begin()+k-1,sorted.end(),cmp);
        
        return sorted[k-1];
    }
};