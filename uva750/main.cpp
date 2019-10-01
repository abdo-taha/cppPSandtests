#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;


int n ;
int x , y ;

map<int,bool> vstcols , vstrows,vstdplus , vstdmns ;

bool valid ( int x , int y ){
    return vstcols[y] == 0 && vstrows[x] == 0
    && vstdplus[x+y] == 0 && vstdmns[x-y] == 0  ;

}

bool grid[10][10] ;
int sol[9];


void solve(int c ){
    if(c == y) solve(c+1) ;
    if(c == 9 ) {
        cout << setw(2) <<  n << "      " ;
        string space = "";
        lp(i,1,9) cout <<space <<  sol[i],space = " " ;
        cout << '\n';
        ++n;

    }



    lp(i,1,9){
        if(valid( i,c )){
            vstcols[c] = 1 ; vstrows[i] = 1 ;
            vstdplus[c+i] = 1 ;  vstdmns[i-c] = 1 ;

            sol[c]=i;
            solve( c +1 ) ;


            vstcols[c] = 0 ; vstrows[i] = 0 ;
            vstdplus[c+i] = 0 ;  vstdmns[i-c] = 0 ;


        }


    }


}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    int nlp ; cin >> nlp ;
    string nl = "" ;
    while(nlp--){
            cout << nl , nl = "\n";
            memset(grid,0,sizeof(grid)) ;
            vstcols.clear(); vstrows.clear();vstdmns.clear();vstdplus.clear();
            cin >> x >> y ;
            grid[x][y] = 1 ;
            vstcols[ y ] = 1; vstrows[x] = 1 ; vstdplus[x+y] = 1 ; vstdmns[x-y] = 1 ;
            sol[y] = x ;
            cout << "SOLN       COLUMN\n" << " #      1 2 3 4 5 6 7 8\n\n" ;
            n = 1 ;
            solve(1);




    }










    return 0;
}
