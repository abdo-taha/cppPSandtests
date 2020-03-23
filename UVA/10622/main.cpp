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

vi factorization(ll n) //	 max n is 1e12
{	// O( sqrt(n) )
    vi v;
	for (ll i = 2; i*i <= n; ++i){
           // cout << n << " " <<i << " ";
        int t = 0;
		while (n % i == 0){

            n/=i;
            ++t;
		}

        if(t !=0) v.push_back(t) ;

	}
    if (n > 1)
        v.push_back(1);

	return v;
}


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;
   ll x;
    while(cin >> x){
        if(x==0) break;
        vi v = factorization(abs(x));
         int ans=1;
        if(v.size()==1) ans = v[0];
         else{
            ans = v[0];
            rep(i,v) ans = GCD(ans,v[i]);
         }
         if( x <0 ){
            if(ans&1) cout << ans<<"\n";
            else {
                while(ans > 1 && ans%2==0 ) ans/=2;
                cout << ans << "\n";
            }
         }
         else cout << ans <<"\n";


    }





    return 0;
}
