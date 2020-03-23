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


ll po( ll a, ll b , ll m ){
    if( b == 0  ) return 1 ;
    if( b == 1) return a ;
    if( b%2 ) return (a * po( a*a % m , b/ 2 , m) )%m ;
    return (po(a*a%m , b/2 , m) ) %m ;

}


enum colors { white , black };;

int n , a , b , m;

vi currentBlack , bestBlack ;
vector<vi> adjlist ;
vector<colors> currentColors ;

bool canBeBlack( int x ){
    if(currentColors[x]==black) return 0 ;
    for(int node : adjlist[x] ){
        if(currentColors[node] == black) return 0 ;
    }
    return 1 ;
}


void backTrack( int cur ){

    if( currentBlack.size() > bestBlack.size()  ) bestBlack = currentBlack;

    if( bestBlack.size() > currentBlack.size() + n+1 - cur  ) return ;



    lp(i,cur,n+1) if(canBeBlack(i)) {

        currentBlack.pb(i);
        currentColors[i] = black;
        backTrack(cur+1) ;
        currentBlack.pop_back();
        currentColors[i]=white;

    }
    return ;
//
//    if(cur == n+1 ) {
//            if(currentBlack.size() > bestBlack.size()) bestBlack= currentBlack;
//        return ;
//    }
//
//    int mxb = n+1 - cur ;
//    if( bestBlack.size() > mxb + currentBlack.size() ) return ;
//
//    if(canBeBlack(cur)){
//        currentColors[cur]=black;
//        currentBlack.pb(cur);
//        backTrack(cur+1);
//        currentBlack.pop_back();
//        currentColors[cur]=white;
//
//    }
//    backTrack(cur+1);


}




int main()
{
    ios::sync_with_stdio(0);
//    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    int nlp ; cin >> nlp ;
    while(nlp--){

        currentBlack.clear();
        bestBlack.clear() ;
        adjlist.clear();
        currentColors.clear();
        cin >> n >> m ;
        adjlist.resize(n+1);
        currentColors = vector<colors>(n+1,white) ;
        lp( i,0,m ){
            cin >> a >> b ;
            adjlist[a].pb(b);
            adjlist[b].pb(a);
        }

        backTrack(1);
        cout << bestBlack.size() << endl;
        string space = "";
        for( int x : bestBlack ) cout << space <<x , space = " "  ;
        cout << endl;


    }








    return 0;
}
