#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;



struct Unionfind {
    vi rnk , parent ;
    int forests ;
    Unionfind(int n){
        rnk =vi(n), parent = vi(n);
        forests = n;
        lp(i,0,n) parent[i] = i , rnk[i] = 1;

    }
    int find_set(int x) { // return greatest father
        if( x == parent[x] ) return x;
        else
            return parent[x] = find_set(parent[x]) ;

    }
    void link(int x , int y){ // link two trees
        if(rnk[x] > rnk[y]) swap(x,y) ;
        parent[x] = y ;
        if(rnk[x] == rnk[y]) ++rnk[y];

    }
    bool union_sets(int x , int y){
        x = find_set(x) , y = find_set(y);
        if(x != y) {
            link(x,y);
            --forests;

        }
        return x != y;

    }


    bool same_set(int x , int y){
        return find_set(x) == find_set(y);
    }
    vector< vi > connected_components(){
        vector< vi > l(parent.size());
        lp(i,0,parent.size()){
            l[find_set(i) ] .push_back(i);
        }
        return l;
    }





};


struct edge {
    int from , to , w ;
    edge(int from , int to , int w) : from(from) , to(to) , w(w) {}
    bool operator < (const edge &e ) const {
        return w > e.w ; //  for priority queue to be non decreasing
    }

};


pair<int , vector<edge> > MST_Kruskal( vector<edge> edgelist ,int n  ) {
    Unionfind uf(n);
    vector<edge> edges ;
    int mstcost = 0;
    priority_queue <edge> q ;
    for(int i = 0 ; i < edgelist.size() ; ++i ){
        q.push(edgelist[i]);
    }
    while(!q.empty()){

        edge e = q.top() ; q.pop();
        if( uf.union_sets(e.from , e.to) ){
            mstcost += e.w;
            edges.push_back(e);
        }
    }
    if( edges.size() != n-1 ) return make_pair( -OO , vector<edge>() ) ;

    return make_pair( mstcost , edges ) ;


}



int main()
{
//    int llp ;
//    cin >> llp ;
//    lp(ilp , 0, llp){
//        vector<edge> cities ;
//        int nc , x , y ,w ;
//        cin >> nc;
//
//        lp(i,0,nc){
//            cin >> x >> y ;
//            w = x * x + y * y ;
//            edge e(x,y,w);
//            cities.push_back(e) ;
//        }
//
//        int nr ;
//        cin >> nr ;
//
//    }

    return 0;
}
