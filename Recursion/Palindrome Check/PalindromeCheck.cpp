//To check if a string is palindrome or not using recursion

#include <iostream>
using namespace std;

bool IsPalindrome (string str, int start, int end)
{
    if(start>=end)
    return true;
    return ((str[start]==str[end])&&(IsPalindrome(str, start+1, end-1)));
}

int main() {
	// your code goes here
	string str;
	cin >> str;
	int start=0,end=str.length();
	
	cout << IsPalindrome(str, start, end-1);
	
	return 0;
}
