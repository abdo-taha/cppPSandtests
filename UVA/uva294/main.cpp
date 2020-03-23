#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9+7;
//const long long OO = (long long) 1e18+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
#define EPS 1e-9

#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define ff first
#define ss second
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;
typedef complex<double> point;
typedef pair<ll,ll> pll;




using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m





int main()
{
    ios::sync_with_stdio(0);
  // cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;
  //  auto stTime = clock();
  // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());


    int n;
    int l,r;
    cin>>n;
    while(n--){
        cin>>l>>r;
        int cnt = 0 , ans=0;


        lp(i,l,r+1){
            int tmp = 0;
            int j = 1;
            for( ; j * j < i ; ++j){
                if(i%j==0) tmp += 2;
            }
            if(j*j==i) ++tmp;
            if(tmp>cnt){cnt=tmp;ans=i;}

        }
        cout << "Between "<<l<<" and "<<r<<", "<<ans<<" has a maximum of "<<cnt<<" divisors.\n";
    }










//   cout << "\n\n\nExecution time: " <<
//		(clock() - stTime) * 1e3 / CLOCKS_PER_SEC << " ms" << endl;
    return 0;
}
