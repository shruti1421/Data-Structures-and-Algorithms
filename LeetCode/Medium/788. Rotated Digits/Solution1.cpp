//DP Solution

class Solution {
public:
    int rotatedDigits(int n) {
        int f=0,cnt=0;
     
        vector<int> dp(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            if(i<10)
            {
                
                if(i==0||i==1||i==8)
                    dp[i]=1;
                else if(i==2||i==5||i==6||i==9)
                {
                    dp[i]=2;
                    cnt++;
                }
            }
            else
            {
                int a=dp[i/10],b=dp[i%10];
                if(a==1&&b==1)
                    dp[i]=1;
                else if(a!=0&&b!=0)
                {
                    dp[i]=2;
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

   
