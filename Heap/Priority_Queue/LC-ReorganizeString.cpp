//https://leetcode.com/problems/reorganize-string/
class Solution {
public:
    string reorganizeString(string s) {
        int n=s.length();
        
        vector<int> freq(26,0);
    
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(n-freq[i]<freq[i]-1)
                return "";
        }
        
        priority_queue<pair<int,int>> p;
     
        for(int i=0;i<26;i++)
        {
            p.push(make_pair(freq[i],i));
        }
        
        string str="";
        
        while(p.top().first>0)
        {
            pair<int,int> x=p.top();
            
            str.push_back(char('a'+x.second));
            
            p.pop();
            if(p.top().first>0)
            {
                pair<int,int> y=p.top();
                str.push_back(char('a'+y.second));
                p.pop();
                p.push(make_pair(y.first-1,y.second));
            }
            
            p.push(make_pair(x.first-1,x.second));
        }
        
        return str;
    }
};