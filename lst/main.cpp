#include <bits/stdc++.h>
using namespace std ;
#define ll  long long
#define lp(i,a,n) for(ll i = a;i<n;++i)


string s ;
int lst = 2;

int main()
{
    ios::sync_with_stdio(0);
    ll c = 0;
    cin >> s;
    for(char i : s){
        int k = i-'0' ;
        if(k == 5){
            if(lst == 2)
                c+=5;
            else
                c+=4;
        }
        else if(k == 4){
            if(lst == 2)
                c += 6;
            else
                c += 4;
        }
        else if(k < 4){
            if(!lst)
                c++;
            c+= k, lst = 2;

        }
        else c+= (9 + lst -k), lst = 0;

    }
    cout << c << endl;
    return 0;
}
