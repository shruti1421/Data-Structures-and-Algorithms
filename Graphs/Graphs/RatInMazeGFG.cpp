//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void Path(string &str, vector<vector<int>> &m, int x, int y, int n, vector<string> &ans)
    {
        if(x==n-1&&y==n-1&&m[x][y]==1)
        {
            ans.push_back(str);
            return;
        }
        
        if(x>=n||y>=n)
        
        
        int temp=m[x][y];
        m[x][y]=0;   
        if(x+1<n&&m[x+1][y]==1)
        {
            str.push_back('D');
            Path(str,m,x+1,y,n,ans);
            str.pop_back();
        }
        
        if(y+1<n&&m[x][y+1]==1)
        {
            str.push_back('R');
            Path(str,m,x,y+1,n,ans);
            str.pop_back();
        }
        
        if(x-1>=0&&m[x-1][y]==1)
        {
            str.push_back('U');
            Path(str,m,x-1,y,n,ans);
            str.pop_back();
        }
        
        if(y-1>=0&&m[x][y-1]==1)
        {
            str.push_back('L');
            Path(str,m,x,y-1,n,ans);
            str.pop_back();
        }
        
        m[x][y]=1;
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string str="";
        if(m[0][0]==1)
        Path(str, m,0,0,n,ans);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends