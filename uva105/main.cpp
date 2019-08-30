#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
map<int,int> g ;

int main()
{
    ios::sync_with_stdio(0);
    //freopen( "output.txt" , "w" , stdout ) ;

    int a , h , b , biggest = 0  ;
    while(cin >> a >> h >> b){
        lp(i,a,b) if( h > g[i] ) g[i] = h ;
        biggest = max( biggest , b ) ;
    }
    int t = -1 ;
    bool spc = 0;
    lp(i,1, biggest +5){
        if(g[i]!= t){
            t = g[i];
            if(spc) cout << ' ';
            cout << i << ' ' << t ;
            spc = 1 ;

        }
    }
    cout << endl;






    return 0;
}
