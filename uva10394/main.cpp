#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef   long long ll;

vector<ll> prime(20000000,1) ;

vector<ll > ans ;


main()
{
    ios::sync_with_stdio(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    ll prv = 2;




    for( ll i = 2 ; i * i <= 20000000 ; ++i){
        if( prime[i] ) {
            for( ll j = i *2 ; j <= 20000000 ; j += i ) prime[j] = 0  ;
        }

    }





    lp(i,2,20000000){
        if(prime[i]) {
            if(i == prv +2 ) ans.push_back(prv);
            prv = i ;

        }

    }



    ll t ;

    while(cin >> t ) {
        --t ;
       cout << "(" << ans[t] << ", " << ans[t]+2 << ")\n";
    }









    return 0;
}
