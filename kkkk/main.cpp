#include <bits/stdc++.h>
using namespace std ;
#define ll  long long
#define lp(i,a,n) for(ll i = a;i<n;++i)
int n , p , t;
vector<int> mv , rmv;
bool dfs(int pos , int i  ){
    if(i == n -1 )
        return 1;
        cout << pos << endl;

    int a = ( pos + mv[i] )% n ;
    int b = ( pos - mv[i] ) ;
    if(b < 0) b += n;
    bool aa = 0 , bb = 0;
    if(a != rmv[i] ) {
            if(a > rmv[i]) --a;
        aa = dfs( a , i+1 ) ;

    }

    if(b != rmv[i] ){
            if(b > rmv[i]) --b;
        bb = dfs( b , i+1 );
    }
    return aa || bb ;

}


int main()
{
    ios::sync_with_stdio(0);
    cin >> n>> p ;
    lp(i,1,n){
        cin >> t;
        mv.push_back(t);
    }
    lp(i,1,n){
        cin >> t;
        rmv.push_back(t);
    }

    if(dfs(p,0)) cout <<"Yes\n" ;
    else cout << "No\n";


    return 0;

}
