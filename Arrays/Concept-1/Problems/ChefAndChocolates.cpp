//https://www.codechef.com/problems/CHOC
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	// your code goes here
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	ll n,u,x,y,k,m,p;
	while(t--)
	{
	    
	    cin >> n >> u;
	    
	    vector<ll> students(n+1,0);
	    
	    for(int i=0;i<u;i++)
	    {
	        cin >> x >> y >> k;
	        students[x]+=k;
	        
	        students[y+1]-=k;
	    }
	    
	    for(int i=1;i<n;i++)
	    {
	        students[i]+=students[i-1];
	    }
	    
	    cin >> m;
	    
	    for(int i=0;i<m;i++)
	    {
	        cin >>p;
	        
	        cout << students[p] << "\n";
	    }
	}
	return 0;
}