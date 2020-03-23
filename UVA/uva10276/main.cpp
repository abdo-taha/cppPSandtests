#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
map<ll,bool> sq ;

vector<ll> rods(50);



int main()
{
    ios::sync_with_stdio(0);

    //freopen( "output.txt" , "w" , stdout ) ;
    lp(i,1,1500){
        sq[i*i] = 1 ;
    }
    int nlp ;
    cin >> nlp ;
    lp(ilp,0,nlp){

        ll n , t = 1 ;
        cin >> n ;
        lp(i,0,50) rods[i] = 0 ;
        bool a = 1;
        while(a){
            lp(i,0,n){
                if( rods[i] == 0 || sq[ t + rods[i] ] ) {
                    rods[i] = t;
                    ++t;
                    break;
                }
                else if(i == n-1) a =0;

            }
        }

        cout << t - 1<<endl;

    }




    return 0;
}
