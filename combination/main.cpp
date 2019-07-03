//this file is not complete
//you have to divide by all numbers in down
//just forgot to copy code before submit in uva



#include <bits/stdc++.h>
#define ll  long long
#define lp(i,a,n) for(int i = a;i<n;++i)
using namespace std;
int  n, m;
vector<int> up , down;


void rmv() {
    lp(i,0,up.size())
        lp(j,0,down.size()) {
            if(down[j]!=1 && up[i]%down[j]==0) {

                up[i] /= down[j];
                down[j] = 1;

            }

        }
}

void c(int x , int y) {
    if(y > x-y) {
        c(x,x-y);
        return;
    }
    while(y) {
        up.push_back(x--);
        down.push_back(y--);
    }

    rmv();


}




int main()
{
    ios::sync_with_stdio(0);
    while(cin >> n >> m){
        if(!(n||m)) break;

        c(n,m);
        ll solution =1;
        lp(i,0,up.size()){

            solution *=up[i];
        }
        cout <<n  << " things taken "<<m << " at a time is "
        << solution << " exactly.\n" << endl;
        up.clear();
        down.clear();

    }


    return 0;
}
