//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        vector<int> preSum(n,0),sufSum(n,0);
        
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                preSum[i]=cardPoints[i];
            else
                preSum[i]=preSum[i-1]+cardPoints[i];
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                sufSum[i]=cardPoints[i];
            else
                sufSum[i]=sufSum[i+1]+cardPoints[i];
        }
        
        int ans=INT_MIN;
        
        if(k==n)
        {
           ans=preSum[n-1];
            return ans;
        }
        
        for(int i=0;i<=k;i++)
        {
            int x=k-i;
            
            if(x==k)
                ans=max(ans,sufSum[n-x]);
            else if(x==0)
                ans=max(ans,preSum[k-x-1]);
            else
                ans=max(ans,preSum[k-x-1]+sufSum[n-x]);
        }
        
        return ans;
    }
};