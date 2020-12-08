#include <iostream>
using namespace std;

#define ll long long

ll sum(ll n)
{
    if(n<10)
    return n;
    return sum(n/10) + n%10;
}

int main() {
	// your code goes here
	ll n;
	cin >> n;
	cout << sum(n);
	return 0;
}
