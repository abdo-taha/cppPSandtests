
#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long) 1e15;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;
typedef complex<double> point;


using namespace std;
ll  Pow(ll  B,ll  P){ll  R=1; while(P>0)  {if(P&1) R=(R*B);P/=2;B=(B*B);}return R;} //compute b^p
bool isVowel(char s){s=tolower(s); if(s=='a'||s=='e'||s=='i'||s=='o'||s=='u')return true;return false;}
ll  GCD(ll  a,ll  b){ while(b){b ^= a ^=b ^= a %=b;}  return a;}
ll  LCM(ll  a,ll  b) { return (a / GCD(a,b)*b); }
ll  BigMod(ll  B,ll  P,ll  M){ ll  R=1; while(P>0)  {if(P&1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return (ll )R;} //compute b^p%m

vector<pair<ll,ll> > numbers;

ll mem[12][12];
int pp[12][12];
int mny[15][2];
int mny1[15];

ll mn( int pos1 , int pos2 ){
    if(pos2<=pos1) return 0;
    ll &ans = mem[pos1][pos2];
    if(ans != -1) return ans;
    ans = 1000000000000000000;



    lp(i,pos1,pos2){
       ll  temp = mn(pos1,i) + mn(i+1,pos2)+ numbers[i].second * numbers[pos1].first*numbers[pos2].second;
       if(temp < ans){
            ans = temp;
           pp[pos1][pos2] = i;

       }
    }



    return ans;

}

void pr(int f , int t){
    if(f==t) cout << "A" << f+1;
    else{
        cout << "(";
        pr(f,pp[f][t]);
        cout << " x ";
        pr(pp[f][t]+1,t);
        cout << ")";
    }

}



int main()
{
    ios::sync_with_stdio(0);
  //  cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;
    int n,t1,t2,T=1;

    while(1){
        cin >> n;
        numbers.clear();
        if(n == 0) break;
        lp(i,0,12)lp(j,0,12) mem[i][j] = -1;
        memset(mny,0,sizeof mny);
        memset(mny1,0,sizeof mny1);
        lp(i,0,n){
            cin >> t1 >> t2;
            numbers.push_back({t1,t2});
        }
        ll x = mn(0,n-1);
        cout << "Case "<< T++<< ": ";
        pr(0,n-1);
        cout << "\n";


    }









    return 0;
}

