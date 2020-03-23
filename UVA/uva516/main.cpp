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


#define MX 32767 /**   O(n)   if needed  O(sqrt n) bs only  mx = sqrt n */
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

vll fact;
void factorization(ll n) //	 max n is 1e12
{	// O( sqrt(n) )

	fact.clear();

	for (ll i = 2; i*i <= n; ++i){
            int t=0;
		while (n % i == 0)
			++t, n /= i;
        if(t) {fact.push_back(t); fact.push_back(i);}
	}

		if (n > 1){
		fact.push_back(1);
                fact.push_back(n);


        }

}


int main()
{
    ios::sync_with_stdio(0);
  //  cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
 //   freopen( "input.txt" , "r" , stdin ) ;


    sieve();
    while(1){
        string s ;
        getline(cin,s);
        if(s[0]=='0')break;
        vi v;
        int t;
        stringstream ss(s);
        while(ss >> t){
            v.push_back(t);
        }
        int n =1;
        for(int i = 0; i< v.size();i+=2){
            n *= Pow(v[i],v[i+1]);
        }
        --n;
        factorization(n);
        reverse(fact.begin(),fact.end());
        s="";
        for(int tn : fact)  {cout << s<<tn  ; s=" ";}
        cout << "\n";
    }




    return 0;
}
