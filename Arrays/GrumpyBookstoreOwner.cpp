//https://leetcode.com/problems/grumpy-bookstore-owner/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
                sum+=customers[i];
        }
        
        vector<int> preGrumpy(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                if(grumpy[i]==1)
                    preGrumpy[i]=customers[i];
            }
            else if(grumpy[i]==1)
                preGrumpy[i]=preGrumpy[i-1]+customers[i];
            else
                preGrumpy[i]=preGrumpy[i-1];
        }
        
        int ans=0;
        
        for(int i=minutes-1;i<n;i++)
        {
            if(i==minutes-1)
            {
                if(sum+preGrumpy[i]>ans)
                    ans=sum+preGrumpy[i];
            }
            else
                ans=max(sum+preGrumpy[i]-preGrumpy[i-minutes],ans);
        }
        
        return ans;

    }
};