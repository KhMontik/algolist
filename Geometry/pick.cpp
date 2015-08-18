/*
ID: kh.madi1
LANG: C++
PROG: fence9
*/
#include <algorithm>
#include <iostream>
#include <string.h>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>   
#include <cmath>
#include <queue>
#include <ctime>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <vector <int> >  vvi;
typedef vector <pair <int, int> >  vpi;
typedef queue  <pair <int, int> > qpi;

#define abs(x) ((x) > 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define mp make_pair
#define inf 7777777
#define eps (1e-7)
#define sz size()
#define s second
#define f first
 
struct pt {
	int x, y;
	pt operator - (pt a) {
		pt r;
		r.x = x-a.x;
		r.y = y-a.y;
		return r;
	}
	int operator * (pt a) {
		return x*a.y-y*a.x;
	}
}a, b, c;

int main ()
{
	freopen ("fence9.in", "r", stdin);
	freopen ("fence9.out", "w", stdout);
	
	int n, m, p;
	cin >> n >> m >> p;
	a.x = a.y = 0;
	b.x = n, b.y = m;
	c.x = p, c.y = 0;
	int area2 = abs((b-a)*(c-a));
	int border = 0;
	border += __gcd(abs(a.x-b.x),abs(a.y-b.y));
	border += __gcd(abs(b.x-c.x),abs(b.y-c.y));
	border += __gcd(abs(c.x-a.x),abs(c.y-a.y));
//	cout << area2 << " " << border << " " << endl;
	cout << (area2-border)/2+1 << endl;

	return 0;
}
    
