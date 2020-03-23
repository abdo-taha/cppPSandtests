#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
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

using namespace std;

int n, m;

int prices[102] , fv[102];
int mem[10202][102];

int dp( int money , int pos ){

    if( money > 10200 ) return -1000;
    if( pos >= n ){
        if( money - m <= 200 && money> 2000 || money <= m ) return 0;
        return -1000;
    }



    int &ans = mem[money][pos];
    if(ans!=-1) return ans;
    int a = 0 , b = 0;
    a = dp(money+prices[pos],pos+1) + fv[pos];
    b = dp(money , pos+1);
    return ans = max(a,b);

}

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    while(cin >> m){
        cin >> n;
        lp(i,0,n) cin >> prices[i] >> fv[i];
        memset(mem,-1,sizeof mem);
        cout << dp(0,0) << "\n";

    }



    return 0;
}
