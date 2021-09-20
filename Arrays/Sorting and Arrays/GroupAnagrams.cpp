//https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    static bool cmp(vector<string> &a, vector<string> &b)
    {
         if(a.size()==b.size())
         {
             int i=0;
             while(i<a.size()&&a[i]==b[i])
                i++;
             if(i==a.size())
                 return 1;
             return a[i]<b[i];
         }
        return a.size()<b.size();
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         int n=strs.size();
        
         unordered_map<string,vector<string>> mp;
        
        for(int i=0;i<n;i++)
        {
            vector<int> freq(26,0);
            
            int m=strs[i].size();
            
            for(int j=0;j<m;j++)
            {
                int x=strs[i][j] -'a';
                freq[x]+=1;
            }
            
            string str="";
            
            for(int j=0;j<26;j++)
            {
                str.append(to_string(freq[j]));
                str.append("$");
            }
            
            mp[str].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        
        for(auto &x: mp)
        {
            sort(x.second.begin(),x.second.end());
            ans.push_back(x.second);
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};