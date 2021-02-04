//Minimum group flips to make all elements same
//We have to find minimum number of consecutive group flips required to make all elements of the array same.
//ex: arr[] = {1,0,0,0,1,0,0,1,1,1,1} output: 2
//TC : theta(n) AS: O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;

	char x = s[0];
	int one = 0, zero = 0;

	int i = 0;
	while (i < s.length())
	{
		if (i == 0)
		{
			if (s[i] == '1')
				one++;
			else
				zero++;

			i++;
			continue;
		}

		if (s[i] == x)
		{
			i++;
			continue;
		}
		else
			x = s[i];

		if (s[i] == '1')
			one++;
		else
			zero++;

		i++;
	}

	if (one < zero)
		cout << one;
	else
		cout << zero;
}
