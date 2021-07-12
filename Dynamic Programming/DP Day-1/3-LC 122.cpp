//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int ans=0,buy=prices[0],sell=0,profit=0;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]<sell)
            {
                buy=prices[i];
                ans+=profit;
                profit=0;
                sell=0;
            }else if(prices[i]>buy)
            {
                profit=max(prices[i]-buy,profit);
                sell=prices[i];
                
                if(i==n-1)
                    ans+=profit;
            }else
                buy=prices[i];
        }
        
        return ans;
    }
};