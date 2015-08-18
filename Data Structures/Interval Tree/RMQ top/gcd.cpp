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

#define l(x) (x<<1)
#define r(x) ((x<<1)+1)
 
const int N = 100007;
int n, t[4*N];

int gcd (int a, int b) {
	return (b == 0 ? a : gcd(b, a%b));
}

void build (int a[], int v = 1, int tl = 0, int tr = n-1) {
	if (tl == tr) t[v] = a[tl];
	else {
		int m = (tl+tr) >> 1;
		build (a, l(v), tl, m);
		build (a, r(v), m+1, tr);
		t[v] = gcd (t[l(v)], t[r(v)]);
	}
}
void update (int pos, int val, int v = 1, int tl = 0, int tr = n-1) {
	if (tl == tr) t[v] = val;
	else {
		int m = (tl + tr) >> 1;
		if (pos <= m) update (pos, val, l(v), tl, m);
		else	      update (pos, val, r(v), m+1, tr);
		t[v] = gcd (t[l(v)], t[r(v)]);
	}
}
int getgcd (int l, int r, int v = 1, int tl = 0, int tr = n-1) {
	if (l > r) return 0;
	if (tl == l && tr == r) return t[v];
	int m = (tl+tr) >> 1;
	return gcd ( getgcd (l, min(r,m), l(v), tl, m),
		     getgcd (max(m+1, l), r, r(v), m+1, tr));
}

int main ()
{
//	freopen ("gcd.in", "r", stdin);
//	freopen ("gcd.out", "w", stdout);
	
	int a[N];
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	build (a);
	for (;;) {
		int id, l, r, x, i;
		cin >> id;
		if (id == 1) cin >> l >> r, cout << getgcd(l-1, r-1) << endl; // GCD of Elements [l;r]
		if (id == 2) cin >> i >> x, update (i-1, x);		  // Update ith element to x
	}	

	return 0;
}
    
