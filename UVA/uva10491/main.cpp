#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;






main()
{
    ios::sync_with_stdio(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    double cows , cars , shows;
    while(cin >> cows >> cars >> shows){
        cout << fixed << setprecision(5) ;
        cout << ( cows ) /( cows+cars ) * cars / ( cars + cows - shows - 1  ) +
        (cars) / (cows+cars) * (cars-1) / (cars +cows - shows - 1) << endl;

    }











    return 0;
}
