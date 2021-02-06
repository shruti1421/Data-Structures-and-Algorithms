//Count Occurrences in a Sorted Array(Binary Search)
//TC: O(logn)

#include<bits/stdc++.h>
using namespace std;

//Square root by using binary search algorithm
//from this algorithm we could only the floor value of the square root

int binarySearch(int n)
{

	int high = n, low = 1, mid;

	int res = (low + high) / 2;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int ans = mid * mid;

		if (ans > n)
			high = mid - 1;
		if (ans < n)
		{
			low = mid + 1;
			res = mid;
		}
		if (ans == n)
			return mid;
	}


	return res;
}


int main() {

	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n;

	cin >> n;

	int sqRoot = binarySearch(n);


	cout << sqRoot;

}
