#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;

using namespace std;

string s ;
bool isplandriom(string s1){
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    return s1 == s2;
}

ll mem[62][62];

ll dp(int first , int last){
    if(last==first) return 1;
    if(last < first) return 0;
    ll &ret = mem[first][last];
    if(ret!=-1) return ret;
    ll a = dp(first+1,last);
    ll b = dp(first,last-1);
    ll c = dp(first+1,last-1);
    ret = a+b-c;
    if(s[first]==s[last]) ret += 1+c;

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

   int T ;
   cin >> T;
   while(T--){
        lp(i,0,62)lp(j,0,62) mem[i][j]=-1;
    cin >> s;
    cout << dp(0,s.size()-1)<<"\n";

   }




    return 0;
}
