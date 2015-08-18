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
struct vertex {
	int l, r, key;
	vertex() {
		l = r = key = -1;
	}
} a[N];

void add (int x) {
	if (root == -1) {
		root = ff++;
		a[root].key = x;
		a[root].l = a[root].r = -1;
		return;
	}
	int i = root;
	int s = ff;
	while (s == ff) {
		if (x < a[i].key) {
			if (a[i].l == -1) a[i].l = ff, a[ff].key = x, ff++;
			else 		  i = a[i].l;
		}
		else {
			if (a[i].r == -1) a[i].r = ff, a[ff].key = x, ff++;
			else		  i = a[i].r;
		}
	}
}

void print (int i) {
	if (a[i].l != -1) print(a[i].l);
	if (a[i].r != -1) print(a[i].r);
	cout << a[i].key << " ";
}
int main ()
{
	freopen ("bst.in", "r", stdin);
	freopen ("bst.out", "w", stdout);

	int n;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) 	cin >> x, add(x);
	print(root);

	return 0;
}
    
