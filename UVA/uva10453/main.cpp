#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
//const long long OO = (long long) 1e18+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define lpr(i,a,n) for(long long i = a ; i >= n ; --i)
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


#define X real()
#define Y imag()
#define INF 1e9

using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m


string s;

int mem[1005][1005];

int dp(int l , int r){
    if(l>=r){
        return 0;
    }
    int &ans = mem[l][r];
    if(ans!=-1) return ans;
    int ans1 = OO;
    if(s[l]==s[r]) ans1 = dp(l+1,r-1);
    int ans2 = 1 + dp(l,r-1);
    int ans3 = 1 + dp(l+1,r);
    return ans = min(ans1,min(ans2,ans3));
}

vector<char> lft , rght;

void backTrack(int l , int r){
    if(l>=r) {
        if(l==r) lft.push_back(s[l]);
        return ;
    }
    int ans = mem[l][r];
    int ans1 = OO;
    if(s[l]==s[r]) ans1 = dp(l+1,r-1);
    int ans2 = 1 + dp(l,r-1);
    int ans3 = 1 + dp(l+1,r);
    if(ans==ans1){

        lft.push_back(s[l]);
        rght.push_back(s[r]);
        backTrack(l+1,r-1);
    }
    else if(ans == ans2){
        lft.push_back(s[r]);
        rght.push_back(s[r]);
        backTrack(l,r-1);
    }
    else {
        lft.push_back(s[l]);
        rght.push_back(s[l]);
        backTrack(l+1,r);
    }

}


int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
//     freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;


    while(cin>>s){

        memset(mem, -1 , sizeof mem);
        cout << dp(0,s.size()-1)<< " ";
        lft.clear();
        rght.clear();
        backTrack(0,s.size()-1);
        reverse( rght.begin(),rght.end() );

        for(char ch : lft) cout << ch;
        for(char ch : rght) cout << ch;
        cout << "\n";

    }





    return 0;
}
