//https://www.interviewbit.com/problems/noble-integer/
int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());

    for(int i=0;i<A.size();i++)
    {
        if(A[i]==A.size()-i-1&&((i+1<A.size()&&A[i+1]!=A[i])||i+1>=A.size()))
            return 1;
    }

    return -1;
}
