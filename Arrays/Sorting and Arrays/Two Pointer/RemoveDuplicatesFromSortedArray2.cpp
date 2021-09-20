//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1)
            return 1;
        
        int fast=1,slow=2,cnt=1;
        if(nums[0]==nums[1])
        {
            cnt=2;
        }
        for(int i=2;i<n;i++)
        {
            if(nums[i]==nums[slow-1])
            {
                cnt++;
                if(cnt>2)
                    continue;
                else{
                    nums[slow]=nums[i];
                    slow++;
                }
            }
            else {
                cnt=1;
                nums[slow]=nums[i];
                slow++;
            }
            

        }

        return slow;
    }
};