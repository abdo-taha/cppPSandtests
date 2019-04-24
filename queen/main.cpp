#include <bits/stdc++.h>

using namespace std;
int n   , c = 0;
bool done = 0 ;
vector<int> board ;
bool valid( int p , int v )
{
    if(p == 0) return 1 ;
    for(int i = 0 ; i < p ; ++i)
    {
        if( (p-i) == abs(v - board[i]) || v == board[i]  )
            return 0 ;
    }
    return 1 ;
}

void print()
{
    vector<int>::iterator it = board.begin() ;
    for(; it != board.end(); ++it)
    {
        cout << *it << ' ' ;
    }
    cout << endl ;
}

void solve(int p )
{
    if(p == n)
    {
        print();
        //done = 1 ;
        ++c ;// for counting possible solutions
        return ;
    }

    for( int i = 1 ; i <= n ; ++i)
    {
        //if(done) return ;
        if(valid(p,i))
        {
            board.push_back(i) ;
            solve( p+1 ) ;
            board.pop_back();

        }
    }
}

int main()
{

    cin >> n ;
    solve(0) ;
    cout << c << endl ;
    return 0;
}
