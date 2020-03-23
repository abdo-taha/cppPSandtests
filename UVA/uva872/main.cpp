#include <bits/stdc++.h>
using namespace std;
//const int OO = (int) 1e9+7;
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

vector<char> alpha;
map<char,vector<char>> before;
map<char,int> vst;

vector<string> ans;
vector<char> tmp;
void dfs(int lvl = 0 ){

    if(lvl==alpha.size()){
            string s = "";
        for(char tch:tmp) s += tch;
        ans.push_back(s);
        return ;
    }
    lp(i,0,alpha.size()){
        char ch = alpha[i];
        if(vst[ch]) continue;
        bool k = 1;
        for(char to : before[ch] ) if(vst[to]) k = 0;
        if(!k) continue;
        vst[ch]=1;
        tmp.push_back(ch);
        dfs(lvl+1);
        tmp.pop_back();
        vst[ch] = 0;
    }



}


int main()
{
    ios::sync_with_stdio(0);
   cin.tie(0);
    // freopen( "output.txt" , "w" , stdout ) ;
  //  freopen( "input.txt" , "r" , stdin ) ;


   int T; cin >> T;
    cin.get();
    string sp = "";
    while(T--){
    alpha.clear();
    before.clear();
    vst.clear();
    ans.clear();
    string s;
    cin.get();
    getline(cin,s);
    //cout <<"0"<<s<<endl;
    for(char ch : s) if(ch != ' ') alpha.push_back(ch);
    getline(cin,s);
//    cout << "0"<<s<<endl;
    stringstream ss(s);
    while(ss>>s){
        before[s[0]].push_back(s[2]);
    }
    dfs();

    cout << sp;
    if(ans.size()){
        for(string ts : ans) {
            string spc = "";
            for(char tch : ts) {
              cout << spc<<tch ;
              spc = " ";
            }
            cout << "\n";

        }
    }
    else{
        cout << "NO\n";
    }

    sp = "\n";



   }


    return 0;
}
