#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
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

    cin.tie(0);
    // freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    while(1){
        int n; cin >> n;
        if(n==0) break;
        int x , y , z , l , ans , x1,x2,y1,y2,z1,z2;
        cin >> x >> y >> z >> l;
        x1=x;y1=y;z1=z;x2=x+l;y2=y+l;z2=z+l;
        ans = l*l*l;
        bool g = 1;
        lp(i,1,n){
            cin >> x >> y >> z >> l;

            x1 = max(x1,x); y1 = max(y,y1); z1 = max(z1,z);
            x2 = min(x2,x+l) ; y2 = min(y2,y+l); z2 = min(z2,z+l);


            if(x2<=x1||y2<=y1||z2<=z1) g = 0;
//            cout << x1 << " "<< y1 << " " << z1 << "        " << x2 << " " << y2 << " " << z2 << endl;
            ans = (x2-x1)*(y2-y1)*(z2-z1);
//            cout << ans << endl;

        }

        if(g) cout << ans;
        else cout << 0;
        cout <<"\n";

    }





    return 0;
}
