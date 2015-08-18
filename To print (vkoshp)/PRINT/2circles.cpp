// 2 CIRCLES

#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#define eps 1e-8

using namespace std;

double dis (double x, double y, double x1, double y1) {
	return (sqrtl((x-x1)*(x-x1)+(y-y1)*(y-y1)));
}

struct pt{
	double x, y;
};
struct circle{
	double x, y, r;
	bool operator == (const circle &a) {
		return (x == a.x && y == a.y && r == a.r);
	}
	int inter (const circle &a) {
		double d = sqrtl((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y));
	
		if (d > r+a.r || d < fabs(r-a.r))	return 0;
		if (fabs(r-a.r) < d && d < a.r+r)	return 2;
		if (d == (r+a.r) || d == fabs(r-a.r)) 	return 1;
	}
} a, b, c;

int main()
{
	freopen ("gps.in", "r", stdin);
	freopen ("gps.out", "w", stdout);

	int k=1, i;

		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
		cin >> a.r >> b.r >> c.r;
		if (a == c) {
			if (a.inter (b) == 0) {
				cout << "Impossible";
				return 0;
			}
			
			double d = fabs(dis(a.x, a.y, b.x, b.y));
			double OH = (((a.r*a.r)+(d*d))-(b.r*b.r))/(2*d);
			double HP = sqrt(a.r*a.r - OH*OH);
			pt v2;
			pt v;
			pt v3;      // O1H
			pt v4;
			v2.x = b.x - a.x;
			v2.y = b.y - a.y;
			
			v.x = (OH/d)*v2.x;
			v.y = (OH/d)*v2.y; 
			        
			v3.x = b.y-a.y;
			v3.y = a.x-b.x;


			double d1 = fabs(sqrt(v3.x*v3.x + v3.y*v3.y));


			v4.x = HP/d1*v3.x;
			v4.y = HP/d1*v3.y;

			printf ("%.8f %.8f\n\n",   a.x + v.x - v4.x, a.y + v.y - v4.y);
	
		}
		if (a.inter(b) == 0) {
			cout << "Impossible";
			return 0;
		}
		if (a.inter(b) == 1) {
			double d = fabs(dis(a.x, a.y, b.x, b.y));
			double OH = (((a.r*a.r)+(d*d))-(b.r*b.r))/(2*d);
			double HP = sqrt(a.r*a.r - OH*OH);
			pt v2;
			pt v;
			pt v3;      // O1H
			pt v4;
			v2.x = b.x - a.x;
			v2.y = b.y - a.y;
			
			v.x = (OH/d)*v2.x;
			v.y = (OH/d)*v2.y; 
			        
			v3.x = b.y-a.y;
			v3.y = a.x-b.x;


			double d1 = fabs(sqrt(v3.x*v3.x + v3.y*v3.y));


			v4.x = HP/d1*v3.x;
			v4.y = HP/d1*v3.y;


			printf ("%.8f %.8f\n\n",   a.x + v.x - v4.x, a.y + v.y - v4.y);
			return 0;
		}
		if (a.inter(b) == 2) {
			double x, y, x1, x2;
			double d = fabs(dis(a.x, a.y, b.x, b.y));
			double OH = (((a.r*a.r)+(d*d))-(b.r*b.r))/(2*d);
			double HP = sqrt(a.r*a.r - OH*OH);
			pt v2;
			pt v;
			pt v3;      // O1H
			pt v4;
			pt v5;
			pt v6;
			v2.x = b.x - a.x;
			v2.y = b.y - a.y;
			
			v.x = (OH/d)*v2.x;
			v.y = (OH/d)*v2.y; 

			        
			v3.x = b.y-a.y;
			v3.y = a.x-b.x;


			double d1 = fabs(sqrt(v3.x*v3.x + v3.y*v3.y));


			v4.x = HP/d1*v3.x;
			v4.y = HP/d1*v3.y;

			pt r, r1;
			if (a.x + v.x - v4.x < a.x + v.x + v4.x || a.x + v.x + v4.x == a.x + v.x - v4.x && a.y + v.y - v4.y  < a.y + v.y + v4.y) {
				r.x = a.x + v.x - v4.x;
				r.y = a.y + v.y - v4.y;
				r1.x = a.x + v.x + v4.x;
				r1.y = a.y + v.y + v4.y;
			}
			else {
				r1.x = a.x + v.x - v4.x;
				r1.y = a.y + v.y - v4.y;
				r.x = a.x + v.x + v4.x;
				r.y = a.y + v.y + v4.y;
			}
			if (fabs(c.r - dis(r.x, r.y, c.x, c.y)) < eps)   {
				printf ("%.8f %.8f\n",   r.x, r.y);
				return 0;	
			}
			if (fabs(c.r - dis(r1.x, r1.y, c.x, c.y)) < eps) {
				printf ("%.8f %.8f\n\n", r1.x, r1.y);
				return 0;
			}
		}
		cout << "Impossible";
	return 0;
}
/*
	(ax-x)^2 + (ay-y)^2 - r  = 0
	(bx-x)^2 + (by-y)^2 - r1 = 0

	(ax-x)^2 + ay^2 - 2yay + y^2 - r = 0    2by
	(bx-x)^2 + by^2 - 2yby + y^2 - r1 = 0   -2ay

	(ax-x)^2*2by + 2byay^2 + 2byy^2 - 2rby = 0
	-(bx-x)^2*2ay - 2ayby^2 - 2ayy^2 + 2r1ay = 0

	(ax-x)^2*2by + 2byay^2 




*/
