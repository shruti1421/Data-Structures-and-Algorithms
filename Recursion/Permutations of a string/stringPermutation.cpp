#include <iostream>
using namespace std;

void stringPerm(string s, int n, int i)
{
    if(n-1==i)
    {
        cout << s << " ";
        return;
    }
    
    for(int j=i;j<n;j++)
    {
        string s1=s;
        char x = s1[i];
        s1[i] = s1[j];
        s1[j] = x;
        
        stringPerm(s1,n,i+1);
    }
}

int main() {
	// your code goes here
	
	string s;
	cin >> s;
	
	int n=s.length();
	int i=0;
	
	stringPerm(s,n,i);
	return 0;
}
