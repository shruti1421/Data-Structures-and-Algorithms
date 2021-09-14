//https://leetcode.com/problems/swap-for-longest-repeated-character-substring/
class Solution {
public:
    int maxRepOpt1(string text) {
        int n=text.length();
        
        vector<int> freq(26,0);
        
        for(int i=0;i<n;i++)
            freq[text[i]-'a']++;
        
        vector<int> countSub(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
                countSub[i]=1;
            else if(text[i]==text[i-1])
                countSub[i]=countSub[i-1]+1;
            else
                countSub[i]=1;
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,countSub[i]);
            
            if(i+1<n&&text[i]==text[i+1])
                continue;
            
            if(i+2<n&&text[i+2]==text[i])
            {
                int j=i+2;
                while(j<n&&text[j]==text[i])
                    j++;
                j--;
                
                if(j-i-2+1==1)
                {
                     int cnt=countSub[i]+j-i-2+1;
                   if(cnt<freq[text[i]-'a'] )
                       cnt++;
                    ans=max(ans,cnt);
                }
                else
                {
                   int cnt=countSub[i]+j-i-2+1;
                   if(cnt<freq[text[i]-'a'] )
                       cnt++;
                    
                    ans=max(ans,cnt);
                    
                    i=j-1;
                }
            }
            else{
   
                   int cnt=countSub[i];
                   if(cnt<freq[text[i]-'a'] )
                       cnt++;
                    
                    ans=max(ans,cnt);
            }
        }
        
        return ans;
    }
};