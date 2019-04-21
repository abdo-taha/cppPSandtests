#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0) ;
    int vp , vd , t , f , c , lp = 0 , ld = 0 , thing = 0 , wait ;
    //v princess == v dragon == time to discover  == time wait home == distance == location princess == location dragon
    cin >> vp >> vd >> t >> f >> c ;
    bool rev = 0 ;
    while(lp < c)
    {
        if(t>0)
        {
            --t ;
            lp += vp ;
            cout << ld  << " " << lp << endl ;
            continue ;


        }
        if(ld>= lp)
        {
            ++thing ;
            cout << thing << endl ;
            rev = 1 ;
            wait = f ;
        }
        if(rev)
        {
            if(ld>0) {
                    ld -= vd ;
            }
            else {

                    if(wait > 0)
                    {
                        --wait;

                    }
                    else
                    {
                        ld = vd ;
                        rev = 0 ;

                    }
            }
            lp += vp ;

        }
        else
        {
            lp += vp ;
            ld += vd ;

        }
        cout << ld  << " " << lp << endl ;

    }
     cout << thing << endl ;
    return 0;
}
