/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

The following code takes
Time Complexity: O(n)
Auxillary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int getWater(int a[], int n)
{
    int res=0;
    int lMax[n],rMax[n];
    
    lMax[0]=a[0];
    for(int i=1;i<n;i++)
    {
        lMax[i]=max(lMax[i-1],a[i]);
    }
    
    rMax[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rMax[i]=max(rMax[i+1],a[i]);
    }
    
    for(int i=1;i<n-1;i++)
    {
        res+=min(lMax[i],rMax[i])-a[i];
    }
    
    return res;
}


int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin >> a[i];
	
	cout << getWater(a,n);
	
	return 0;
}
