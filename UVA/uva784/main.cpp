#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
char grid[50][100];
bool visited[50][100];
vector<int>c,dsh;


int r = 0  , x , y;


int xx[] = { 1 , 0 , -1 , 0 } ,
    yy[] = { 0 , 1 , 0 , -1 } ;



bool valid( int a , int b ) {
    return a >= 0 && b >= 0 && a < r && b < c[a] ;
}



void dfs( int p1 , int p2 ){
        visited[p1][p2] = 1 ;
        grid[p1][p2] = '#' ;
        lp(i,0,4) {
            if(valid(p1+ xx[i] , p2 +yy[i]  ) && (!visited[p1+ xx[i] ][p2 +yy[i] ]) && grid[p1+ xx[i] ][p2 +yy[i] ] == ' ' )
                dfs( p1+ xx[i] , p2 +yy[i] ) ;
        }

}


int main()
{
    //ios::sync_with_stdio(0);

//    freopen( "output.txt" , "w" , stdout ) ;

    int nlp ;
    cin >> nlp ;
    lp(ilp,0,nlp){

        lp(i,0,50)
        lp(j,0,100){
            grid[i][j] = ' ' ;
            visited[i][j] = 0 ;
        }


        string t ;
        r = 0;
        c.clear();

        while(1){

            getline(cin , t ) ;
            if(t[0]=='_') {
                dsh.push_back( t.size() ) ;
                    break ;
            }

            c.push_back(t.size() );
            lp(i,0,t.size()){
                grid[r][i]=t[i];
                if(t[i] == '*'){
                    x = r ;
                    y = i ;
                }
            }


            ++r;
        }

        dfs( x , y ) ;
        int bg = 0 ;
        if(ilp == 0 ) ++bg ;
        lp(i,bg,r){
            lp(j,0,c[i]){
                cout <<grid[i][j];
            }
            cout << endl;
        }
        //cout << r << ' ' << c << endl;
        lp(i,0,dsh[ilp] ) cout << '_';
        cout << "\n" ;
    }






    return 0;
}
