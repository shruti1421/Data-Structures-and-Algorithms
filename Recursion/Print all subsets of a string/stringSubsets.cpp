//Given a string print all subsets of it (in any order)
// I/P: s = "ABC"
// O/P: "","A","B","C","AB","BC","AC","ABC"

#include <iostream>
using namespace std;

void printSubsets(string s, string str, int i)
{
    if(i==s.length())
    {
        cout << str << " ";
        return;
    }
    
    printSubsets(s,str,i+1);
    printSubsets(s,str+s[i],i+1);
    
}

int main() {
	// your code goes here
	string s;
	cin >> s;
	int i=0;
	string str="";
	printSubsets(s,str,i);
	return 0;
}
