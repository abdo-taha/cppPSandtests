#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll rem(ll b,ll p,ll m) {
    if( b == 0) return 0;
    if(p==0) return 1;
    if(p==1) return b % m;
    ll oldb = b;
    b %= m;
    b *= b;
    b %= m;
    if(p%2) {
        return ((rem(b,p/2,m)%m) * (rem(oldb,1,m)%m) )%m;
    }
    else {
        return rem(b,p/2,m);
    }

}


int main()
{
    ios::sync_with_stdio(0);
    ll b , p , m , c = 0;
    while(cin >> b) {
        cin >> p >> m ;

        cout << rem(b,p,m)<<endl;

    }


    return 0;
}
