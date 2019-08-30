#include <bits/stdc++.h>
using namespace std ;
#define ll  long long
#define lp(i,a,n) for(ll i = a;i<n;++i)

ll dp[1000] ;

ll fibo( int n) {
    if(n == 1 || n == 2) return 1 ;
    if(dp[n]!= 0) return dp[n];
    else return dp[n] = fibo( n-1  ) + fibo( n-2) ;

}


int main()
{
    ios::sync_with_stdio(0);

    while(1) {

        int n;
        cin >> n ;
        cout << fibo(n) << endl;
    }

    return 0;
}
