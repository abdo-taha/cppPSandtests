#include <bits/stdc++.h>
using namespace std;
const int OO = (int) 1e9;
#define lp(i,a,n) for(int i = a ; i < n ; ++i)
typedef vector<int> vi ;
typedef long long ll;
map<string,int> tree;
vector<int> ans ;
int dfs(string s){
    //cout << s << ' ' << (tree[s]!=0)<< endl;
    if(tree[s]==0) return 0 ;
    //ans.push_back(tree[s]) ;
    string s1 = s , s2 = s ;
    s1 += 'L' ;
    s2 += 'R' ;
    int a = 0 , b = 0 ;
    if(tree[s1] != 0 )   a += dfs(s1) ;
    if(tree[s2] != 0 )   b += dfs(s2) ;
    return a + b + 1 ;

}
void bfs(int ns){
    queue<string> q;
    string s = "";
    q.push(s);
    while(ans.size() < ns){
        s = q.front();
        q.pop();
        if( tree[s] != 0 ) ans.push_back(tree[s]);
        q.push(s+'L');
        q.push(s+'R');
    }

}


int main()
{

    ios::sync_with_stdio(0);
    //freopen("output.txt" , "w" , stdout) ;

    string s ;
    while(cin >> s ) {
    int ns  = 0;

            tree.clear() ;
            ans.clear() ;

        bool vld = 1 ;
        if(s =="()") {
            cout << "not complete" << endl;
            continue ;
        }
            string num = "";
            int pos = 1,n;
            while(pos < s.size() && s[pos++] != ',') num += s[pos-1] ;
            istringstream iss(num);
            iss >> n ;
            string s1 = "";
            while(pos < s.size() && s[pos++] != ')' ) s1 += s[pos-1];
            if(tree[s1] != 0 ) vld = 0;
            tree[s1] = n ;
            //cout << s1 << ' ' << n << endl;
            ++ns;

        while(cin >> s){
            if(s =="()") break ;
            string num = "";
            int pos = 1,n;
            while(pos < s.size() && s[pos++] != ',') num += s[pos-1] ;
            istringstream iss(num);
            iss >> n ;
            string s1 = "";
            while(pos < s.size() && s[pos++] != ')' ) s1 += s[pos-1];
            if(tree[s1] != 0 ) vld = 0;
            tree[s1] = n ;

            ++ns;

        }
        if(dfs("") != ns || vld == 0) cout << "not complete" << endl;
        else {

                bfs(ns);

            lp(i,0,ans.size()){
                cout << ans[i] ;
                if(i != ans.size() -1) cout << " " ;
            }
            cout << endl;
        }
    }




    return 0;
}
