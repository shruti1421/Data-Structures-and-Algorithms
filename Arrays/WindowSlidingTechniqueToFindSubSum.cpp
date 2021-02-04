//Window Sliding Technique
//Given an unsorted array of non-negative integers. Find if there is a subarray with given sum.
//ex: I/O: arr[]={1,4,20,3,10.5} sum=33 O/P: YES
//ex: I/O: arr[]={2,4} sum=3 O/P: NO
//TC: O(n)  AS: O(1)


#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	int a[n];

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int req_sum;

	cin >> req_sum;

	int start = 0, end = 0;

	int sum = 0;
	while (end <= n)
	{

		while (sum > req_sum && start < n - 1)
		{
			sum -= a[start];
			start++;
		}
		if (sum == req_sum)
		{
			cout << "YES";
			return 0;
		}

		if (end < n)
			sum += a[end];
		end++;

	}

	cout << "NO";

	return 0;

}
