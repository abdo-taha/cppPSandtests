#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long) 1e18+7;
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





ll n, m, source, dest, u, v, w, d;



struct edge {
	ll from, to, w;

	edge(ll from, ll to, ll w): from(from), to(to), w(w) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};

ll Dijkstra(vector< vector< edge > > adjList, ll src, ll dest = -1)	// O(E logV)
{
	ll n = adjList.size();
	vll dist(n, OO);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push( edge(-1, src, 0) );

	while( !q.empty() ) {
		edge e = q.top();	q.pop();

		if(e.w > dist[e.to])	continue;	// some other state reached better
        if(e.to == dest) return dist[dest];
       lp(i,0,adjList[e.to].size()){
           edge &ne = adjList[e.to][i];
			if( dist[ne.to] > dist[ne.from] + ne.w ) {
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push( ne );
			}
		}
	}

	return dest == -1 ? -1 : dist[dest];
}




int main()
{
    ios::sync_with_stdio(0);
  // cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;
    int T; cin >> T;
    lp(i,1,T+1){
        cin >> n>>m>>source>>dest;
        vector<vector<edge> > edges(n);
        lp(j,0,m){
            ll f,t,w;
            cin>>f>>t>>w;
            edge e1(f,t,w) , e2(t,f,w);
            edges[f].push_back(e1);
            edges[t].push_back(e2);
        }

        ll x = Dijkstra(edges,source,dest);
        cout << "Case #"<< i<<": " ;
        if(x==OO) cout << "unreachable";
        else cout << x;
        cout << "\n";

    }




    return 0;
}
