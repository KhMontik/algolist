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
 
const int N = 70000;
int ff = 0, root = -1;
int nx[N];
struct vertex {
	int l, r, xl, xr, pr;
	int mx, mn;
	vertex() {
		l = r = xl = xr = mx = pr = -1;
		mn = inf;
	}
	bool operator == (const vertex &a) {
		return (l == a.l && r == a.r && xr == a.xr && xl == a.xl);
	}
} a[N];
int c[5000000]={0};
void add (int xl, int xr) {
	if (root == -1) {
		root = ff++;
		a[root].xl = xl;
		a[root].xr = xr;
		a[root].mx = xr;
		a[root].mn = xl;
		a[root].l = a[root].r = -1;
		return;
	}
	int i = root;
	int s = ff;
	while (s == ff) {
		if (xl < a[i].xl) {
			if (a[i].l == -1) {
				a[i].l = ff; 
				a[ff].xl = xl; 
				a[ff].xr = xr;
				a[ff].mx = xr;
				a[ff].mn = xl;
				a[ff].pr = i;
				c[ff] = 1;
				int j = ff;
				while (j != -1) {
					j = a[j].pr;
					if (a[j].l != -1) a[j].mx = max (a[j].mx, a[a[j].l].mx), a[j].mn = min (a[j].mn, a[a[j].l].mn);
					if (a[j].r != -1) a[j].mx = max (a[j].mx, a[a[j].r].mx), a[j].mn = min (a[j].mn, a[a[j].r].mn);
				}
				ff++;
			}
			else 		  i = a[i].l;
		}
		else {
			if (a[i].r == -1) {
				a[i].r = ff;                                      
				a[ff].xl = xl; 
				a[ff].xr = xr;
				a[ff].mx = xr;		
				a[ff].mn = xl;
				a[ff].pr = i;
				c[ff] = 1;
				int j = ff;
				while (j != -1) {
					j = a[j].pr;
					if (a[j].l != -1) a[j].mx = max (a[j].mx, a[a[j].l].mx), a[j].mn = min (a[j].mn, a[a[j].l].mn);
					if (a[j].r != -1) a[j].mx = max (a[j].mx, a[a[j].r].mx), a[j].mn = min (a[j].mn, a[a[j].r].mn);
				}
				ff++;
			}
			else		  i = a[i].r;
		}
	}
}

                        /*
void del (int i) {
	if (a[i].l == -1 && a[i].r == -1) {
		a[i].xl = a[i].xr = a[i].mx = -1;
		a[i].mn = inf;
		nx[i] = ff;
		ff = i;	
	}else
	if (a[i].l != -1) {
		int x = a[i].pr;
		if (x == -1) {
			root = a[i].l;
			a[a[i].l].pr = -1;
			a[i].xl = a[i].xr = a[i].mx = -1;
			a[i].mn = inf;
			nx[i] = ff;
			ff = i;		
		}else {
			if (a[a[x].l] == a[i]) {
				a[x].l = a[i].l, a[a[i].l].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].l].mx);
				a[x].mn = min (a[x].mn, a[a[i].l].mn);
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
			else if (a[a[x].r] == a[i]) {
				a[x].r = a[i].l, a[a[i].l].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].l].mx);
				a[x].mn = min (a[x].mn, a[a[i].l].mn);
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
		}
	}else 
	if (a[i].r != -1) {
		int x = a[i].pr;
		if (x == -1) {
			root = a[i].r;
			a[a[i].r].pr = -1;
			a[i].xl = a[i].xr = a[i].mx = -1;a[i].mn = inf;nx[i] = ff;ff = i;		
		}else {
			if (a[a[x].l] == a[i]) {
				a[x].l = a[i].r, a[a[i].r].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].r].mx);
				a[x].mn = min (a[x].mn, a[a[i].r].mn);
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
			else if (a[a[x].r] == a[i]) {
				a[x].r = a[i].r, a[a[i].r].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].r].mx);
				a[x].mn = min (a[x].mn, a[a[i].r].mn);
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
		}
	}
	else {
		int x = a[i].pr;
		if (x == -1) {
			root = a[i].r;
			a[a[i].r].l = a[i].l;a[a[i].r].pr = -1, a[a[i].l].pr = a[i].r;
			a[i].xl = a[i].xr = a[i].mx = -1;a[i].mn = inf;nx[i] = ff;ff = i;
		}else {
			if (a[a[x].l] == a[i]) {
				a[x].l = a[i].r, a[a[i].r].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].r].mx);
				a[x].mn = min (a[x].mn, a[a[i].r].mn);
				a[a[i].r].l = a[i].l;a[a[i].r].pr = -1, a[a[i].l].pr = a[i].r;
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
			else if (a[a[x].r] == a[i]) {
				a[x].r = a[i].r, a[a[i].r].pr = x;
				a[x].mx = max (a[x].mx, a[a[i].r].mx);
				a[x].mn = min (a[x].mn, a[a[i].r].mn);
				a[a[i].r].l = a[i].l;a[a[i].r].pr = -1, a[a[i].l].pr = a[i].r;
				a[i].xl = a[i].xr = a[i].mx = -1;
				a[i].mn = inf;
				nx[i] = ff;
				ff = i;		
			}
		}
	}
}

                   */


void print (int i) {
	if (a[i].l != -1) print(a[i].l);
	if (a[i].r != -1) print(a[i].r);
	cout << i << " " << a[i].xl << " " << a[i].xr << endl ;//<< " " << a[i].mx << " "  << a[i].mn << endl;
}
int intersect (int l, int r, int i) {
	int res = 0;
	if (a[i].xl <= r && l <= a[i].xr) res = c[i], c[i] = 0;
	if (a[i].l != -1 && a[a[i].l].mx >= l) res += intersect (l, r, a[i].l);
	if (a[i].r != -1 && a[a[i].r].mn <= r) res += intersect (l, r, a[i].r);
	return res;
}
int main ()
{
	freopen ("bsts.in", "r", stdin);
	freopen ("bsts.out", "w", stdout);

	int n;
	int l, r;
	cin >> n;
	for (int i = 0; i < N; i++) nx[i] = i+1;
	for (int i = 0; i < n; i++) 	cin >> l >> r, add(l, r);
	print(root);
//	del(7);
	print(root);

	return 0;
}
    
