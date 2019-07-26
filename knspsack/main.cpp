#include <bits/stdc++.h>

using namespace std;
vector<int> w , v,sol;
int n , wm ,t ;


int main()
{
    cin >> wm >> n ;
    for(int i = 0 ; i < n ; ++i) {
        cin >> t;
        w.push_back(t);
        cin >> t;
        v.push_back(t);
    }
    sol.resize(wm+1);
    sol[0] = 0;
    for(int i = 1 ; i <= wm ; ++i ) {
            sol[i] = 0;
        for(int j = 0 ; j < n ; ++j) {
            if(w[j] <= i ){
                t = sol[i-w[j] ] + v[j];
                sol[i]=max(sol[i] , t);
            cout << j << ' ' << sol[i] << ' ';
            }
        }

        cout << endl;
    }
    for(int i = 0 ; i <= wm ; ++i)
        cout << sol[i] << ' ';
//    cout << sol[wm];


    return 0;
}


