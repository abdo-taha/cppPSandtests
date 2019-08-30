#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
vector<vi > board;
map <int,bool> visited;
int mny ;


void dfs(int x ){
    visited[x] = 1 ;
    lp(i,0,board[x].size()){
        int t = board[x][i];
        if(!visited[t]) dfs(t);
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
    //cout << "aaaaaaa";
    lp(i,1,n+1){
        if(!visited[i]){
            ++mny;
            dfs(i);
        }

    }
    cout << mny ;






    return 0;
}
