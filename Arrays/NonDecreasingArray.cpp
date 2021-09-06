//https://leetcode.com/problems/non-decreasing-array/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n=nums.size(),c=0;
        
        for(int i=0;i<n-1;i++)
        {
             if(nums[i+1]<nums[i])
             {
                 if(c) return false;
                 else
                 {
                     c++;
                     if(i+2<n&&nums[i+2]>=nums[i+1])
                         nums[i]=nums[i+1];
                     else if(i+2>=n) return true;
                     else return false;
                 }
             }
            else
            {
                if(i+2<n&&nums[i+1]>nums[i+2])
                {
                    if(c) return false;
                    else if(nums[i+2]>=nums[i])
                    {
                        c++;
                        nums[i+1]=nums[i];
                    }
                    else if(i+2<n&&nums[i+2]<=nums[i])
                    {
                        c++;
                        nums[i+2]=nums[i+1];
                    }
                }
            }
        }
        
        return true;
    }
};