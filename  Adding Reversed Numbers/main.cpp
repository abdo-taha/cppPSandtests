#include <bits/stdc++.h>
using namespace std;
int a[205], b[205] , c[205] , n , n1 , n2;


int main()
{
    string s1 , s2 ;
    cin >> n ;
    while(n--) {
        cin >> s1 >> s2 ;
        n1 = s1.length();
        n2 = s2.length();
        int j = 0 ;
        bool start = 0 ;
        for(int i = n1 -1 ; i >= 0 ; --i) {
            if(s1[i] != '0') {
                start = 1 ;
                a[j++] = s1[i] -'0';
            }
            else if( !start) --n1 ;
            else {
                a[j++] = 0;
            }
        }
        j = 0;
        start = 0;
        for(int i = n2 -1 ; i >= 0 ; --i) {
            if(s2[i] != '0') {
                start = 1 ;
                b[j++] = s2[i] -'0';
            }
            else if( !start) --n2 ;
            else {
                b[j++] = 0;
            }
        }
        reverse(a,a+n1);
        reverse(b,b+n2);
//        for(int i = 0 ; i < n1 ; ++i)
//            cout << a[i] ;
//        cout << endl;
//        for(int i = 0 ; i < n2 ; ++i)
//            cout << b[i];
        int mx = max(n1,n2)  ;
        for(int i = 0 ; i < mx ; ++i )
            c[i] = a[i] + b[i];
        for(int i = 0 ; i < mx ; ++i) {
                if(i == mx -1 && c[i] > 9) ++mx;
            c[i+1] += c[i] / 10 ;
            c[i] %= 10 ;

        }
        //if(c[0]!=0) cout << c[0];
        start = 0;
        for(int i = 0 ; i < mx ; ++i)
            {
                if(start) cout << c[i] ;
                else if(c[i]!= 0) {
                    start = 1;
                    cout << c[i];
                }
            }
        cout << endl;
        for(int i = 0 ; i < 205 ; ++i)
            c[i] = b[i] = a[i] = 0 ;

    }

    return 0;
}
