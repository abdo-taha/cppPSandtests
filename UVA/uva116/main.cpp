#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f;
//const long long OO = (long long) 1e18+7;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define lpr(i,a,n) for(long long i = a ; i >= n ; --i)
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


#define X real()
#define Y imag()
#define INF 1e9

using namespace std;
ll  inv(ll a, ll b) {return 1 < a ? b - inv(b % a, a) * b / a : 1;}
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m



int mem[105][105] ,costs[105][105] , rows , cols;

int dp(int col , int row){
    if(col >= cols) return 0;
    int &ans = mem[col][row];
//    if(col==2&&row==0) cout << ans << " ";
    if(ans!=OO) return ans;
    int ans1 = dp(col+1,(row-1+rows)%rows) + costs[row][col];
    int ans2 = dp(col+1,row) + costs[row][col];
    int ans3 = dp(col+1,(row+1)%rows) + costs[row][col];

    ans=min( ans1 , min(ans2,ans3) );
    //if(col==28&&row==2) cout << costs[row][col]<<endl;
//    if(col==2&&row==0) cout << ans << endl;
//    cout << col << " " << row << " " << ans<< endl;
    return ans;
}
string spc;

void pr(int col , int row){
    if(col >= cols) return;
//    cout << col << " " << row << " "<< mem[col][row]<<endl;
    cout <<spc <<row+1;
    spc = " ";
    int ans = mem[col][row];
    vi nxt;
    int ans1 = dp(col+1,(row-1+rows)%rows) + costs[row][col];
    if(ans==ans1){
        nxt.push_back( (row-1+rows)%rows );
    }
    int ans2 = dp(col+1,row) + costs[row][col];
    if(ans==ans2){
       nxt.push_back(row);
    }
    int ans3 = dp(col+1,(row+1)%rows) + costs[row][col];
    if(ans==ans3){
        nxt.push_back((row+1)%rows);
    }
    sort(nxt.begin(),nxt.end());
    pr(col+1,nxt[0]);
}



int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);
//     freopen( "output.txt" , "w" , stdout ) ;
    //  freopen( "input.txt" , "r" , stdin ) ;

    while( cin >> rows>>cols ){
        memset(mem,OO,sizeof mem);
        lp(i,0,rows) lp(j,0,cols) cin >> costs[i][j];

        int ans = OO;
        lp(i,0,rows) {
            ans = min(ans,dp(0,i));
//            cout << mem[2][0]<<endl;
        }



//        cout << mem[24][0] << " " << mem[25][0] << " " << mem[26][0] << " " << mem[27][3]<<" "<<mem[28][2]<<endl;

        spc = "";
        lp(i,0,rows){
            if(ans==dp(0,i)){
                pr(0,i);
                cout <<"\n" <<ans<<"\n";
                break;
            }
        }



    }




    return 0;
}
