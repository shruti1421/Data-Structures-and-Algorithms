//https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        
        vector<pair<int,int>> tow;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]-k>=0)
                tow.push_back({arr[i]-k,i});
            tow.push_back({arr[i]+k,i});
        }
        
        sort(tow.begin(),tow.end());
        
        vector<int> vis(n,0);
        int ele=0,right=0,left=0;
        
        while(ele<n&&right<tow.size())
        {
            if(!vis[tow[right].second])
                ele++;
            vis[tow[right].second]++;
            right++;
        }
        
        int ans=INT_MAX;
        
        
                ans=min(ans,tow[right-1].first-tow[left].first);
        
        while(right<tow.size()&&left<right)
        {
            if(vis[tow[left].second]==1)
                ele--;
            vis[tow[left].second]--;
            left++;
            
            while(ele<n&&right<tow.size())
            {
                if(!vis[tow[right].second])
                     ele++;
                vis[tow[right].second]++;
                right++;
            }
            
            if(ele==n)
                 ans=min(ans,tow[right-1].first-tow[left].first);
            else
                break;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends