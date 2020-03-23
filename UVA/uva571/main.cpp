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


int ca,cb,req;

string actions[] = { "fill B", "fill A", "empty B", "empty A", "pour B A", "pour A B" };
enum 		   {  FILL_B ,  FILL_A ,  EMPTY_B ,  EMPTY_A ,  POUR_B_A ,  POUR_A_B  };

struct state{int a, b, action;};
bool vst[1005][10005];
state prv[1005][1005];
queue<state> q;

void print(state st){
    if(st.a == 0 && st.b == 0) return;
    print(prv[st.a][st.b]);
    cout << actions[st.action]<<"\n";

}

void add_state(int a,int b,int action , state parent){
    if(vst[a][b]) return;
    vst[a][b] = 1;
    state st ={a,b,action};
    q.push(st);
    prv[a][b] = parent;

}


void bfs(){
    q = queue<state>();
    memset(vst,0,sizeof(vst));
    state t ={0,0,0};
    q.push(t);
    while(!q.empty()){
        state st = q.front(); q.pop();
        int a = st.a , b = st.b , aa , bb  ;
        if(b == req){
            print(st);
            cout<< "success\n";
            return;
        }

        add_state(a,cb,FILL_B,st);
        add_state(ca,b,FILL_A,st);
        add_state(a,0,EMPTY_B,st);
        add_state(0,b,EMPTY_A,st);
        aa = (a+b)<=ca?a+b:ca;
        bb = (a+b)<=ca?0:a+b-ca;
        add_state(aa,bb,POUR_B_A,st);
        aa = (a+b)>cb ? (a+b)-cb:0;
		bb = (a+b)>cb ? cb:a+b;
		add_state(aa, bb, POUR_A_B, st);


    }



}





int main()
{
    ios::sync_with_stdio(0);
  // cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;

  while(cin>>ca>>cb>>req) bfs();





    return 0;
}
