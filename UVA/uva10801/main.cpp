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





int n,  source = 0, dest;
int tme[6];
vi floorsfromlift[6];
vi liftsfromfloor[100];

struct edge {
	int  to, w , prv;

	edge(int to, int w , int prv): to(to), w(w) , prv(prv) {}

	bool operator < (const edge & e) const {
		return w > e.w;
	}
};






ll Dijkstra( ll src, ll dest )	// O(E logV)
{
	vll dist(100, OO);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push( edge(0,0,-1) );

	while( !q.empty() ) {
		edge e = q.top();	q.pop();

		if(e.w > dist[e.to])	continue;
        if(e.to == dest) return dist[dest];
        int currentfloor=e.to; int currentcost=e.w;
        for(int i=0;i< liftsfromfloor[currentfloor] .size();++i){
                int currentlift = liftsfromfloor[currentfloor][i];
            for(int j=0;j<  floorsfromlift[currentlift].size();++j){ // to == floor
                int nxtfloor=floorsfromlift[currentlift][j];

                if( nxtfloor==currentfloor ) continue;

                if( e.prv == currentlift || e.prv == -1){
                    if( dist[nxtfloor] > currentcost + abs( currentfloor-nxtfloor )*tme[ currentlift ] ){
                        dist[nxtfloor] = currentcost + abs( currentfloor-nxtfloor )*tme[ currentlift ] ;
                        q.push(edge(nxtfloor,dist[nxtfloor],currentlift));
                    }
                }
                else{
                   if( dist[nxtfloor] > currentcost + abs( currentfloor-nxtfloor )*tme[ currentlift ]+60 ){
                        dist[nxtfloor] = currentcost + abs( currentfloor-nxtfloor )*tme[ currentlift ] +60;
                        q.push(edge(nxtfloor,dist[nxtfloor],currentlift));
                    }
                }

            }

        }

	}

	return OO;
}






int main()
{
    ios::sync_with_stdio(0);
  // cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;

    while(cin>>n>>dest){
        memset(floorsfromlift,0,sizeof(floorsfromlift));

        lp(i,0,n) cin>>tme[i];
        cin.get();
        lp(i,0,100) liftsfromfloor[i].clear();
        lp(i,0,n){
            string s; getline(cin,s);
            stringstream ss(s);
            int t;
            floorsfromlift[i].clear();
            while(ss>>t){
                floorsfromlift[i].pb(t);
                liftsfromfloor[t].pb(i);
            }
        }






        ll x = Dijkstra(0,dest);
        if(x==OO) cout<<"IMPOSSIBLE\n";
        else cout<<x<<"\n";
    }





    return 0;
}
