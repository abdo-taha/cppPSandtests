#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
ll order = 1;
map<string,ll> ton ;
map<ll,ll> parent , sons;
ll tonumber(string s){
    if(ton[s] == 0){
        ton[s] = order ;
        ++order ;
    }
    return ton[s];

}
ll grand(ll x){
    while(parent[x] != x) x = parent[x] ;
    return x;

}


ll relation( ll a , ll b ) {
    if(parent[a] == 0 && parent[b] == 0) {
        parent[a] = b ;
        parent[b] = b;
        sons[b] = 2 ;
        if(a==b) --sons[b];
        return sons[b];
    }
    else if( parent[a] == 0  ){
        parent[a] = a;
        ll gf = grand(b) ;
        parent[a] = parent[b] = gf ;
        ++sons[gf] ;
        return sons[gf] ;
    }
    else if(parent[b] == 0) {
        parent[b] = b;
        ll gf = grand(a) ;
        parent[b] = parent[a] = gf ;
        ++sons[gf] ;
        return sons[gf] ;
    }
    else {
        ll gf1 = grand(a) , gf2 = grand(b) ;
        parent[gf2] = gf1 ;
        if(gf1 != gf2) sons[gf1] += sons[gf2] ;
        return sons[gf1] ;
    }


}




int main()
{
    freopen("output.txt" , "w",stdout);
    ll nlp ;
    cin >> nlp;
    lp(ilp,0,nlp){
        order = 1 ;
        ton.clear();
        sons.clear();
        parent.clear();
        ll n , a , b ;
        string s1 , s2 ;

        cin >> n;
        lp(i,0,n){
            cin >> s1 >> s2 ;
            a = tonumber(s1) ;
            b = tonumber(s2) ;
            cout << relation(a,b) << endl;
        }

    }




    return 0;
}
