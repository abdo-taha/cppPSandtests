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


vector<edge> MST_Kruskal( vector<edge> edgelist ,int nc , vector<pair<int,int> > done , int cr  ) {
    Unionfind uf(nc);
    vector<edge> edges ;
    //int mstcost = 0;
    priority_queue <edge> q ;
    for(int i = 0 ; i < edgelist.size() ; ++i ){
        q.push(edgelist[i]);
    }
    lp(i,0,cr){
        if(uf.union_sets(done[i].first , done[i].second )){

        }

    }
    while(!q.empty()){

        edge e = q.top() ;
        q.pop();
        if( uf.union_sets(e.from , e.to) ){
           // mstcost += e.w;
            edges.push_back(e);
            //cout << "aaa" << endl;
        }
    }
   // if( edgelist.size() != n-1 ) return make_pair( -OO , vector<edge>() ) ;

    return edges ;


}



int main()
{
    //freopen("output.txt" , "w" , stdout);
    int llp ;
    cin >> llp ;
    lp(ilp , 0, llp){
        vector<pair<int,int>> cities ;
        int nc , x , y ,w ;
        cin >> nc;

        lp(i,0,nc){
            cin >> x >> y ;
            cities.push_back({x,y}) ;
        }
        vector<edge> edgelist ;
        lp(i,0,nc){
            lp(j,i+1,nc){
                edge e (i,j , (cities[i].first - cities[j].first )* (cities[i].first - cities[j].first )
                        + (cities[i].second - cities[j].second) * (cities[i].second - cities[j].second) );
                edgelist.push_back(e);
            }
        }
        vector<pair<int,int> > done;
        int nr ;
        cin >> nr ;
        lp(i,0,nr){
            cin >> x >> y;
            done.push_back({x-1,y-1}) ;

        }

        vector<edge> sol = MST_Kruskal(edgelist,nc,done,nr) ;
        //cout << sol.size() ;
        lp(i,0,sol.size()){
            cout << sol[i].from +1  << ' ' << sol[i].to +1<< endl;
        }
        if(sol.size() == 0){
            cout << "No new highways need\n" ;
        }
        if(ilp != llp -1 )cout << endl;

    }


    return 0;
}
