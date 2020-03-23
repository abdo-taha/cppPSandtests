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


#define MX 105 /**   O(n)   if needed  O(sqrt n) bs only  mx = sqrt n */
bitset<MX> bs; // 00110....
vi primes; // 2,3,5,...
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MX; i++) {
		if (bs[i])
			primes.pb(i);
		for (int j = 0; j < primes.size() && i * primes[j] < MX; ++j) {
			bs[i * primes[j]] = 0;
			if (i % primes[j] == 0)
				break;
		}
	}
}

// prime factorization

void getPFs(ll x , vi &PFs) {
	for (ll i = 2; i * i <= x; ++i)
		while (x % i == 0)
			PFs.pb(i), x /= i;
	if (x > 1)
		PFs.pb(x);
}




int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
     //freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    int n , d;
//    sieve();

    while(cin >> n >> d){
        if(n==0&&d==0) break;
        vi pfs;
        lp(i,2,n+1) getPFs(i,pfs);
        map<int,int> cnt;
        for(int x : pfs) cnt[x]++;

        vi pfs1;
        getPFs(d,pfs1);
        bool k = 1;
        for(int x : pfs1) {
            --cnt[x];
            if(cnt[x]<0) k = 0;
        }
        ll ans = 1;
        for(auto p : cnt) ans *= p.ss+1;
        if(!k) ans = 0;
        cout << ans << "\n";



    }


    return 0;
}
