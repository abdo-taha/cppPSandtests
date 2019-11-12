#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;


class BigBurger {
public :
    int maxWait(vector<int> a , vector<int> b) {
        int cutime = 0 , mx = 0;
        int sz = a.size();
        lp(i,0,sz){
            int t  = cutime - a[i] ;
            //cout << cutime << " " << t << endl;
            mx = max(mx,t);
            if(t < 0 ) cutime = a[i];

            cutime += b[i];


        }
        return mx ;


    }


};

int main(){
    BigBurger br ;
    vector<int> a = {2,10,11} , b = {3 , 4, 13};
    cout << br.maxWait(a,b);

    return 0 ;
}
