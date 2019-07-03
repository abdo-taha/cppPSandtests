#include <bits/stdc++.h>
#define ll  long long
#define lp(i,a,n) for(int i = a;i<n;++i)
using namespace std;
vector<int> permutation;
int n_perm = 4 , perm_cnt=0;
bool is_visited[4];
void getperm(int i = 0){
    if(i==n_perm) {
        ++perm_cnt;
        cout << permutation[0] << ' ' << permutation[1] << ' ' <<
        permutation[2] << ' ' << permutation[3] << endl;
        return;
    }
    for(int j = 0 ; j < n_perm ; ++j) {
        if(is_visited[j]) continue;
        is_visited[j] = 1;

        permutation.push_back(j+1);
        getperm(i+1);
        is_visited[j] = 0;

        permutation.pop_back();
    }

}
vector<int> p  = {1,2,3,4};

void print(){
 cout << p[0] << ' ' << p[1] << ' ' <<
        p[2] << ' ' << p[3] << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    //getperm();
    do{
        print();
    }while(next_permutation(p.begin(),p.end()));

    return 0;
}
