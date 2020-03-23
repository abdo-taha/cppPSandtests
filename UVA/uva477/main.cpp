#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
//const long long OO = (long long) 1e18+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
#define EPS 1e-9

#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define ff first
#define ss second
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;
typedef complex<double> point;
typedef pair<ll,ll> pll;



using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m


 struct rect{
    double x1,x2,y1,y2;
    int pos;
 };
 struct cir{
    double x , y , r;
    int pos;
 };

 vector<rect> rects;
 vector<cir> cirs;


 bool in_rec(double x , double y , rect r){
    return x <= max(r.x1,r.x2) && x>= min(r.x1,r.x2)&&y>= min(r.y1,r.y2)&&y<=max(r.y1,r.y2);
 }

 bool in_cir(double x , double y , cir c){
    return sqrt( pow(x-c.x,2) + pow(y-c.y,2) )  - c.r <= EPS ;

 }





int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
     //freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    char ch;
    int i = 1;
    while(cin>>ch){
        if(ch=='*') break;
        if(ch=='r'){
            rect r;
            cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
            r.pos = i++;
            rects.push_back(r);
        }
        else {
            cir c ;
            cin >> c.x>>c.y>>c.r;
            c.pos = i++;
            cirs.push_back(c);
        }

    }

    double x,y;
    int cnt = 1;
    while(cin>>x>>y){
        if(x==9999.9&&y==9999.9) break;
        vi pr;
        for(rect r : rects){
            if(in_rec(x,y,r)) pr.push_back(r.pos);

        }
        for(cir c : cirs) if(in_cir(x,y,c) )pr.push_back(c.pos);
        sort(pr.begin(),pr.end());
        if(!pr.size()) cout << "Point "<<cnt<<" is not contained in any figure\n";
        else {
            for(int n:pr) cout << "Point "<<cnt<<" is contained in figure "<<n<<"\n";
        }


    ++cnt;
    }







    return 0;
}
