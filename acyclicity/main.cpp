#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
int n , m ,a,b ;
bool check = 0 ;
vector<vi > verts;
map <int,bool> visited;

void dfs( int x  , int sourse ){
    visited[x] = 1 ;
    int sz = verts[x].size();
//    cout << x << endl;
    lp(i,0,sz){
//        cout << x << ' ' << verts[x][i]<<endl;
        if(!visited[ verts[x][i] ] ) dfs( verts[x][i] , sourse );
        else {
            check = verts[x][i] == sourse ? 1 : check ;
        }
    }
//    cout << endl;

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
        if(!visited[i] )  dfs( i , i ) ;
    }
    cout << check ;


    return 0;
}
