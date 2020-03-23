#include <iostream>
using namespace std;

int main()
{
    int game ; cin >> game ;
    char game_map[101][101];
    bool visited[101][101] ;
    int n , c  , temp;
    bool alive ;
    for ( int k = 0 ; k < game ; k++ )
    {
        c = 0 ;
        for( int i = 0 ; i < 101 ; i++ )
            for ( int j = 0 ; j < 101 ; j++ )
                visited[j][i] = 0 ;
        cin >> n ;
        for( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < n ; j++ )
                cin >> game_map[j][i] ;
        for( int i = 0 ; i < n ; i++ )
            for ( int j = 0 ; j < n ; j++ )
            {
                alive = 0 ;
                if ( visited[j][i] == 0 )
                {
                    visited[j][i] = 1 ;
                    if ( game_map[j][i] != '.'  )
                    {
                        temp = j ;
                         if ( game_map[j][i] == 'x' ) alive = 1 ;
                         while ( (game_map[j+1][i] != '.') && (j + 1) < n )
                         {
                             j++ ;
                             visited[j][i] = 1 ;
                             if ( game_map[j][i] == 'x' ) alive = 1 ;

                         }
                         j = temp ;
                         temp = i ;
                         while ( (game_map[j][i+1] != '.') && (i + 1) < n )
                         {
                             i++ ;
                             visited[j][i] = 1 ;
                             if ( game_map[j][i] == 'x' ) alive = 1 ;

                         }
                         i = temp ;

                    }
                }
                if ( alive == 1 )  c++ ;


            }
        cout << "Case " << k + 1 << ": " << c << endl ;
    }
    return 0;
}
