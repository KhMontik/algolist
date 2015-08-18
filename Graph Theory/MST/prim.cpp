/*
ID: kh.madi1
LANG: C++
PROG: agrinet
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
 

int main ()
{
	freopen ("prim.in", "r", stdin);
	freopen ("prim.out", "w", stdout);
	
	int n, a[111][111];
	bool u[111] = {0};
	int d[111];

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	cin >> a[i][j], d[j] = inf;
	int x = 0;
	d[0] = 0;
	do {
		for (int i = 0; i < n; i++) 
			if (a[x][i] > 0 && d[i] > a[x][i] && !u[i]) d[i] = a[x][i];
		u[x] = 1;
		x = -1;
		for (int i = 0; i < n; i++) 
			if ((x == -1 || d[x] > d[i]) && !u[i]) x = i;
	}while (x != -1);
	int res = 0;	
	for (int i = 0; i < n; i++) res += d[i];
	cout << res << endl;

	return 0;
}
    

