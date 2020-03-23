#include <bits/stdc++.h>

using namespace std;

int mp[100][15];

int main()
{

    int n ,m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; ++i){

        for(int j = 0; j < m ; ++j) cin >> mp[i][j];
    }

    for(int i = 0 ; i < n ; ++i){
        cout << endl;
        for(int j = 0; j < m ; ++j) cout<< mp[i][j] << " ";
        cout << endl;
    }




    return 0;
}

