#include <bits/stdc++.h>
using namespace std ;
#define ll  long long
#define lp(i,a,n) for(ll i = a;i<n;++i)


string s ;

int main()
{
    ios::sync_with_stdio(0);
    ll c = 0;
    cin >> s;
    reverse(s.begin(), s.end());
    bool big = 0 ;
    for(char i : s){

        int k = i-'0' ;
        if(big) ++k;
        //cout << k << ' ';
        if( k == 10 ) big = 1 ;

        else if( k > 5 || ( k==5&& big) ) {
            big = 1 ;
            c += 10 - k ;
        }
        else {
            //if(big) ++c;
            big = 0 ;
            c += k;
        }
        //cout << c << endl;





    }
    if(big) ++c;
    cout << c << endl;



    return 0;
}
