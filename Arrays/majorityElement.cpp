/*Majority Element
A element in an array is called majority when it occurs more than n/2 time in that array given that n is the size of that array
We have to find whether majority element is present in the given array or not and print that element.

TC: O(n)
AS: O(1)
*/
#include <iostream>
using namespace std;

int majorityElement(int n, int a[])
{
    int res=0, count = 1;
    
    for(int i=1; i<n; i++)
    {
        if(a[res]==a[i])
        count++;
        else
        count--;
        
        if(count==0)
        res=i;count=1;
    }
    
    count = 0;
    
    for(int i=0;i<n;i++)
    {
        if(a[res]==a[i])
        count++;
    }
    
    if(count>(n/2))
    return a[res];
    else
    return -1;
    
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
	
	cout << majorityElement(n,a);
	
	return 0;
}
