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

int n , a , b ;
int up[30] , down[30];

string s1 , s2 ;

void clean(int x) {
    while( up[x] != x || down[x] != x ){

        int t = up[x] ;
        up[x] = x ;
        down[x] = x ;
        x = t;
    }

}

void cleanb(int x){

    int t = down[x] ;
    clean(x);
    down[x] = t ;

}
int top(int x) {

    while( up[x] != x ) x = up[x] ;
    return x ;

}
void print(int x){
    cout << " ";
    while(up[x]!= x) {
        cout << x << " ";
        x = up[x];
    }
    cout << x;

}


int main()
{
    ios::sync_with_stdio(0);
//    cin.tie(0);
    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    cin >> n ;
    lp(i,0,n) up[i] = down[i] = i ;
    int k = 0 ;
    while(cin >> s1 ){

        if(s1 =="quit") break ;
        cin >> a >> s2 >> b;


        bool x = s1 == "move";
        bool y = s2 =="onto" ;
        if( top(a) == top(b) ) continue;

        if( x ) clean(a);
        else if( down[a] != a ){
            int t = down[a];
            up[t] = t ;

        }
        if( y ){

            cleanb(b);

        }
        else{

            b = top(b);

        }

        down[a] = b ;
        up[b] = a ;
//                        string nl ="";
//                    lp(i,0,n){
//                        cout << nl << i <<":" ;
//                        nl = "\n";
//                        if( down[i] == i ){
//                            print(i);
//                        }
//
//                    }cout <<endl;


    }


    lp(i,0,n){
        cout <<  i <<":" ;

        if( down[i] == i ){
            print(i);
        }
        cout << "\n";

    }










    return 0;
}

