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


string s ;
ll md = 1000000007;

ll x[100005] ;

ll fn(int k){
    ll &ret = x[k];
    if( ret != -1 ) return ret ;

    ret = fn(k-1) + fn(k-2) ;
    ret %= md;



    return ret ;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "task.in" , "r" , stdin ) ;

    for(int i = 0 ; i < 100005 ; ++i) x[i] = -1 ;

    x[0] = 0;
    x[1] = 1;
    x[2] = 2 ;
    x[3] = 3 ;


    cin >> s;
    bool n = 0 , u = 0 , ok = 1;
    int t = 0;
    int ans = 1;
    for(int i = 0 ; i < s.size();++i){
        char ch = s[i];
        if(ch == 'm' || ch == 'w') ok = 0;
        if(n){
            if( ch =='n' && i != s.size()-1 ) ++t ;
            else {
                if( ch =='n' && i == s.size()-1 ) ++t ;
                ans *= fn( t ) ;
                t = 0 ;
                n = 0 ;
                if( ch == 'u' ) {
                    t = 1 ;
                    u = 1 ;
                }
            }

        }
        else if(u){

            if(ch == 'u'&& i != s.size()-1){
                ++t;
            }
            else {
                if( ch == 'u'&& i == s.size()-1 ) ++t;
                ans *= fn(t);
                t = 0 ;
                u = 0;
                if( ch == 'n'){
                    t = 1 ;
                    n = 1 ;
                }
            }
        }
        else if(ch == 'u'){
            u = 1 ;
            t =1 ;
        }
        else if(ch == 'n'){
            n = 1 ;
            t = 1 ;
        }

        ans %= md;
    }
    ok ? cout << ans << "\n" : cout << "0\n";









    return 0;
}
