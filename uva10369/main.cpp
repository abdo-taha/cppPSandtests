#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;

struct edge{
    int from , to , w ;
    edge(int from , int to , int w) : from(from) , to(to) , w(w) {}
    bool operator < (const edge &e) const{
        return w > e.w ;
    }
};


struct Unionfind{
    vi parent ;

    Unionfind(int n ){
        parent = vi(n);
        lp(i,0,n)  {
            parent[i] = i ;

        }
    }

    int find_set( int x ){

        if(parent[x] == x) return x;
        return parent[x] =  find_set( parent[x] );
    }

    int link(int x , int y){

        parent[x] = y;
    }

    bool union_sets(int x , int y){
        x = find_set(x) ;
        y = find_set(y) ;
        if(x != y) {
            link( x ,y) ;
        }
        return x!= y;

    }

};

int Mst_krusal( vector<edge> edgelist , int nc , int channels ){
    Unionfind uf(nc) ;
    vector<int> ws ;
    priority_queue<edge> q;
    lp(i,0,edgelist.size()){
        q.push(edgelist[i]);
    }

    while(!q.empty()){

         edge e = q.top() ;
        q.pop() ;
        if( uf.union_sets(e.from , e.to) ) ws.push_back(e.w) ;

    }
    //if(nc-channels-1 < 0) return 0 ;
    return ws[nc-channels-1];


}


int main()
{
    ios::sync_with_stdio(0);

    int nlp;
    cin >> nlp;
        //freopen("output.txt" , "w",stdout);
    lp(ilp,0,nlp){
        vector<edge> edgelist;
        vector<pair<int,int> > cities ;
        int channel , n , x , y ;
        cin >> channel >> n ;
        lp(i,0,n){
            cin >> x >> y ;
            cities.push_back({x,y}) ;

        }
        if(channel >= n) {
            cout << "0.00" << endl;
            continue ;
        }

        lp(i,0,n){
            lp(j,i+1,n){
                edge e(i,j, (cities[i].first - cities[j].first) * (cities[i].first - cities[j].first) +
                       (cities[i].second - cities[j].second) * (cities[i].second - cities[j].second) ) ;
                edgelist.push_back(e);


            }
        }
         double ans =  Mst_krusal(edgelist,n,channel) ;
         cout << fixed << setprecision(2) << sqrt(ans) << endl;
    }




    return 0;
}
