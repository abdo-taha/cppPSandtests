#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
#define EPS 1e-9
#define INF 1e9
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
typedef pair<int,int> pii;


using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m


 map<int,bool> dnttake;


struct Unionfind {
    vi rnk , parent ;
    int forests ;
    Unionfind(int n){
        rnk =vi(n), parent = vi(n);
        forests = n;
        lp(i,0,n) parent[i] = i , rnk[i] = 1;

    }
    int find_set(int x) { // return greatest father
        if( x == parent[x] ) return x;
        else
            return parent[x] = find_set(parent[x]) ;

    }
    void link(int x , int y){ // link two trees
        if(rnk[x] > rnk[y]) swap(x,y) ;
        parent[x] = y ;
        if(rnk[x] == rnk[y]) ++rnk[y];

    }
    bool union_sets(int x , int y){
        x = find_set(x) , y = find_set(y);
        if(x != y) {
            link(x,y);
            --forests;

        }
        return x != y;

    }


    bool same_set(int x , int y){
        return find_set(x) == find_set(y);
    }
    vector< vi > connected_components(){
        vector< vi > l(parent.size());
        lp(i,0,parent.size()){
            l[find_set(i) ] .push_back(i);
        }
        return l;
    }





};



vector<pair<int,pair<int,int>>>  edgelist ;

pair<int , vector<int> > MST_Kruskal( int n  ) {
    Unionfind uf(n);
    vector<int> edges ;
    int mstcost = 0;

    lp(i,0,edgelist.size()){
        int cost = edgelist[i].ff , from = edgelist[i].ss.ff , to=edgelist[i].ss.ss;
        if(dnttake[i]) continue;
        if( uf.union_sets(from , to) ){

            mstcost += cost;
            edges.push_back(i);
        }
    }

    if( edges.size() != n-1 ) return make_pair( -OO , vector<int>() ) ;

    return make_pair( mstcost , edges ) ;


}





int main()
{
    ios::sync_with_stdio(0);
   cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;
  int T; cin >>T;
  lp(ilp,1,T+1){
    int v , e ;
    cin >> v>>e;
    dnttake.clear();
    edgelist.clear();
    lp(i,0,e){
        int f,t,w;
        cin>>f>>t>>w;
        --f;--t;
        edgelist.push_back( { w,{f,t} } );

    }
    sort( edgelist.begin() , edgelist.end() );

    auto p = MST_Kruskal(v);
    if(p.ff == -OO){
        cout<<"Case #"<< ilp<< " : No way\n";
    }

    else{
        int ans = OO;
        for( int&no:p.ss){
            dnttake[no]=1;
            int tm = MST_Kruskal(v).ff ;
            if(tm!= -OO) ans = min( ans,tm );
            dnttake[no] =0;
        }
        if(ans==OO ){
            cout<<"Case #" << ilp  << " : No second way\n";
        }
        else{
            cout<<"Case #" << ilp << " : "<< ans<<"\n";
        }

    }
  }

    return 0;
}
