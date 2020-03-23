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

char board[9][9];

int xx[]={0,0,1,-1} , yy[] ={1,-1,0,0};

bool valid(int x , int y){
    return x >=0 && y >= 0 && x < 9 && y<9;
}

bool vst[9][9];

pii bfs(int x , int y){
    queue<pii> q;
    q.push({x,y});
    vst[x][y] = 1;
    bool black = 0 , white = 0;
    int cnt =0;
    while(!q.empty()){
        pii p = q.front(); q.pop();
        ++cnt;
        lp(i,0,4){
            int nxtx = p.ff + xx[i] , nxty = p.ss+ yy[i];
            if(!valid(nxtx,nxty)) continue;
            if( board[nxtx][nxty] == 'X' ) black = 1;
            else if( board[nxtx][nxty] == 'O') white = 1;
            else if(!vst[nxtx][nxty]){
                vst[nxtx][nxty] =1;
                q.push({nxtx,nxty});
            }
        }
    }
    int ff  = black&&white?2: black?0:1;
    return {ff,cnt};


}



int main()
{
    ios::sync_with_stdio(0);
  // cin.tie(0);
  //   freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;


  int T; cin >>T;
  while(T--){
        lp(i,0,9)lp(j,0,9) vst[i][j]=0;
      lp(i,0,9) lp(j,0,9) cin >> board[i][j];
        int cntb = 0 , cntw =0;
      lp(i,0,9)lp(j,0,9){
        if(board[i][j]=='X') ++cntb;
        else if(board[i][j]=='O') ++ cntw;
        else if(!vst[i][j]){
            pii p = bfs(i,j);
            //if(!p.ff)cout << p.ff << " " << p.ss << " "  << i << " " << j  <<endl;
            if(p.ff == 0) cntb += p.ss;
            else if(p.ff == 1 ) cntw += p.ss;
        }

      }
      cout << "Black " << cntb << " White " << cntw << "\n";
  }





    return 0;
}
