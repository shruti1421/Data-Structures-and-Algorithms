/*
Stock Buy and Sell
We are given value of stocks , we need to find the maximum profit by buying and selling the stocks present in the array

The following code takes
Time Complexity: O(n)
Auxillary Space: O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int stockBuyAndSell(int a[], int n)
{
    int profit=0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i]>a[i-1])
        profit+=a[i]-a[i-1];
    }
    
    return profit;
}


int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++)
	cin >> a[i];
	
	cout << stockBuyAndSell(a,n);
	
	return 0;
}
