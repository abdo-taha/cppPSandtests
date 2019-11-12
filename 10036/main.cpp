#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long ) 1e18;
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
int n , k;

int numbers[10005];
int dp[10005][105];
int fxmd(int m )
{
    m %= k;
    m += k;
    m %= k;
    return m;
}
int dvs(int pos , int mod)
{
    mod = fxmd(mod);
    if(pos == n)
    {
       // cout << mod<<endl;
        if(mod) return 0;
        return 1;
    }
    int &ret = dp[pos][mod] ;
    if(ret != -1) return ret ;
    int ans1 , ans2 ;
    ans1 = dvs(pos+1, mod + numbers[pos] );
    ans2 = dvs(pos+1 , mod - numbers[pos] );

    return ret = ans1 || ans2 ;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "task.in" , "r" , stdin ) ;
    int T; cin >> T ;
    lp(ilp,0,T)
    {
        memset(dp,-1,sizeof dp );
        cin >> n >> k ;
        lp(i,0,n) cin >> numbers[i];
        dvs(1,numbers[0])? cout << "Divisible\n" : cout << "Not divisible\n";

    }



    return 0;
}
