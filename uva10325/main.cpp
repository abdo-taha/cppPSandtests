#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef   long long ll;

vector<ll> numbers ;
ll sum , n, m , t ;





ll gcd(ll x, ll y) {
    ll a = max(x,y) , b = min(x,y) , t ;
    while(b!=0) {
        t = b ; b = a%b ; a = t ;
    }
    return a ;
}

ll lcm( ll x , ll y ){
    return x * y / gcd(x,y) ;
}



void dfs( ll pos , ll dv , bool eo ) {

    if(pos == m){

        if(eo) sum += n/dv ;
        else sum -= n/dv ;
        return ;
    }
    if(dv>n) return ;

    dfs( pos +1 , dv , eo ) ;
    dfs( pos +1 , lcm( dv , numbers[pos] ) , !eo );

}




main()
{
    ios::sync_with_stdio(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    while(cin >> n >> m ){
        sum = 0 ;
        numbers.clear() ;

        lp(i,0,m){
             cin >> t ; numbers.push_back(t);
        }

        dfs(0,1,1) ;
        cout << sum << endl;


    }





    return 0;
}
