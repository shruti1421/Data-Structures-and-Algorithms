/*
Given a square grid of integers arr, a falling path with non-zero shifts is a choice of exactly one element from each row of arr, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.

 

Example 1:

Input: arr = [[1,2,3],[4,5,6],[7,8,9]]
Output: 13
Explanation: 
The possible falling paths are:
[1,5,9], [1,5,7], [1,6,7], [1,6,8],
[2,4,8], [2,4,9], [2,6,7], [2,6,8],
[3,4,8], [3,4,9], [3,5,7], [3,5,9]
The falling path with the smallest sum is [1,5,7], so the answer is 13.

 

Constraints:

    1 <= arr.length == arr[i].length <= 200
    -99 <= arr[i][j] <= 99


*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        
        int n=arr.size();
        
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
            dp[0][i]=arr[0][i];
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                 int miniDP=INT_MAX;
                for(int k=0;k<n;k++)
                {
                    if(k!=j)
                       miniDP=min(miniDP,dp[i-1][k]);
                }
                
                  dp[i][j]=miniDP+arr[i][j];
            }
        }
        
        int ans=INT_MAX;
        
        for(auto &x: dp[n-1])
        {
            ans=min(ans,x);
        }
        
        return ans;
        
    }
};
