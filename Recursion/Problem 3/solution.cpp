#include <iostream>
using namespace std;

int max(int a, int b, int c)
{
    if(a>b)
    {
        if(a>c)
        return a;
        return c;
    }
    else
    {
        if(b>c)
        return b;
        return c;
    }
}

int maxCuts(int n, int a, int b, int c)
{
    if(n==0)
    return 0;
    if(n<0)
    return -1;
    if(max(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c))==-1)
    return -1;
    return max(maxCuts(n-a,a,b,c),maxCuts(n-b,a,b,c),maxCuts(n-c,a,b,c)) +1;
}

int main() {
	// your code goes here
    int a,b,c,n;
    cin >> n >> a >> b >> c;
    cout << maxCuts(n,a,b,c);
}
