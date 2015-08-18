#include <iostream>
#include <fstream> 
#include <math.h>
#define eps 1e-10

using namespace std;

int main ()
{
	freopen ("rect.in", "r", stdin);
	freopen ("rect.out", "w", stdout);
	
	int oh, ow, kh, kw;
	int a, b, c, d;
	cin >> c >> d >> a >> b;

	oh = min (c, d);
	ow = max (c, d);
	kh = min (a, b);
	kw = max (a, b);

	if (oh <= kh && ow <= kw){	cout <<"YES";return 0;}

        else if (oh <= kh && ow <= kw){		cout <<"YES";return 0;}
        else if (oh <= kh && ow > kw) {
        	double ca, fc;
        	ca = sqrtl(ow*ow+oh*oh);
        	fc = sqrtl(ca*ca-kh*kh); 
        	double cab, fac, baf, bae, daf;
        	cab = atan2 (oh, ow);
        	fac = atan2 (fc, kh);
        	baf = cab+fac;
        	bae = M_PI/2-baf;
        	long double ge;
        	ge = oh*sin(bae)+ow*cos(bae);
        	if (ge <= kw+eps){	cout << "YES";return 0;}
        }

        cout << "NO";

	return 0;
}