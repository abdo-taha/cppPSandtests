#include <bits/stdc++.h>
using namespace std;
const int OO = (int ) 2*1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;


int x , n , t , m , a , b;

vi   times ,costs;
vvi roads ;

int mn[1005][1005];


void solve( int pos , int tme , int cst , int prv){

    cst += costs[pos];
    //cout << pos << " "<<tme<<" " << cst <<" " <<prv  <<endl;
    if( tme > x ) return ;
    if( cst > mn[pos][tme]) return ;
    mn[pos][tme] = cst ;

    rep(i, roads[pos] ){
        solve( roads[pos][i] , tme + times[pos] + t , cst, pos ) ;
    }
    solve( pos , tme + times[pos] , cst, pos ) ;


}

int main()
{
    ios::sync_with_stdio(0);
//    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;
    int a = 2000000000;
    cout << a ;



    return 0;
}
