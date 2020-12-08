/*
We have to calculate the no. of subsets which are equal to given sum.

Time Complexity: theta(2^n)
*/

#include <iostream>
using namespace std;

int countSubsets(int arr[],int n,int sum)
{
    if(n==0)
    return (sum==0)?1:0;
    return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
}

int main() {
	// your code goes here
	int n,sum;
	int a[n];
	
	cin >> n >> sum;
	
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	
	cout << countSubsets(a,n,sum);
	
	return 0;
}
