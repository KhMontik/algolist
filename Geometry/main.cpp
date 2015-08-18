/*
Vector, Scalar multiplying
Point, line, circle sphere structures
Make line from 2 points
Line-point distance
Distance on sphere
Area of Triangle
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>   
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

#define abs(x) ((x) > 0 : (x) : -(x))
#define all(v) ((v).begin(), (v).end())
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define s second
#define f first
#define sz size 

struct pt {
	double x, y;
	ll operator * (pt a)  { // Vector Multiply                                 
		return (x*a.y - y*a.x);                     
                // also
                // len() * a.len() * sin (angle)
	}
        void operator += (pt a) {
            x += a.x;
            y += a.y;
        }
	pt operator - (pt a) {
		pt r;
		r.x = x-a.x;
		r.y = y-a.y;
		return r;	                                    	
	}
	ll operator ^ (pt a) { // Scalar Multiply
		return (x*a.x + y*a.y);	
                // also
                // len()*a.len() * cos(angle)
	}
	double dis (pt a) {
		return sqrtl(sq(x-a.x)+sq(y-a.y));
	}
        double len (){
            returb sqrtl(sq(x) + sq(y));
        }
        pt rotate (double ang) {
            pt r;
            r.x = x * cos(ang) - y * sin(ang);
            r.y = x * sin(ang) + y * cos(ang);
            return r;

            // ang  rad  cos sin 
            //  0    0    1   0
            //  90  pi/2  0   1
            // 180  pi   -1   0
            // 270 1.5pi  0  -1
            // 360  2pi   1   0
        }
};
struct line {
	double A, B, C;
	pt p, p1;
	void make (pt a, pt b) {
		A = b.y-a.y;
		B = a.x-b.x;
		C = -(A*a.x+B*a.y);
	}
	ll turn (pt a) {
		return (A*a.x+B*a.y+C);
	}
	double dis (pt a) {
		return fabs((A*a.x+B*a.y+C)/(sqrtl(sq(A)+sq(B))));
	}
};
struct circle {
	pt c;
	double r;
	int intersect (circle a)  {
		double d = c.dis(a.c);
		if (fabs(d - (r+a.r)) < eps) return 1;
	 	if (d > r+a.r+eps || d < fabs(r-a.r-eps)) return 0;
	 	return 2;	
	}
};
struct sphere_pt {
	int x, y, z, r;
	double al, bt;
	double dis_chord (sphere_pt &a) {
		return (sqrtl(sq(a.x-x)+sq(a.y-y)+sq(a.z-z)));
	}
	double dis (sphere_pt &a) {
	 	return acos(sin(al)*sin(a.al)+cos(al)*cos(a.al)*cos(fabs(bt-a.bt)))*r;
	}
};                 
                              
                                                                                 // matrix
double area (pt a, pt b, pt c) {                                                 // ax ay 1
	return 0.5*(a.x*b.y + a.y*c.x + c.y*b.x - b.y*c.x - a.y*b.x - a.x*c.y);  // bx by 1
}                                                                                // cx cy 1



int main ()
{
	freopen ("geometry.in", "r", stdin);
	freopen ("geometry.out", "w", stdout);


	return 0;
}
    
