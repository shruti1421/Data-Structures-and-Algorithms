//https://leetcode.com/contest/weekly-contest-256/problems/find-the-kth-largest-integer-in-the-array/
class Stringcmp{
        public:
         bool operator() (string &b, string &a)
         {
            if(a.size()!=b.size()) return a.size()<b.size();
            return a<b;
         }
};
   
class Solution {
public:

    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,Stringcmp> pq;
        int n=nums.size();
        
        
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            
            if(pq.size()>k)
                pq.pop();
        }
        
        
        return pq.top();
    }
};