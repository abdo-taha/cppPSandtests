#include <bits/stdc++.h>

using namespace std;

const int n = 5  , d = 16 ;
int arr[n][n] ;
bool done = 0 ;
void print ()
{
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
            cout << arr[i][j] << ' ' ;
        cout << endl ;
    }
    cout << "...................\n" ;
}
bool validPosition( int x , int y)
{
    return  x >= 0 && x < n && y >= 0 && y < n ;
}
int nextx( int x , int y )
{
    if( validPosition(x,y+1) ) return x ;
    return x+1 ;
}
int nexty( int x , int y )
{
    if( validPosition(x,y+1) ) return y+1 ;
    return 0 ;
}
bool valid(int x , int y , int p ) // x , y are  valid position
{
    if(p == 0 ) return 1 ;
    if(p == 2 )
        {
            if(validPosition(x-1,y+1) && arr[x-1][y+1] == 2 )
                return 0 ;
            if(validPosition(x,y-1) && arr[x][y-1]==1)
                return 0 ;
            if(validPosition(x-1,y) && arr[x-1][y]==1)
                return 0 ;
            return 1 ;
        }
    else
    {
        if(validPosition(x-1,y-1) && arr[x-1][y-1] == 1 )
            return 0 ;
        if(validPosition(x-1,y) && arr[x-1][y] == 2 )
             return 0 ;
        if(validPosition(x,y-1) && arr[x][y-1] == 2 )
            return 0 ;
        return 1 ;
    }
}
void solve(int x , int y , int c )
{
    if(done  ) return ;
    for(int i = 2 ; i >= 0; --i)
    {


        if( valid( x , y , i )  )
        {

            arr[x][y] = i ;
            if(i != 0) ++c ;
            //print();
            if(validPosition(nextx(x,y) , nexty(x,y)))
                solve( nextx(x,y) , nexty(x,y) , c  ) ;
            else
            {
                if(c == d)
                {
                    done = 1 ;
                    return ;
                }
            }
            if(done) return ;
            if(i!=0)
            {--c ;
            arr[x][y] = 0 ;
            }

        }

    }


}

int main()
{

    solve(0,0,0) ;
    print() ;


    return 0;
}
