#include<iostream>
using namespace std;

int a[100][100];
int N;

bool isAttacked(int N, int n, int a[][100], int x, int y)
{
    if(N==1)
    return true;
    for(int i=0;i<N;i++)
    {
        if(a[i][y]==1)
        return false;
    }
    for(int i=0;i<N;i++)
    {
        if(a[x][i]==1)
        return false;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if((i+j)==(x+y))
            {
                if(a[i][j]==1)
                return false;
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if((i-j)==(x-y))
            {
                if((a[i][j])==1)
                return false;
            }
        }
    }
    return true;
}

bool nQueens(int N, int n, int a[][100])
{
    if(n==0)
    return true;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(isAttacked(N,n,a,i,j))
            {
                a[i][j]=1;
                int x=n;
                if(nQueens(N,n-1,a)==0)
                {
                    a[i][j]=0;
                    n=x;
                }
                else
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> N;
    n=N;
    
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        a[i][j]=0;
    }

    if(nQueens(N,n,a))
    {
        cout << "YES\n";
         for(int i=0;i<N;i++)
        {
         for(int j=0;j<N;j++)
         cout<< a[i][j] << " ";
         cout << "\n";
        }
        
    }
    else
    cout << "NO";

    return 0;
}
