/*
Rules:
1. Only one disc moves at a time
2. No larger disc above smaller disc even not in intermediate state
3. Only top disc of a tower can be movied

total moves = pow(2,n) - 1

O(2^n)
*/


#include <iostream>
using namespace std;

void TOH(int n, char a, char b, char c)
{
    if(n>1)
    {
        TOH(n-1,a,c,b);
        cout << "\nmove disc " << n << " from " << a << " to " <<c ;
        TOH(n-1,b,a,c);
    }
    if(n==1)
    cout << "\nmove disc " << n << " from " << a << " to " <<c ;
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	
	char a='A',b='B',c='C';
	
	TOH(n,a,b,c);
	
	return 0;
}
