#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long) 1e15;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;
typedef complex<double> point;


using namespace std;
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m



struct cube{
    ll a , b , c,d;
};

vector<cube> t;
bool srt(const cube& c1 , const cube& c2){
    if(c1.a<c2.a) return 1;
    if(c1.a>c2.a) return 0;
    else{
        if(c1.b < c2.b) return 1;
        else if(c1.b>c2.b) return 0;
        else{
            if(c1.c<c2.c) return 1;
            else if(c1.c>c2.c) return 0;
            else{
                return c1.d<c2.d;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
  //  cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
 //   freopen( "input.txt" , "r" , stdin ) ;

    for(ll i = 6;i <=200;++i){
        for(ll j = 2; j < i ; j++){
            for(ll k = 2 ; k <= j ;++k){
                ll x = Pow(i,3) - Pow(j,3) - Pow(k,3);
                if(x <= 1 ) continue;
                ll tx = (ll)cbrt(x);
                if(Pow(tx,3) != x ) continue;
                x = tx;
                if(Pow(j,3) + Pow(k,3)+Pow(x,3)==Pow(i,3) && x <= k){
                    cube tc;
                    tc.a=i; tc.b=x;tc.c=k;tc.d=j;
                    t.push_back(tc);
                }
            }
        }
    }
    sort(t.begin(),t.end(),srt);
    for(cube tc: t){
        cout << "Cube = "<< tc.a << ", Triple = ("<< tc.b << ","<< tc.c<<","<<tc.d<<")"<<endl;
    }






    return 0;
}
