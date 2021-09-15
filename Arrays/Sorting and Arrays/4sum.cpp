//https://leetcode.com/problems/4sum/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int a=j+1,b=n-1,t=target-nums[i]-nums[j];
                
                int sum=nums[a]+nums[b];
                
                while(a<b)
                {
                    if(sum<t)
                        a++;
                    else if(sum>t)
                        b--;
                    else
                    {
                        vector<int> v={nums[i],nums[j],nums[a],nums[b]};
                        
                        ans.push_back(v);
                        
                        a++;
                        while(a<b&&nums[a]==nums[a-1])
                            a++;
                        b--;
                        while(a<b&&nums[b]==nums[b+1])
                            b--;
                    }
                    sum=nums[a]+nums[b];
                }
                
                while(j<n-1&&nums[j]==nums[j+1])
                    j++;
            }
            
            
            
            while(i<n-1&&nums[i]==nums[i+1])
                i++;
        }
        
        return ans;
    }
};