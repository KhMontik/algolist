#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>


using namespace std;

const int N = 100500;

struct pt {
	long long x, y;
	pt(){}
	pt(long long a, long long b) {x = a, y = b;}
	pt operator - (pt a) {
		return pt(x-a.x,y-a.y);
	}
	long long operator * (pt a) {
		long long d = x*1LL*a.y-y*1LL*a.x;
		return d;
	}
	long double len () {
		return sqrtl(x*1LL*x+y*1LL*y);
	}
}a[N], p;

bool cmp (pt a, pt b) {
	return (a*b > 0 || (a*b == 0 && a.x*1LL*a.x+a.y*1LL*a.y > b.x*1LL*b.x+b.y*1LL*b.y));
}

int n, k;
long long x, y;

bool border (pt a, pt b, pt p){
	if ((b-a).len() == 0) return 0;
	return ((a-p)*(b-p) == 0 && (a-p).len()+(p-b).len() == (a-b).len());
}
int sg (long long z) {
	if (z > 0) return 1;
	if (z < 0) return -1;
	return 0;
}
bool inside (pt a, pt b, pt c, pt p) {
        int d = sg((b-a)*(p-a));
        int d1 =sg((c-b)*(p-b));
        int d2 =sg((a-c)*(p-c));

        if (d1 == 0)d1 = d2;
        if (d == 0) d = d1;
        if (d == 0) return 0;
        return d == d1 && d == d2;
}
pt base;
int main ()
{
	freopen ("inside.in", "r", stdin);
	freopen ("inside.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf ("%lld%lld", &a[i].x, &a[i].y);
		if (base.x < a[i].x || (base.x == a[i].x && base.y < a[i].y)) base = a[i];
	}
	for (int i = 0; i < n; i++) a[i] = a[i]-base;
	sort (a, a+n, &cmp);
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf ("%lld%lld", &p.x,&p.y);
		p = p-base;
		int l = 0, r = n-1;
		while (r-l > 1) {
			int m = (l+r) >> 1;
			if ((p-a[0])*(a[m]-a[0]) >= 0) r = m;
			else			       l = m;		
		}
		if (border (a[0],a[1],p) || border(a[0],a[n-1],p) || border(a[l],a[r],p)) {puts("BORDER");continue;}
		else if (inside(a[l],a[r],a[0], p) || inside(a[0],a[n-1],a[n-2],p) || inside(a[0],a[1],a[n-1],p)) puts("INSIDE");
		else	puts("OUTSIDE");
	}
	return 0;
}

