
#define MX 10000010 /**   O(n)   if needed  O(sqrt n) bs only  mx = sqrt n */
bitset<MX> bs; // 00110....
vi primes; // 2,3,5,...
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MX; i++) {
		if (bs[i])
			primes.pb(i);
		for (int j = 0; j < sz(primes) && i * primes[j] < MX; ++j) {
			bs[i * primes[j]] = 0;
			if (i % primes[j] == 0)
				break;
		}
	}
}

bool isPrime(ll n) {
	if (n <= MX)
		return bs[n];
	for (auto& p : primes)	// works for number up to (primes.back())^2
		if (n % p == 0)
			return false;
	return true;
}

ll  Pow(ll  B,ll  P){
    ll  R=1;
    while(P>0) {
        if(P&1) R=(R*B);
        P/=2;
        B=(B*B);
    }
    return R;
} //compute b^p



ll  GCD(ll  a,ll  b){
    while(b){
        b ^= a ^=b ^= a %=b; // xor exchange trick
    }
    return a;
}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){
    ll  R=1;
     while(P>0)  {
        if(P&1){
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
     }
     return (ll )R;
} //compute b^p%m


vll generate_divisors(ll n)	// O( sqrt(n) )
{
	vll v;
	ll i;
	for(i = 1 ; i*i <= n  ;++i)
		if(n%i == 0)
			v.push_back(i), v.push_back(n/i);

	if(i*i == n)
		v.push_back(i);

	return v;	// Not sorted
}

vll factorization(ll n) //	 max n is 1e12
{	// O( sqrt(n) )

	vll primes;

	for (ll i = 2; i*i <= n; ++i)
		while (n % i == 0)
			primes.push_back(i), n /= i;

		if (n > 1)
		primes.push_back(n);

	return primes;
}

// return a^-1 mod b, a and b must be coprime
ll inv(ll a, ll b) {
	return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

void extendedEuclid(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        d = a;
        return;
    }
    extendedEuclid(b, a % b);
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}


///////    p^n  == p^ ( n% m-1 ) %m  m is prime and p doesnt divide m


vi divs;
void getDivs(int x) {
	int i;
	for (i = 2; i * i < x; i++)
		if (x % i == 0)
			divs.pb(i), divs.pb(x / i);
	if (i * i == x)
		divs.pb(i);
}


const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

ll modExp(ll base, ll power) {
    if (power == 0) {
        return 1;
    } else {
        ll cur = modExp(base, power / 2); cur = cur * cur; cur = cur % MOD;
        if (power % 2 == 1) cur = cur * base;
        cur = cur % MOD;
        return cur;
    }
}

ll inv(ll base) {
    int g = MOD, r = base, x = 0, y = 1;
    while (r != 0) {
        int q = g / r;
        g %= r; swap(g, r);
        x -= q * y; swap(x, y);
    }
    return x < 0 ? x+MOD : x;
}

ll mul(ll A, ll B) {
	return (A*B)%MOD;
}

ll add(ll A, ll B) {
	return (A+B)%MOD;
}

ll dvd(ll A, ll B) {
    return mul(A, inv(B));
}

ll sub(ll A, ll B) {
    return (A-B+MOD)%MOD;
}
ll* facs = new ll[MX];
ll* facInvs = new ll[MX];

ll choose(ll a, ll b) {
	if (b > a) return 0;
	if (a < 0) return 0;
	if (b < 0) return 0;
    ll cur = facs[a];
    cur = mul(cur, facInvs[b]);
    cur = mul(cur, facInvs[a-b]);
    return cur;
}

void initFacs() {
	facs[0] = 1;
	facInvs[0] = 1;
	FOR(i, 1, MX) {
		facs[i] = (facs[i-1] * i) % MOD;
		facInvs[i] = inv(facs[i]);
	}
}


// prime factorization

vi PFs;
void getPFs(ll x) {
	for (ll i = 2; i * i <= x; ++i)
		while (x % i == 0)
			PFs.pb(i), x /= i;
	if (x > 1)
		PFs.pb(x);
}



