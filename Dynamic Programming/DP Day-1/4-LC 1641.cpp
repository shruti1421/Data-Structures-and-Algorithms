//https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:

    int countVowelStrings(int n) {
        
        int arr[5]={1,2,3,4,5};
        
        int dp[n][5];
        
        int ans[n];
        
        ans[0]=5;
        
        if(n==1)
            return ans[0];

        
        dp[1][0]=1;
        dp[1][1]=2;
        dp[1][2]=3;
        dp[1][3]=4;
        dp[1][4]=5;
        
        
        
        ans[1]=dp[1][0]+dp[1][1]+dp[1][2]+dp[1][3]+dp[1][4];
        

        for(int i=2;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(j==0)
                dp[i][5-j-1]=ans[i-1];
                else
                {
                    cout << dp[i-1][5-j] << " ";
                    dp[i][5-j-1]=ans[i-1]-dp[i-1][5-j];
                    ans[i-1]-=dp[i-1][5-j];
                }
            }
            ans[i]=dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4];
        }
        
        return ans[n-1];
    }
};