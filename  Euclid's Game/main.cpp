#include <bits/stdc++.h>
#define ll long long
using namespace std;
string players[]={"Ollie","Stan"};
ll c = 0;
ll gcd(ll a , ll b) {
    if(a<b) swap(a,b);
    if(b==0) {
        return a;
    }
    else {
            ++c;
        return gcd(a%b,b);
    }

}

int main()
{
    ll a , b ;
    while(1){
        cin >> a >> b;
        if(!a&&!b) return 0;
        gcd(a,b);
        cout << players[c%2] << " wins"<< endl;
        c = 0;

    }



}
