#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
vector<vi > board;
map <int,bool> visited;

bool can = 0 ;


void dfs(int start , int finish){
    if(start == finish) {
        can = 1;
    }
    visited[start] = 1;
    lp(i,0,board[start].size()){
        int t = board[start][i];
        if(!visited[t]) dfs( t,finish );
    }




}


int main()
{
    ios::sync_with_stdio(0);
    int n ,m ,a,b , start , finish;
    cin >> n >> m ;
    board = vector<vi > (n +1) ;
    lp(i,0 ,m){
        cin >> a >> b ;
        board[a].push_back(b);
        board[b].push_back(a);

    }


    cin >> start >> finish ;
    dfs(start,finish);
    cout << can ;



    return 0;
}
