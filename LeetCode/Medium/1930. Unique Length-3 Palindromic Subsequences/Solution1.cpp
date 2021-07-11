//O(n^3) 

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length(),ans=0;
        
        unordered_map<string,int> mp;
        
        vector<int> arr(26,0);
        
        for(int i=0;i<n;i++)
            arr[s[i]-'a']++;
        
        int c=0;
        
        for(int i=0;i<26;i++)
        {
            if(arr[i]>1)
                c++;
        }
        
        for(int i=0;i<n-2;i++)
        {
            if(ans==c*26)
                return ans;
            
            if(arr[s[i]-'a']<2)
                continue;
            
            for(int j=i+2;j<n;j++)
            {
                if(ans==c*26)
                return ans;
                if(s[j]==s[i])
                {
                       
                    
                    if((j-i)>1)
                    {
                        for(int k=i+1;k<j;k++)
                        {
                            if(ans==c*26)
                            return ans;
                            string str="";
                            str.push_back(s[i]);
                            str.push_back(s[k]);
                            str.push_back(s[j]);      
                    
                         if(mp.find(str)==mp.end())
                         {
                            ans++;
                            mp.insert(make_pair(str,1));
                          }
                    
                        }
                    }
                }
            }
            
            arr[s[i]-'a']--;
        }
        
        return ans;
    }
};