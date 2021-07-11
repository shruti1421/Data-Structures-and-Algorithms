//O(n^2)
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
        
        for(int i=0;i<n;i++)
        {
            if(ans==c*26)
                return ans;
            
            vector<int> left(26,0);
            for(int j=0;j<i;j++)
            {
                left[s[j]-'a']=1;
            }
            
            vector<int> right(26,0);
            for(int j=i+1;j<n;j++)
            {
                right[s[j]-'a']=1;
            }
            
            for(int j=0;j<26;j++)
            {
                if(left[j]==1&&right[j]==1)
                {
                    string str="";
                    char c='a'+j;
                    str.push_back(c);
                    str.push_back(s[i]);
                    str.push_back(c);
                    
                    if(mp.find(str)==mp.end())
                    {
                        ans++;
                        mp.insert(make_pair(str,1));
                    }
                }
            }
        }
        
        return ans;
    }
};