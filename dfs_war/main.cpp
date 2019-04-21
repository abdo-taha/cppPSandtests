#include <iostream>
using namespace std;


int x[8] = {1,1,0,-1,-1,-1,0,1}
 ,  y[8] = {0,1,1,1,0,-1,-1,-1};

int n ;
void dfs( int i , int j ,int arr[][26] , bool visited[][26] )
{

    if (visited[i][j] == 1 ) return ;
    else{
        if( arr[i][j] == 0 )
        {
            visited[i][j] = 1 ;
            return ;
        }
        else
        {
            visited[i][j] = 1 ;
            for( int k = 0 ; k < 8 ; k++)
            {
                if( i + x[k] < n && i + x[k] >= 0 &&
                    j + y[k] < n && j + y[k] >= 0 )
                        dfs(i + x[k] ,j + y[k] ,arr ,visited ) ;
            }
        }
    }
}
int main()
{
    int arr[26][26]={} ;
    bool visited[26][26]={};
    int c = 0 ;
    int number = 0 ;
    while(cin >> n)
    {
        c = 0 ;
        for( int i = 0; i < 26; i++ )
            for ( int j =0 ; j < 26; j++ )
                visited[i][j] = 0 ;

    char in;
    for( int i = 0; i < n; i++ )
        for ( int j =0 ; j < n; j++ )
        {
            cin >> in ;
            arr[i][j] = in - '0' ;
        }


    for( int i = 0; i < n; i++ )
        for ( int j =0 ; j < n; j++ )
        {

            if (visited[i][j] == 1 ) continue ;
            else
            {
                dfs( i , j ,arr ,visited );
                if ( arr[i][j] == 1 ) c++ ;
            }
        }

        cout << "Image number " << ++number << " contains " << c << " war eagles." << endl ;
    }

    return 0;
}
