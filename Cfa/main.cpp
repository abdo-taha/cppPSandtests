#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
//const long long OO = (long long) 1e18+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define lpr(i,a,n) for(long long i = a ; i >= n ; --i)
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


#define X real()
#define Y imag()
#define INF 1e9

using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m

int n , k;
vi nms;


int dp(int l , int r , int k){
    /// ////////////////////////////////////////
    if(k==1&&l<=r){
        int srch1 = 0,srch2=0;
        lp(i,l,r+1) srch1 += nms[i];
        srch1 /= (r+1-l);
        srch2 = srch1 -1 ;
        srch1 = *lower_bound(nms.begin()+l,nms.begin()+r,srch1);
        srch2 = *upper_bound(nms.begin()+l,nms.begin()+r,srch2);
        int ans1=0,ans2=0;
        lp(i,l,r+1){
            ans1 += abs(nms[i]-srch1);
            ans2 += abs(nms[i]-srch2);
        }
        return min(ans1,ans2);


    }
    if(l>=r){
        return OO;
    }

    int ans = OO;
    lp(i,l,r+1){
        ans = min(ans, dp(l,i,1) + dp(i+1,r,k-1) );
    }

    return ans;

}


int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
//     freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    while(cin>>n>>k){
        if(n==0&&k==0) break;
        nms.resize(n);
        lp(i,0,n) cin >> nms[i];

        cout << dp(0,n-1,k)  << endl;

    }






    return 0;
}
