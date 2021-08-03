//https://www.hackerrank.com/challenges/sherlock-and-permutations/problem
#include <bits/stdc++.h>

using namespace std;

const long long int mod=1000000007;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */
 
long long int factorial(long long int n)
{
   if(n==1||n==0)
     return 1;
   return ((n%mod)*(factorial(n-1)%mod))%mod; 
}

long long int power(long long int n, long long int m)
{
   long long int res=1;
   while(m>0)
   {
       if(m%2!=0)
         res=((res%mod)*(n%mod))%mod;
       m/=2;
       n=((n%mod)*(n%mod))%mod;
   } 
   
   return res;
}

long long int moduloInverse(long long int n)
{
    return power(n,mod-2);
}

long long int solve(long long int n,long long int m) {
     long long int places=n+m-1;
      m--;
      
      long long int  ans;
      
      long long int factM=factorial(m),factN=factorial(n);
      
      long long int inverse=moduloInverse((factM*factN)%mod);
      
      ans=((factorial(places)%mod)*(inverse%mod))%mod;
     
     return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
        long long int n = stoll(first_multiple_input[0]);

        long long int m = stoll(first_multiple_input[1]);

        long long int result = solve(n, m);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

