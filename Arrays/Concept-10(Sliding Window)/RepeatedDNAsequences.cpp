//https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        
        vector<string> ans;
        
        unordered_map<string,int> vis;
        
        for(int i=0;i<=n-10;i++)
        {
            string str=s.substr(i,10);
            if(vis.find(str)==vis.end())
                vis.insert({str,0});
            else if(vis[str]==1)
                ans.push_back(str);
            
            vis[str]++;
        }

        return ans;
    }
};