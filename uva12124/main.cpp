#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;

int n , budg , a , b , ans ;
string s1 , s2 ;
map< string , vector<pair<int,int> > > comps;

void solve(){

    int l = 0 , r = 1000000000 , md;
    while(l<=r){

        md = (l+r)/2;

        map< string , vector<pair<int,int> > > :: iterator it = comps.begin();
        int totalcost = 0 ;
        for( ; it != comps.end() ; ++it ){
            int tcost = 1000000;
            vector<pair<int,int> >::iterator jt = (it->second).begin() ;
            for(;jt != (it->second).end();++jt){
                if(jt->second >= md) tcost = min(tcost,jt->first);
            }
            totalcost += tcost ;
            if( totalcost > budg ) break ;


        }
        if( totalcost <= budg ) { ans= max(ans, md ) ; l = md +1 ; }
        else r = md -1 ;

    }





}





int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    int nlp;   cin >> nlp ;
    lp(ilp,0,nlp){

        comps.clear();
        ans = 0 ;
        cin >> n >> budg ;


        lp(i,0,n){

            cin >> s1 >> s2;
            cin >> a >> b ;
            comps[s1].push_back({a,b});


        }

        solve();
        cout << ans << endl;






    }





    return 0;
}
