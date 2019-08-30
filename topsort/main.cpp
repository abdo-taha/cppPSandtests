#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
int n , m ,a,b ;
vector<vi > verts;
map <int,bool> visited;
vi ans;

void dfs( int x  ){
    visited[x] = 1 ;
    int sz = verts[x].size();

    lp(i,0,sz){
        if(!visited[ verts[x][i] ]  ){
            dfs( verts[x][i]   ) ;
        }
    }
    ans.push_back( x ) ;


}


int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m ;
    verts= vector<vi>(n+1);
    lp(i,0,m){
        cin >> a >> b;
        verts[a].push_back(b);
    }
    lp(i,1,n+1){
        if(!visited[i])dfs( i );
    }

    reverse( ans.begin() , ans.end() ) ;
    lp( i , 0 , n) cout << ans[i] << ' ' ;



    return 0;
}
