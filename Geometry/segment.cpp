// Solution by Khamitbekov Madi
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

struct pt {
	double x, y;
	int operator * (const pt &a) {
		if (x*a.y - y*a.x > 0) return 1;
		if (x*a.y - y*a.x < 0) return -1;
		return 0;		
	}
	pt operator - (const pt &a) {
		pt r;
		r.x = x - a.x;
		r.y = y - a.y;
		return r;
	}
	bool operator < (const pt &a) const {
		if (x < a.x) return 1;
		if (x > a.x) return 0;
		if (y < a.y) return 1;
		return 0;
	}
	bool operator > (const pt &a) const {
		if (x > a.x) return 1;
		if (x < a.x) return 0;
		if (y > a.y) return 1;
		return 0;
	}

	void operator = (const pt &a)  {
		x = a.x;
		y = a.y;
	}
	bool operator == (const pt &a) {
		return (a.x == x && y == a.y);
	}
}a, b, c, d;

pt lin_in ()  {
	double A = b.y - a.y;
	double B = a.x - b.x;
	double C = -A*a.x-B*a.y;
	double A1 = d.y - c.y;
	double B1 = c.x - d.x;
	double C1 = -A1*c.x - B1*c.y;
	pt res;
	res.x = (C * B1 - B * C1) / (B * A1 - A * B1);
	res.y = (A * C1 - C * A1) / (B * A1 - A * B1);
	return res;
}
bool rect_in () {
	return ( max (a.x, b.x) >= min (c.x, d.x) &&
		 max (a.y, b.y) >= min (c.y, d.y) &&
		 max (c.x, d.x) >= min (a.x, b.x) &&
		 max (c.y, d.y) >= min (a.y, b.y));
}

int main () 
{                	
//	freopen ("a.in", "r", stdin);
//	freopen ("a.out", "w", stdout);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	
	if (!rect_in ()) {
		cout << "NONE";
		return 0;
	}
	if (((b-a)*(c-a)) * ((b-a)*(d-a)) > 0) {
		cout << "NONE";
		return 0;
	}
	if (((d-c)*(a-c)) * ((d-c)*(b-c)) > 0) {
		cout << "NONE";
		return 0;
	}
	if (((d-c)*(a-c)) == 0 && ((d-c)*(b-c)) == 0 && ((b-a)*(c-a)) == 0 && ((b-a)*(d-a)) == 0)   {
		if (a > b) swap (a, b);
		if (c > d) swap (c, d);
		pt minp, maxp;
		minp = min (min (min (a, b), c), d);
		maxp = max (max (max (a, b), c), d);
		if (a == b){printf ("POINT %.10f %.10f", b.x, b.y); return 0;} 
		if (c == d){printf ("POINT %.10f %.10f", c.x, c.y); return 0;}
		if (minp.x == a.x && minp.y == a.y) {
			
			if (maxp.x == b.x && maxp.y == b.y)printf ("SEGMENT %d %d %d %d", (int)c.x, (int)c.y, (int)d.x, (int)d.y);
			else if (b == c)		   printf ("POINT %.10f %.10f", b.x, b.y);
			else 				   printf ("SEGMENT %d %d %d %d", (int)min(b,c).x, (int)min(b,c).y, (int)max(b,c).x, (int)max(b,c).y);
		}
		else {
			if (maxp.x == d.x && maxp.y == d.y)printf ("SEGMENT %d %d %d %d", (int)a.x, (int)a.y, (int)b.x, (int)b.y);
			else if (d == a) 		   printf ("POINT %.10f %.10f", a.x, a.y);
			else 				   printf ("SEGMENT %d %d %d %d", (int)min(d,a).x, (int)min(a,d).y, (int)max(a,d).x, (int)max(d,a).y);		
		}
	}
	else {
		cout << "POINT ";
		pt r = lin_in ();
		printf ("%.10f %.10f", r.x, r.y);
	}

	return 0;
}
