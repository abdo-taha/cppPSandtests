#include <bits/stdc++.h>
#define ll  long long
#define lp(i,a,n) for(int i = a;i<n;++i)
using namespace std;
vector<int> numbers;
//map<int,int> cnt;
int gcd(int a , int b) {
    int mx = max(a,b) , mn = min(a,b);
    if(mn == 0) return a;
    else{
        return gcd(b , a%b);
    }

}

int main()
{
    //ios::sync_with_stdio(0);
   int a,b,n,t,c=0,est =0;
    //freopen("output.txt","w",stdout);
    while(1){
        cin >> n;
        if(n==0) return 0;
        while(n--) {
            cin >> t;
            numbers.push_back(t);
        }

        lp(i,0,(int)numbers.size())
             lp(j,i+1,(int)numbers.size()){
                ++c;
                if( gcd(numbers[i],numbers[j]) == 1) ++est;

             }

        if(!est) cout << "No estimate for this data set.\n" ;
        else {
            double x = 6.0 * (double) c / est ;
            x = sqrt(x);
            printf("%0.6f\n" , x);
        }
        numbers.clear();
        c = est = 0;

    }


    return 0;
}
