//https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();
        
        vector<int> freq(256,0);
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'\0']++;
        }
        
        vector<pair<int,char>> mp;
        
        for(int i=0;i<256;i++)
        {
            mp.push_back({freq[i],char(i)});
        }
        
        sort(mp.begin(),mp.end());
        reverse(mp.begin(),mp.end());
        
        int j=0;
        
        for(int i=0;i<256;i++)
        {
            while(mp[i].first>0)
            {
                s[j++]=mp[i].second;
                mp[i].first--;
            }
        }
        
        return s;
    }
};