#include <bits/stdc++.h>
using namespace std ;
#define ll  long long
#define lp(i,a,n) for(ll i = a;i<n;++i)

struct point{
    double x , y;
    point(double x1,double y1){
        x = x1 , y = y1 ;
    }

};

struct line{
    double m , c;
    line( point p0 ,point p1  ){
        m = ( p1.y - p0.y ) / (p1.x - p0.x) ;
        c = p0.y - m * p0.x ;

    }

};



int main()
{
    //ios::sync_with_stdio(0);
//
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    int n ;
    double x0 , y0 , x1 , y1 ;
    cout << "INTERSECTING LINES OUTPUT\n";
    cin >> n ;
    lp(i,0,n){
        double x , y ;
        bool par = 0 ;
        cin >> x0 >> y0 >> x1 >> y1;
        point p0(x0,y0) , p1(x1,y1);
        cin >> x0 >> y0 >> x1 >> y1;
        point p2(x0,y0) , p3(x1,y1);
        if( p1.x-p0.x == 0 || p3.x-p2.x == 0 ){
            if( p1.x-p0.x == 0 && p3.x-p2.x == 0 ){
                if(p1.x == p2.x) {
                    cout << "LINE\n";
                }
                else cout << "NONE\n";
            }
            else if( p1.x-p0.x == 0 ) {
                x = p1.x;
                line l1(p2,p3);
                y = x * l1.m + l1 .c;
                printf("POINT %0.2f %0.2f\n" , x , y);
            }
            else{
                x = p2.x;
                line l1(p0,p1);
                y = x * l1.m + l1 .c;
                printf("POINT %0.2f %0.2f\n" , x , y);
            }



        }
        else{

            line l1(p0,p1), l2(p2,p3);
            par =   l1.m == l2.m ;
            if(par){
                if(l1.c == l2.c) {
                    cout << "LINE\n";
                }
                else cout << "NONE\n";

            }
            else {
                x = (l1.c - l2.c) / (l2.m - l1.m) ;
                y = x * l1.m + l1.c ;
                printf("POINT %0.2f %0.2f\n" , x , y);

            }

        }



    }
    cout << "END OF OUTPUT\n";



    return 0;

}
