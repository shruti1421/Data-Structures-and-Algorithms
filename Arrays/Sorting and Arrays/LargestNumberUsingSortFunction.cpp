class Solution {
public:
    static bool cmp(string &s1, string &s2)
    {
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        
        vector<string> st;
        
        for(int i=0;i<n;i++)
            st.push_back(to_string(nums[i]));
        sort(st.begin(),st.end(),cmp);
        
        string ans="";
        int f=0;
        
        for(int i=0;i<n;i++)
        {
            if(st[i]=="0"&&f==0)
                continue;
            else
            {
                f=1;
                ans.append(st[i]);
            }
        }
        
        if(ans=="")
            return "0";
        else return ans;
    }
};