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


int numbers[10005];
int n,k;

int mem[10005][25][25];
int dp(int first , int k1, int k2){
    int last = n-1 - first - k1 + k2;
    if(first >= last) return 0;
    if(k1+k2 > k) return OO;

    int &ret = mem[first][k1][k2];
    if(ret =! -1) return ret;

    if(numbers[first]!=numbers[last]){
       ret = dp(first,k1+1,k2)+1 ;
       ret = min(ret,1+dp(first+1, k1,k2+1 ));
    }
    else
        ret = dp(first+1,k1,k2);
    return ret;



}
int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    int nlp; cin >> nlp;
    lp(ilp,0,nlp){
        memset(mem,-1,sizeof mem);
        cin >> n >> k;
        lp(i,0,n) cin >> numbers[i];
        int a = dp(0,0,0);



        cout << "Case " << ilp+1 <<": " ;
        a == 0 ? cout << "Too easy\n" : a > k ? cout << "Too difficult\n" : cout << a << "\n";


    }




    return 0;
}
