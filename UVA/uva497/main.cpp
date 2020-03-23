
#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define eps (1e-5)
#define pb(i) push_back(i)
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;

string s ;
vi numbers ;
vi nOfSmaller , before;
int mxvalue , mxpos ;



void solve( ){

   nOfSmaller.resize(numbers.size());
   before = vi(numbers.size(),-1);
   rep(i,numbers){
       nOfSmaller[i] = 1;
        for(int j = i-1 ; j >= 0 ; --j) {
            if( numbers[j] < numbers[i] ){
                if(nOfSmaller[j]+1 > nOfSmaller[i]) {
                    nOfSmaller[i] = nOfSmaller[j] +1 ;
                    before[i]= j ;
                }


            }
        }
        if(nOfSmaller[i] > mxvalue){
            mxvalue = nOfSmaller[i];
            mxpos = i ;
        }

   }


}

void printsol( ){

    stack<int> st ;
    while(1){
        if( mxpos == -1 ) break;
        st.push(numbers[mxpos]);
        mxpos = before[mxpos];
    }
    while(!st.empty()){
        cout << st.top() << "\n";
        st.pop();
    }


}




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;

    int nlp; cin >> nlp;
    cin.ignore();

    lp(ilp,0,nlp){

        numbers.clear();
        nOfSmaller.clear();
        before.clear();
        mxvalue = 0; mxpos = 0;


        if(ilp == 0)getline(cin,s);
        if(ilp!=0) cout << "\n";

        while(1){
            getline(cin , s );
            if(s == "") break ;
            numbers.push_back(stoi(s));
        }

        solve() ;


        cout << "Max hits: "<<  mxvalue << "\n";

        printsol(  ) ;







    }
















    return 0;
}

