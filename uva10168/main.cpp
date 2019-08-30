#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef   long long ll;

vector<bool>  prime(10000005,1) ;





 vector<ll> ans ;

bool sumofprimes( ll n , ll d  ) {

    if(n < 2 ) return 0 ;
    if( d == 1 ) {

        if(prime[n]) {
           ans.push_back(n) ; return 1 ;
        }
        return 0 ;
    }

    else {
        for(ll i = n-2 ; i >= 2 ; --i ){
            if(prime[i]&& sumofprimes(n-i , d-1 )){

                ans.push_back(i) ; return 1 ;
            }

        }
        return 0 ;
    }

}


main()
{
    ios::sync_with_stdio(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;



    prime[0] = prime[1] = 0 ;
    for(ll i = 2 ; i * i < 10000000 ; ++i ) {
        if(prime[i]) for( ll j = i*2 ; j <= 10000000 ; j+=i ){
            prime[j] = 0 ;
        }
    }





    ll t ;



    while(cin >> t) {
           ans.clear() ;
           if(sumofprimes(t,4)) cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << endl;
           else cout << "Impossible.\n" ;
    }











    return 0;
}
