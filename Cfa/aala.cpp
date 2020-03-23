#include <bits/stdc++.h>

using namespace std;

const int N = (2<<20) + 4, mod = 1e9+7;

int n ;
long long A[N] , f[N];
long long c[2][N];

void make(int dir)
{
    if(dir)
    {
        reverse(A +1, A+n+1);
    }
    stack<int> s1;
    s1.push(0);
    for(int i = 1;i<=n;i++)
    {
        if(A[i] > A[i-1])
        {
            c[dir][i] =c[dir][i-1] + A[i];
        }
        else
        {
            while( s1.size() && A[s1.top()] > A[i] )
            {
                s1.pop();
            }
            int j =s1.top();
            c[dir][i] = c[dir][j] + (i-j)*A[i];
        }
        s1.push(i);
    }
    if(dir)
    {
        reverse(c[dir]+1 , c[dir]+n+1);
    }
}


int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
        cin>>A[i];
    make(0);
    make(1);
    long long sol = 0;
    int idx = 0;
    for(int i = 0;i<=n;i++)
    {
        if(c[0][i] + c[1][i+1] >sol)
        {
            sol = c[0][i] + c[1][i+1];
            idx = i;
        }
    }
    reverse(A+1, A+n+1);

    for(int i = 1 ; i < n+1 ; ++i) cout << c[0][i]<< " ";
//    long long nw = A[idx];
//    for(int j = idx;j>0;j--)
//    {
//        nw = min(nw , A[j]);
//        f[j] = nw;
//    }
//    nw = A[idx+1];
//    for(int j = idx+1;j<=n;j++)
//    {
//        nw = min(nw , A[j]);
//        f[j] = nw;
//    }
//    for(int i = 1;i<=n;i++)
//        cout<<f[i]<<" ";
    return 0;
}

