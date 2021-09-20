//https://leetcode.com/problems/largest-number/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                string str=to_string(nums[i]);
                str.append(to_string(nums[j]));
                
                string str2=to_string(nums[j]);
                str2.append(to_string(nums[i]));
                
               if(str2>str)
                   swap(nums[i],nums[j]);
            }
        }
        
        string ans="";
        int f=0;
        
        for(int i=0;i<n;i++)
        {
            if(f==0&&nums[i]==0)
                continue;
            else
            {
                f=1;
                ans.append(to_string(nums[i]));
            }

        }
        if(ans=="")
            return "0";
        else
            return ans;
    }
};