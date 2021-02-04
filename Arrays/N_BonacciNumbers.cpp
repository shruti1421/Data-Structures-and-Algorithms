//N-bonacci numbers: Print first M N-bonacci number.
// ex: I/P: N=3 M=8 O/P: 0 0 1 1 2 4 7 13
// TS: theta(M)  AS: O(1)


#include<bits/stdc++.h>
using namespace std;

int main() {


#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, m;

	cin >> n >> m;

	vector<int> a;

	int i = 1;
	while (i < n)
	{
		a.push_back(0);
		i++;
	}

	m -= n ;
	m--;

	a.push_back(1);

	int start = 0, end = n;

	int sum = 1;

	while (m >= 0)
	{
		a.push_back(sum);

		sum += a[end];
		sum -= a[start];
		start++;
		end++;
		m--;

	}

	for (int j = 0; j < a.size(); j++)
		cout << a[j] << " ";
}
