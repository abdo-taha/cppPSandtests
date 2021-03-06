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

int orientation(point p1, point p2, point p3)
{

    int val = (p2.Y - p1.Y) * (p3.X - p2.X) -
              (p2.X - p1.X) * (p3.Y - p2.Y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
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




bool intersectSegments(point a, point b, point c, point d, point & intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false;  // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;
    /// till here they intersecting lines
    /// t1 for ab t2 for cd
    /// t1<-eps is not on ray ab t2 < -eps not on ray cd
    ///  t2 < -EPS || t2 > 1 + EPS not on segment cd
    ///  t1 < -EPS || t1 > 1 + EPS not on segment ab

  if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
    return false;  //e.g ab is ray, cd is segment ... change to whatever
  return true;
}

// Where is P2 relative to segment p0-p1?
// ccw = +1 => angle > 0 or collinear after p1
// cw = -1 => angle < 0 or collinear after p0
// Undefined = 0 => Collinar in range [a, b]. Be careful here
int ccw(point a, point b, point c) {
  point v1(b - a), v2(c - a);
  double t = cp(v1, v2);

  if (t > +EPS)
	return +1;
  if (t < -EPS)
	return -1;
  if (v1.X * v2.X < -EPS || v1.Y * v2.Y < -EPS)
	return -1;
  if (norm(v1) < norm(v2) - EPS)
	return +1;
  return 0;
}

bool intersect(point p1, point p2, point p3, point p4) {
    // special case handling if a segment is just a point
    bool x = (p1 == p2), y = (p3==p4);
    if(x && y)  return p1 == p3;
    if(x)   return ccw(p3, p4, p1) == 0;
    if(y)   return ccw(p1, p2, p3) == 0;

    return  ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0  &&
        ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
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



double ang3Points(point b , point a , point c){
    double la = length( b-c ) , lb = length( a-c ) , lc = length( a-b );
    return getAngle_A_abc(la,lb,lc);

}


         /** circles **/



double sectorLength( double angle , double r , bool deg = 1){
    if(!deg) angle = RAD_to_DEG(angle);
    return angle / 360.0 * 2 * PI * r;
}
double sectionArea(double angle , double r , bool deg = 1){
    if(!deg) angle = RAD_to_DEG(angle);
    return angle / 360.0  * PI * r * r;
}

// 2 points has infinite circles
// Find circle passes with 3 points, some times, there is no circle! (in case colinear)
// Draw two perpendicular lines and intersect them
// may be see https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-line-intersection-and-its-applications/
pair<double, point> findCircle(point a, point b, point c) {
	//create median, vector, its prependicular
	point m1 = (b+a)*0.5, v1 = b-a, pv1 = point(v1.Y, -v1.X);
	point m2 = (b+c)*0.5, v2 = b-c, pv2 = point(v2.Y, -v2.X);
	point end1 = m1+pv1, end2 = m2+pv2, center;
	intersectSegments(m1, end1, m2, end2, center);
	return make_pair( length(a-center), center );
}

// If line intersect cirlce at point p, and p = p0 + t(p1-p0)
// Then (p-c)(p-c) = r^2 substitute p and rearrange
// (p1-p0)(p1-p0)t^2 + 2(p1-p0)(p0-C)t + (p0-C)(p0-C) = r*r; -> Quadratic
vector<point> intersectLineCircle(point p0, point p1, point C, double r) {
    double a = dp(p1-p0, p1-p0), b = 2*dp(p1-p0, p0-C),
           c = dp(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<point> v;
    if( dcmp(f, 0) >= 0) {
	    if( dcmp(f, 0) == 0)	f = 0;
	    double t1 =(-b + sqrt(f))/(2*a);
	    double t2 =(-b - sqrt(f))/(2*a);
	    v.push_back( p0 + t1*(p1-p0) );
	    if( dcmp(f, 0) != 0)	v.push_back( p0 + t2*(p1-p0) );
    }
    return v;
}

vector<point> intersectCircleCircle(point c1, double r1, point c2, double r2) {
  // Handle infinity case first: same center/radius and r > 0
  if (same(c1, c2) && dcmp(r1, r2) == 0 && dcmp(r1, 0) > 0)
    return vector<point>(3, c1);    // infinity 2 same circles (not points)

  // Compute 2 intersection case and handle 0, 1, 2 cases
  double ang1 = angle(c2 - c1), ang2 = getAngle_A_abc(r2, r1, length(c2 - c1));

  if(isnan(ang2)) // if r1 or d = 0 => nan in getAngle_A_abc (/0)
    ang2 = 0; // fix corruption

  vector<point> v(1, polar(r1, ang1 + ang2) + c1);

  // if point NOT on the 2 circles = no intersection
  if(dcmp(dp(v[0]-c1, v[0]-c1), r1*r1) != 0 ||
      dcmp(dp(v[0]-c2, v[0]-c2), r2*r2) != 0 )
    return vector<point>();

  v.push_back(polar(r1, ang1 - ang2) + c1);
  if(same(v[0], v[1]))  // if same, then 1 intersection only
    v.pop_back();
  return v;
}


const int MAX = 100000+9;
point pnts[MAX], r[3], cen;
double rad;
int ps, rs;	// ps = n, rs = 0, initially

// Pre condition
// random_shuffle(pnts, pnts+ps);		rs = 0;
void MEC() {
	if(ps == 0 && rs == 2) {
		cen = (r[0]+r[1])/2.0;
		rad = length(r[0]-cen);
	}
	else if(rs == 3) {
		pair<double, point> p = findCircle(r[0], r[1], r[2]);
		cen = p.second;
		rad = p.first;
	}
	else if(ps == 0) {
		cen = r[0];	// sometime be garbage, but will not affect
		rad = 0;
	}
	else {
		ps--;
		MEC();

		if(length(pnts[ps]-cen) > rad) {
			r[rs++] = pnts[ps];
			MEC();
			rs--;
		}

		ps++;
	}
}






int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
//    freopen( "output.txt" , "w" , stdout ) ;
//    freopen( "input.txt" , "r" , stdin ) ;


    return 0;
}
