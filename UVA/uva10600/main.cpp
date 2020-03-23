//#include <bits/stdc++.h>
//using namespace std;
//const int OO = (int) 1e9;
//#define lp(i,a,n) for(int i = a ; i < n ; ++i)
//typedef vector<int> vi ;
//typedef long long ll;
//vector<int> donttake ;
//
//struct edge {
//    int from , to , w ;
//    edge(int from , int to , int w) : from(from) , to(to) , w(w) {}
//
//    bool operator < (const edge &e) const {
//        return w > e.w ; // for priority queue
//    }
//
//};
//
//struct Unionfind{
//    vi parents ;
//    Unionfind(int n){
//        parents = vi(n);
//        lp(i,0,n) parents[i] = i ;
//    }
//
//    int find_set(int x){
//        if(parents[x] == x) return x;
//        return   parents[x]  = find_set(parents[x]) ;
//    }
//
//    void link(int x , int y) {
//
//        parents[x] = y ;
//
//    }
//    bool union_sets(int x , int y){
//        x = find_set(x) ;
//        y = find_set(y);
//        if( x != y){
//            link( x,y) ;
//        }
//        return x!=y;
//
//    }
//
//
//};
//
//
//pair<int , vector<edge> > MST_Kruskal(int n , vector<edge> edgelist , int dont){
//    Unionfind uf(n) ;
//    vector<edge> edges ;
//    int cost = 0;
//    priority_queue<edge> q;
//    lp(i,0,edgelist.size()) q.push(edgelist[i]) ;
//    int i = -1 ;
//    while(!q.empty()){
//        ++i;
//        edge e = q.top();
//        q.pop();
//        if(i == dont) continue ;
//        if(uf.union_sets(e.from,e.to)){
//            cost += e.w;
//            edges .push_back(e);
//            if(dont == -1) donttake.push_back(i);
//        }
//    }
//    if(edges.size() != n - 1 ) return make_pair( (int) 1e9 , vector<edge>() ) ;
//
//    return make_pair( cost ,edges  ) ;
//
//}
//
//
//
//
//int main()
//{
//    int nn ;
//    cin >> nn ;
//    lp(jj,0,nn){
//
//        donttake.clear();
//        int n , m  , a ,b , w;
//        cin >> n >> m ;
//        vector<edge> edgelist ;
//        lp(i,0,m){
//            cin >> a >> b >> w ;
//            edge e(a-1,b-1,w);
//            edgelist.push_back(e);
//
//        }
//        pair<int,vector<edge> > sol = MST_Kruskal(n,edgelist , -1);
//        cout << sol.first << ' ';
//        int mn2 = (int) 1e9;
//        lp(i,0,n-1) {
//            mn2 = min(mn2 , MST_Kruskal(n,edgelist , donttake[i]).first ) ;
//
//        }
//        cout << mn2 << endl;
//    }
//
//
//    return 0;
//}






/*


i solved it again in sheet !!!
and wrote same code again woow !!








*/

#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;




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
    bool operator == (const edge &e ) const {
        return w == e.w && from == e.from && to == e.to ; //  for priority queue to be non decreasing
    }

};


pair<int , vector<edge> > MST_Kruskal( vector<edge> edgelist ,int n , edge forbiden  ) {
    Unionfind uf(n);
    vector<edge> edges ;
    int mstcost = 0;
    priority_queue <edge> q ;
    for(int i = 0 ; i < edgelist.size() ; ++i ){
        q.push(edgelist[i]);
    }
    while(!q.empty()){

        edge e = q.top() ; q.pop();
        if( e == forbiden ) continue;
        if( uf.union_sets(e.from , e.to) ){

            mstcost += e.w;
            edges.push_back(e);
        }

    }

    if(edges.size()!= n-2) return make_pair( 100000000, vector<edge>() ) ;
    return make_pair( mstcost , edges ) ;


}












int main()
{
    ios::sync_with_stdio(0);
//    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    int t , n , m , a, b , c ; cin >> t ;
    while(t--){
        cin >> n >> m ;
        vector<edge> es ;
        lp(i,0,m){
            cin >> a>>b>>c ;
            edge e(a,b,c);
            es.push_back( e );
        }
        edge f(-1,-1,-1) ;
        pair<int, vector<edge> > kk = MST_Kruskal(es,n+1,f) ;

        cout << kk.first << ' ';
        int mn = 100000000;

        lp(i,0,kk.second.size()){

            mn = min( mn , MST_Kruskal(es,n+1,kk.second[i]).first )  ;
        }
        cout << mn << endl;


    }




    return 0;
}






