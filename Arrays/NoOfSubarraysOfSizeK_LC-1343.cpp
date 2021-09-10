//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        threshold*=k;
        int n=arr.size();
        
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];
        
        int c=0;
        
        for(int i=k-1;i<n;i++)
        {
            if(i==k-1&&arr[i]>=threshold)
                c++;
            else if(i>k-1&&arr[i]-arr[i-k]>=threshold)
               c++;
        }
        
        return c;
    }
};