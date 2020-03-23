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


bool in( double px , double py , double x, double y , double r  ){
    return (px-x) * (px-x)  + (py-y) *(py-y) - r*r <= EPS;

}


int check( int i , int j , double x , double y , double r){
    int cnt = 0;
    double px = i , py = j ;
    if(in(px,py,x,y,r)) ++cnt;
    if(in(px+1,py,x,y,r)) ++cnt;
    if(in(px,py+1,x,y,r)) ++cnt;
    if(in(px+1,py+1,x,y,r)) ++cnt;
    return cnt;
}



int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
     //freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    string nl = "";
    int n;
    while(cin >> n){
        int cntSeg = 0 , cntIn = 0;
        double r = (2.0*n-1)/2.0;
        double x = n , y = n ;
        lp(i,0,2*n){
            lp(j,0,2*n) {
                if(check(i,j,x,y,r) == 4) ++cntIn;
                else if(check(i,j,x,y,r) > 0) ++cntSeg;
            }
        }
        cout << nl;
        cout << "In the case n = "<<n<<", "<<cntSeg
            <<" cells contain segments of the circle.\nThere are "<<cntIn
            <<" cells completely contained in the circle.\n";
        nl = "\n";
    }




    return 0;
}
