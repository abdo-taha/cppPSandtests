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

ll mem[305][305];

string s;
bool ispalindrome(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());
    return s2 == s;
}

ll dp(int first , int last){ /// how many palindromes cant it make

    if(s[first] != s[last]) return 0;
    if(first>= last) return 1;
    if(last-first==1) return 0;
    if((last-first)%2) return 0;

    ll &ans = mem[first][last];
    if(ans!=-1) return ans;
    ans = 0;
   // string ts = s.substr(first,last-first+1);

    //if(ispalindrome(ts)) ++ans;
    lp(i,first+2,last+1){
        if( s[i]==s[first] ) ans +=  dp(first+1,i-1) * dp(i,last);
        ans%= 1000000000;

    }
    return ans;

}


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


while(cin >> s){
    int sz = s.size();
    lp(i,0,sz+1)lp(j,0,sz+1) mem[i][j]=-1;
    cout << dp(0,s.size()-1)<<endl;
}




    return 0;
}
