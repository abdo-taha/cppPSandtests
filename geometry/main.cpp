#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long ) 1e18;
#define lp(i,a,n) for(long long i = a ; i < n ; ++i)
#define rep(i,vec) for(ll i = 0 ; i < vec.size() ; ++i)
#define reprv(i,vec) for(ll i = vec.size()-1; i >=0 ; --i)
#define eps (1e-5)
#define pb(i) push_back(i)
#define PI acos(-1.0)
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define length(a)               (hypot((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))
#define normalize(a)            (a)/length(a)
#define INF 1e9
#define EPS 1e-9
typedef vector<int> vi ;
typedef   long long ll;
typedef vector<ll> vll ;
typedef pair<int,int> pii ;
typedef vector< pair<int,int> >  vpii;
typedef vector<vector<int> > vvi ;

using namespace std;

typedef complex<double> point;


double DEG_to_RAD(double d) {
	return d * PI / 180.0;
}
double RAD_to_DEG(double r) {
	return r * 180.0 / PI;
}

double dcmp(double a , double b){
    return fabs(a-b) <= EPS ? 0 : a < b ? -1 : 1;
}

double fixAngle(double A){
    return A > 1 ? 1 : (A < -1 ? -1 : A);
}


double getSlope(point p1, point p2) {
	if (fabs(p1.X - p2.X) < EPS)
		return INF;
	return (p1.Y - p2.Y) / (p1.X - p2.X);
}

point reflect(point p, point p0, point p1) {
    point z = p-p0, w = p1-p0;
    return conj(z/w)*w + p0; // Refelect point p1 around p0p1
}
                    /** lines & points  **/


bool isCollinear(point a, point b, point c) {
	return fabs( cp(b-a, c-a) ) < EPS;
}
bool isPointOnRay(point p0, point p1, point p2) { /// p2 on p0 -> p1
    if(length(p2-p0) < EPS) return true;
    return same( normalize(p1-p0), normalize(p2-p0) );
}
bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a-b), ac = length(a-c), cb = length(b-c);
	return dcmp(acb-(ac+cb), 0) == 0;
}

double distToLine( point p0, point p1, point p2 ) {
	return fabs(cp(p1-p0, p2-p0)/length(p0-p1)); // area = 0.5*b*h
}
//distance from point p2 to segment p0-p1
double distToSegment( point p0, point p1, point p2 ) {
	double d1, d2;
	point v1 = p1-p0, v2 = p2-p0;
	if( (d1 = dp(v1, v2) ) <= 0)	return length(p2-p0);
	if( (d2 = dp(v1, v1) ) <= d1)	return length(p2-p1);
	double t = d1/d2;
	return length(p2 - (p0 + v1*t) );
}

struct line {
	double a, b, c; // ax + by + c = 0
};
line rotateLine(line l1 , double theta , bool rad = 1){
    if(!rad) theta = DEG_to_RAD(theta);
    line l2 ;
    l2.a = l1.a*cos(theta)-l1.b*sin(theta);
    l2.b = l1.a*sin(theta)+l1.b*cos(theta);
    l2.c=l1.c;
    return l2;

}

// the angle of line with x axis
point reflectPaboutLine(point p1 , double theta ,  bool rad = 1){
    if(!rad) theta = DEG_to_RAD(theta);
    point p2;
    p2.real( p1.X * cos(2*theta)+p1.Y * sin(2*theta) );
    p2.imag(p1.X * sin(2*theta)-p1.Y*cos(2*theta) );
    return p2;
}

void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.X - p2.X) < EPS) {	// vertical line
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.X;
	} else {
		// b is fixed to 1.0
		l.a = -(double) (p1.Y - p2.Y) / (p1.X - p2.X);
		l.b = 1.0;
		l.c = -(double) (l.a * p1.X) - p1.Y;
	}
}

void pointSlopeToLine(point p, double m, line &l) {
	if (fabs(m - INF) < EPS) {
		l.a = 1.0;
		l.b = 0;
		l.c = -p.X;
	} else {
		l.a = -m;
		l.b = 1.0;
		l.c = -((l.a * p.X) + (l.b * p.Y));
	}
}

void pointAngleToLine(point p , double theta , line &l){
    pointSlopeToLine(p,tan(theta),l);
}



                                    /** triangles **/



// A is angle a is side


double getSide_a_bAB(double b,double A,double B){
    return (sin(A)*b)/sin(B);
}

double getAngle_A_abB(double a , double b , double B){
    return asin( fixAngle( ((a*sin(B))/b) ) );
}

double getAngle_A_abc(double a , double b , double c){
    return acos( fixAngle( (b*b+c*c-a*a)/(2*b*c) ) );
}

double triangleArea(point p0 , point p1 , point p2){
    double a = length(p0-p1) , b = length(p0-p2), c = length(p1-p2);
    double s = (a+b+c)/2;
    return sqrt( s*(s-a)*(s-b)*(s-c) );

}

double rCircle3pointsout(point p0 , point p1 , point p2){
    double a = length(p0-p1) , b = length(p0-p2), c = length(p1-p2);
    double s = (a+b+c)/2;
    double area = sqrt( s*(s-a)*(s-b)*(s-c) );
    return (a*b*c) / (4*area);
}

double rCircle3pointsin(point p0 , point p1 , point p2){
    double a = length(p0-p1) , b = length(p0-p2), c = length(p1-p2);
    double s = (a+b+c)/2;
    return  sqrt( (s-a)*(s-b)*(s-c)/s ) ;
}

// m = 1  abc are median m=0 abc sides
double triangleArea(double a , double b, double c , bool m = 0){
    double s = 0.5*(a+b+c);
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
    if(m) return 4.0/3.0*area ;
    return area;
}

         /** circles **/



double sectorLength( double angle , double r , bool deg = 1){
    if(!deg) angle = RAD_to_DEG(deg);
    return deg / 360.0 * 2 * PI * r;
}
double sectionArea(double angle , double r , bool deg = 1){
    if(!deg) angle = RAD_to_DEG(deg);
    return deg / 360.0  * PI * r * r;
}


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    return 0;
}
