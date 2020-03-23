
#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;

string s1 , s2 ;
int dp[105][105] ;

int solve( int p1 , int p2  ){

    if( dp[p1][p2] != -1 ) return dp[p1][p2] ;
    if( p1 >= s1.size() || p2 >= s2.size() ) return 0 ;

    int a = solve( p1 +1 , p2+1 ) ;
    int b = solve( p1 , p2+1  ) ;
    int c = solve( p1+1,p2 );
    int d = 0 ;
    if( s1[p1] == s2[p2] ) d = solve(p1+1,p2+1) +1 ;

    return dp[p1][p2] = max( a , max( b , max( c , d ) ) ) ;


}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;
    int n = 1 ;

    while(1){
        cin >> s1 ;
        if(s1 == "#") break ;
        cin >> s2 ;
        memset(dp,-1,sizeof(dp));
        cout << "Case #" << n   <<": you can visit at most " << solve(0,0) << " cities.\n" ;
        ++n;


    }
















    return 0;
}

