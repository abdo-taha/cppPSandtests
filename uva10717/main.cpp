#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;

ll x , y , n , m , t , wanted ;
vll numbers;
stack<ll> ns ;

ll gcd( ll a , ll b ){
    ll aa = max(a,b) , bb = min( a , b) ;
    while(b!=0){
        ll t = a ;
        a = b ; b = t % b ;
    }
    return a ;
}
ll lcm(ll a , ll b){
    return a * b / gcd(a,b) ;
}


void dfs( ll pos , ll need ) {

    if(need == 0){
        ll mult = 1 , mult1 , mult2 ;

        stack<ll> tempstack ;
        while(!ns.empty()){
            t = ns.top() ;
            ns.pop() ;
            mult = lcm( mult , t ) ;
            tempstack.push(t);
        }
        while(!tempstack.empty()){
            ns.push(tempstack.top());
            tempstack.pop();
        }
        mult1 = wanted / mult ;
        mult1 *= mult ;
        mult2 = mult1 + mult ;
        if( mult1 > x  && mult1 <= wanted ) x = mult1 ;
        if( mult1 < y && mult1 >= wanted ) y = mult1 ;
        if( mult2 > x  && mult2 <= wanted ) x = mult2 ;
        if( mult2 < y && mult2 >= wanted ) y = mult2 ;
        return ;

    }
    if(pos == n) return ;

    dfs(pos+1,need) ;
    ns.push( numbers[pos]) ;
    dfs(pos+1,need-1) ;
    ns.pop();
}


main()
{
    ios::sync_with_stdio(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;
    while(1){
        numbers.clear() ;
        cin >> n >> m ;
        if(!n) break;
        lp(i,0,n){
            cin >> t;
            numbers.push_back(t);
        }
        lp(i,0,m) {
            x = 0 ;
            y = 100000000000000000;
            cin >> wanted ;
            dfs(0,4);
            cout << x << ' ' << y << endl;
        }
    }







    return 0;
}
