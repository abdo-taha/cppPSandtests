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

int ln , n , t;

int pos[55];
int mem[55][55];


int dp(int first , int last){
    if(last < first) return 0;
    if(last == first){
        if(first == 0 || first == n+1) return 0 ;
        return pos[last+1] - pos[first-1];
    }
    int &ans = mem[first][last];
    if(ans != -1) return ans;
    ans = 10000000 ;
    lp(i,first,last+1){
        ans = min(ans, pos[last+1] - pos[first-1] + dp(first,i-1) + dp(i+1,last) );
    }

    return ans;
}


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;



    while(cin >> ln){
        if(ln == 0) break;
        memset(mem,-1,sizeof mem);
        cin >> n ;
        lp(i,1,n+1) cin >> pos[i];
        pos[n+1] = ln;
        cout <<"The minimum cutting is " <<dp(1,n) << ".\n";

    }




    return 0;
}
