//https://leetcode.com/problems/largest-number-after-mutating-substring/
class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n=num.length();
        
        string temp;
        string ans=num;
        int index=0;
        
        for(int i=0;i<n;i++)
        {
           int x=num[i]-'0',z=0;
           temp=num;
               int j;
                for(j=i;(j)<n&&change[x]>=x;j++)
                {
                   
                   temp[j]=change[x]+'0';
                    if(j<n-1)
                    x=num[j+1]-'0';
                }
            if(j==n)
            {
                ans=temp;
                break;
            }
            
            for(int j=index;j<n;j++)
            {
                if((temp[j]-'0')<(ans[j]-'0'))
                    break;
                else 
                if((temp[j]-'0')>(ans[j]-'0'))
                {
                    ans=temp;
                    index=j;
                    break;
                }
            }
            
            
        
        }
        
        
        return ans;
        
        
    }
};