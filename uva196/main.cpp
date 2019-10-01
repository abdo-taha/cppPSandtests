#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;


ll g[1000][18500] ;
int done[1000][18500];

int n , m ;
vector<pair<int,int> > order ;
ll po(int a , int b){
    if(b==0) return 1 ;
    if(b == 1) return a ;
    if(b == 2) return a * a ;
    return a*a*a;
}
map< pair<int,int> , vector<pair<int,int> > > need;



pair<int,int> tocell( string s ){
    pair<int,int> n ;
    string s1 ="";
    string s2="";
    for(char c : s){
        if(c <='9' && c >= '0') s2 += c;
        else s1+= c;
    }

    stringstream ss(s2) ;
    ss >> n.first ;
    --n.first ;
    reverse(s1.begin(),s1.end());
    int i = 0 ,t , sum = 0;
    for(char c : s1){
        t = c-'A'+1;
        sum += t *  po(26,i) ;
        ++i;
    }
    --sum ;
    n.second = sum ;
    return n ;


}


void solve(int x , int y){

     ll sum = 0 ;

   for(ll i = 0 ; i < need[{x,y}].size() ; ++i ){

         sum += g[ need[ {x,y} ][i].first ][ need[ {x,y} ][i].second ];



    }

    g[x][y] = sum ;
    done[x][y] = 2;



}

void topo(int x , int y){

    order.clear();
    queue<pair<int,int> > q;
    q.push({x,y}) ;
    done[q.front().first][q.front().second] = 1 ;
    while(!q.empty()){

        order.push_back(q.front());

        rep(i,need[q.front()]){
            if( done[need[q.front()][i].first ][need[q.front()][i].second] ==0  ) {
                done[need[q.front()][i].first ][need[q.front()][i].second] = 1 ;
                q.push( need[q.front()][i] ) ;
            }
        }
        q.pop();



    }

    reverse(order.begin(),order.end());

    rep(i,order) {

        solve( order[i].first , order[i].second ) ;
    }





}


void dfs( int x , int y ){
    ll ans = 0 ;
    rep( i , (need[ {x,y} ]) ){
        int tx =  need[{x,y}][i].first ;
        int ty = need[{x,y}][i].second;
        if( done[tx][ty] != 2 )
            dfs(tx,ty ) ;
        ans += g[tx][ty];
    }
    g[x][y] = ans ;
    done[x][y] = 2 ;

}





main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    int nlp;
    cin >> nlp ;
//    scanf("%d",&nlp);
//    char tss[100] ;
    string ts;
    while(nlp--){
        need.clear();
        memset(done,0,sizeof(done));

        cin >> m >> n ;
//            scanf("%d%d" , &m , &n);
        lp(i,0,n) lp(j,0,m) {
            cin >> ts ;
//                scanf("%s",tss);


            if(ts[0] != '=' ) {
                stringstream ss(ts) ;
                ss>>g[i][j] ;
                done[i][j] = 2;
            }

           else {

                string s1 = "";
               lp(k,1,ts.size()){
                    if(ts[k]!='+' && k != ts.size()-1) s1 += ts[k] ;
                    else {
                        if(k == ts.size()-1) s1 += ts[k] ;
                        pair<int,int> p   = tocell(s1) ;
                       need[{i,j}].push_back( p);

                        s1 = "";

                    }
               }

           }

        }


        lp(i,0,n)lp(j,0,m)if(done[i][j]!=2){

           // topo( i , j) ;
           dfs(i,j);

        }


//
        lp(i,0,n){
            lp(j,0,m) {

                    cout << g[i][j] ;
//                printf("%d",g[i][j]);
                if(j != m-1) cout << " ";//printf(" ");//
            }
            cout << "\n";
//                printf("\n");
        }


    }







    return 0;
}
