#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
vector<int> donttake ;

struct edge {
    int from , to , w ;
    edge(int from , int to , int w) : from(from) , to(to) , w(w) {}

    bool operator < (const edge &e) const {
        return w > e.w ; // for priority queue
    }

};

struct Unionfind{
    vi parents ;
    Unionfind(int n){
        parents = vi(n);
        lp(i,0,n) parents[i] = i ;
    }

    int find_set(int x){
        if(parents[x] == x) return x;
        return   parents[x]  = find_set(parents[x]) ;
    }

    void link(int x , int y) {

        parents[x] = y ;

    }
    bool union_sets(int x , int y){
        x = find_set(x) ;
        y = find_set(y);
        if( x != y){
            link( x,y) ;
        }
        return x!=y;

    }


};


pair<int , vector<edge> > MST_Kruskal(int n , vector<edge> edgelist , int dont){
    Unionfind uf(n) ;
    vector<edge> edges ;
    int cost = 0;
    priority_queue<edge> q;
    lp(i,0,edgelist.size()) q.push(edgelist[i]) ;
    int i = -1 ;
    while(!q.empty()){
        ++i;
        edge e = q.top();
        q.pop();
        if(i == dont) continue ;
        if(uf.union_sets(e.from,e.to)){
            cost += e.w;
            edges .push_back(e);
            if(dont == -1) donttake.push_back(i);
        }
    }
    if(edges.size() != n - 1 ) return make_pair( (int) 1e9 , vector<edge>() ) ;

    return make_pair( cost ,edges  ) ;

}




int main()
{
    int nn ;
    cin >> nn ;
    lp(jj,0,nn){

        donttake.clear();
        int n , m  , a ,b , w;
        cin >> n >> m ;
        vector<edge> edgelist ;
        lp(i,0,m){
            cin >> a >> b >> w ;
            edge e(a-1,b-1,w);
            edgelist.push_back(e);

        }
        pair<int,vector<edge> > sol = MST_Kruskal(n,edgelist , -1);
        cout << sol.first << ' ';
        int mn2 = (int) 1e9;
        lp(i,0,n-1) {
            mn2 = min(mn2 , MST_Kruskal(n,edgelist , donttake[i]).first ) ;

        }
        cout << mn2 << endl;
    }


    return 0;
}
