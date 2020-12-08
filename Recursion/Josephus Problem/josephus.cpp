/*
There are n people in a circle we have to kill kth person in each iteration.

Time Complexity: Theta(n)
*/

#include <iostream>
using namespace std;

int jos(int n, int k)
{
    if(n==1)
    return 0;
    else return (jos(n-1,k)+k)%n;
}

int main() {
	// your code goes here
	int n,k;
	cin >> n >> k;
	
	cout << jos(n,k);
	return 0;
}
