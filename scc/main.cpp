#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
int  n , m , t , x= 1 , y = 1 ;
priority_queue<int> xs , ys ;


int main()
{
    ios::sync_with_stdio(0);
    int nlp ;
    cin >> nlp;
    lp(ilp,0,nlp){
        x = 1 , y = 1 ;
        cin >> n >> m ;
        --n; --m;
        lp(i,0,n) {
            cin >> t ;
            xs.push(t);
        }
        lp(i,0,m){
            cin >> t;
            ys.push(t);
        }
        ll ans = 0 ;
        while( (!xs.empty()) && (!ys.empty()) ){
            int tx , ty;
            tx = xs.top()  ;
            ty = ys.top()  ;
            if( tx > ty ){
                ++x;
                ans += tx * y;
                xs.pop();
            }
            else {
                ++y;
                ans += ty * x ;
                ys.pop();
            }
        }
        while(!xs.empty() ){
            int tx = xs.top() * y;
            xs.pop();
            ans += tx;
        }
        while(!ys.empty()){
            int ty = ys.top() * x ;
            ys.pop();
            ans += ty;
        }
        cout << ans << endl;

    }







    return 0;
}
