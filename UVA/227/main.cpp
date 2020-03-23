#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long) 1e9+7;
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

char game[26][26];

pair<int,int> nxt(int x,int y,char ch){
    if(ch == 'A') --x;
    else if(ch=='B') ++x;
    else if(ch=='R') ++y;
    else if(ch == 'L')--y;
    else x = -1;
    if( x >= 0 && x < 5 && y >=0 && y<5 ) return {x,y};
    return {-1,-1};
}

int main()
{
    ios::sync_with_stdio(0);
   cin.tie(0);
  //    freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;
    string s;
    int x,y;
    int T=1;
    while(1){
        bool valid = 1;
        lp(i,0,5) {
         getline(cin,s);
            if(s=="Z") break;
         if(s.size()!=5) s += " ";
        // cout << s << endl;
          lp(j,0,5) game[i][j] = s[j];
        }
         if(s=="Z") break;
        lp(i,0,5)lp(j,0,5)if(game[i][j]==' ') {x=i;y=j;}
       // cout << x << " " << y << endl;
               while(cin>>s){

            for(char &ch: s) if(valid &&ch!='0'){
                pair<int,int> p = nxt(x,y,ch);
                if(p.ff==-1) valid = 0;
                else{
//                        cout << ch << " " ;
//                    cout << x << " " << y << " ";
                    swap( game[x][y] , game[p.ff][p.ss] );
                    x=p.ff; y=p.ss;
                   // cout << x << " " << y << endl;
                }

            }

            if(s[s.size()-1] == '0') break;
        }
        cout << "Puzzle #" << T++<<":\n";
        if(!valid){
            cout<<"This puzzle has no final configuration.\n\n";
            cin.get();
            continue;
        }

        lp(i,0,5){
            string ts="";
            lp(j,0,5) {cout<<ts<<game[i][j];ts = " ";}
            cout<<"\n";
        }
        cout<<"\n";
        cin.get();


    }




    return 0;
}
