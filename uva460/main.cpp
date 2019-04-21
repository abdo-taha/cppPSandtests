#include <bits/stdc++.h>

using namespace std;
int x1l , x1r ,y1d , y1u , x2l , x2r ,y2d , y2u, xl ,xr,yd,yu;


bool yes()
{
    if(x1l> x2l)
    {
        swap(x1l,x2l);
        swap(x1r,x2r);
    }
    if(y1d>y2d)
    {
        swap(y1d,y2d);
        swap(y1u,y2u) ;
    }
    if(x1r>x2l&&y1u>y2d)
        return 1 ;
    else return 0;
}

int main()
{
   int n ;
   cin >> n ;


   for(int i = 0;i<n;i++)
   {
       cin >> x1l >> y1d >> x1r >> y1u >> x2l >> y2d >> x2r >> y2u ;
       int xs[4] ={x1l,x1r,x2l,x2r} ;
       int ys[4] ={y1d,y1u,y2d,y2u} ;
       sort(xs,xs+4);
       sort(ys,ys+4) ;
       xl = xs[1] ; xr=xs[2] ;
       yd =ys[1] ; yu = ys[2] ;
        if(i>0)
            cout << "\n";
       if( yes())
        cout << xl <<" " << yd <<" " << xr<<" " <<yu <<"\n" ;
       else
        cout << "No Overlap\n" ;
   }
    return 0;
}

