#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > wishes;
map<int,bool> visited ;
vector<int> order ;
vector<int> parents ;
void topo( int current ) {
    visited[current] = 1;

    vector<int> :: iterator it = wishes[current].begin();
    for(;it!=wishes[current].end();++it) {
        int child = *it ;
        if( !visited[*it] ) {
            topo(*it);
        }
    }
    order.push_back(current);

}


int main()
{
    ios::sync_with_stdio(0);
    int a,n , m , t;
    //cin >> n >>a;
    scanf("%d%d",&n,&a);
    wishes.resize(n+5);
    for(int i = 1 ; i <= a ; ++i)
    {
       // cin >> m;
        scanf("%d",&m);
        for(int j = 0 ; j < m ; ++j) {
            //cin >> t;
            scanf("%d",&t);
            wishes[i].push_back(t);


        }

    }

    for(int i = 1 ; i <= n ;++i) {
        if(!visited[i])
            topo(i);
    }

    parents.resize(n+5);
    int father = 0;
    //cout << n << ' ' << order.size();
    for(int i = n-1; i>=0 ; --i) {
        int current = order[i];
        parents[current]=father;
        father = current;
    }
    for(int i = 1 ; i <= n ; ++i) {
        //cout << parents[i] << endl;
        printf("%d\n",parents[i]);
    }


    return 0;
}
