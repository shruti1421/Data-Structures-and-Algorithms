//https://leetcode.com/problems/majority-element-ii/
//https://gregable.com/2013/10/majority-vote-algorithm-find-majority.html - majority element(algorithm)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
        int curr1=-1,curr2=-1,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==curr1)
                cnt1++;
            else if(nums[i]==curr2)
                cnt2++;
            else if(cnt1==0)
            {
                curr1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0)
            {
                curr2=nums[i];
                cnt2=1;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
            
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==curr1)
                cnt1++;
            
            if(nums[i]==curr2)
                cnt2++;
        }
        
        if(cnt1>floor(n/3)&&cnt2>floor(n/3)&&curr1!=curr2)
            return {curr1,curr2};
        else if(cnt1>floor(n/3))
            return {curr1};
        else if(cnt2>floor(n/3))
            return {curr2};
        else return {};
        
    }
};