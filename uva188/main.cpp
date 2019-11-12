#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long ) 1e18;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;

using namespace std;
ll n , k;

ll ton(string s)
{
    ll ans = 0, t = 1;
    reverse(s.begin(),s.end());
    lp(i,0,s.size())
    {
        ans += (s[i]-'a'+1) * t;
        t*=32;
    }
    return ans;
}

void split( string &s ,vector<ll> &v )
{
    v.clear();
    string t ="";
    for(char ch:s)
    {
        if(ch!=' ') t+= ch;
        else
        {
            ll x = ton(t);
            if(x!=0)v.push_back(x);
            t ="";
        }
    }
    //cout << ton(t) << " " << ton("full");
    if(t!="" && ton(t)) v.push_back(ton(t));

}

ll nxtc( ll c, ll wi, ll wj )
{
    return min( (c/wi+1)*wi , (c/wj+1)*wj );
}

ll mod( ll a, ll b){
    a %= b;
    a += b;
    a %= b;
    return a;
}

string text;

int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    vll numbers;
    ll n , c;
    while(getline(cin,text))
    {
        split(text,numbers);
        n=numbers.size();
        c =1000000000;

        rep(i,numbers) c = min(c,numbers[i]);
        while(1)
        {

            map<ll,bool>md;
            bool done = 1;
            map<ll,ll>pr;
            rep(i,numbers)
            {
                ll x = mod(c/numbers[i],n);

                if( md[x] )
                {
                    done = 0;
                    c = nxtc(c,numbers[i],pr[x]);
                    break;
                }
                else
                {
                    md[x] =1;
                    pr[x] = numbers[i];
                }

            }
            if(done) break;

        }
        cout << text << "\n";
        cout << c << "\n\n";

    }



    return 0;
}
