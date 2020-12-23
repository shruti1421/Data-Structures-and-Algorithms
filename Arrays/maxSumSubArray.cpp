/*Maximum Sum Subarray
to find the subarray having maximum Sum

TC: O(n)
AS: O(1)
*/
#include <iostream>
using namespace std;

int maxSumSubArray(int n, int a[])
{
    int sum=a[0],res=sum;
    for(int i=1;i<n;i++)
    {
       sum=max(a[i],sum+a[i]);
       res=max(sum,res);
    }
    
    return res;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	int a[n];
	
	for(int i=0;i<n;i++)
	{
	    cin >> a[i];
	}
	
	cout << maxSumSubArray(n,a);
	
	return 0;
}
