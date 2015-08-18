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
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <vector <int> >  vvi;
typedef vector < pair <int, int> >  vpi;
typedef queue <pair <int, int> > qpi;

#define abs(x) ((x) > 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define mp make_pair
#define inf 7777777
#define sz size()
#define s second                                                                                                                     
#define f first
 
int gcd (int a, int b, int &x, int &y) {
	if (a == 0) {
		x = 0, y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

int main ()
{
	freopen ("gcd.in", "r", stdin);
	freopen ("gcd.out", "w", stdout);

	int x, y;
	int a, b;
	cin >> a >> b;
	cout << gcd (a, b, x, y) << " " << x << " " << y;

	return 0;
}
    
