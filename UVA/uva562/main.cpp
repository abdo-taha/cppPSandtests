
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

int dp[105][50005];

int n , sum ;
vi numbers;

int solve( int pos , int s ){

        if( dp[pos][s] != -1  ){
        return dp[pos][s] ;
    }
    if(pos == n  ) {

        int sum1 = sum - s ;
        return abs( sum1 - s ) ;
    }

   int a =  solve( pos +1 , s + numbers[pos] ) ;
   int b = solve( pos +1 , s ) ;
   return  dp[pos][s] =  min( a, b ) ;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    int nlp ; cin >> nlp ;
    while(nlp--){

        memset(dp,-1,sizeof(dp));

        sum = 0 ;
        cin >> n ;
        numbers.resize(n);
        rep(i,numbers) {cin >> numbers[i]; sum += numbers[i]; }
        cout << solve(0,0) << "\n";


    }





















    return 0;
}

