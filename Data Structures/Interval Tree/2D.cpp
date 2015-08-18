/*
** Khamitbekov Madi
** Kazakhstan, Almaty
** Kazakh-Turkish High School, 2011
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
 
int a[121][121];
int n, m;
int t[500][500];
int k;

void build () {
	for (int i = 2*n-1; i >= 1; i--) {
		if (i >= n) {
			for (int j = 2*m-1; j >= 1; j--) {
				if (j >= m)t[i][j] = a[i-n][j-m];
				else	   t[i][j] = t[i][j*2]+t[i][j*2+1];
			}
		}else {
			for (int j = 2*m-1; j >= 1; j--) 
				t[i][j] = t[i*2][j] + t[i*2+1][j];
		}
	}
}
int get_y (int i, int l, int r) {
	l += m-1;
	r += m-1;
	int res = 0;
	while (l <= r) {
		if (l&1) res += t[i][l];
		if (!(r&1))res += t[i][r];
		l = (l+1) >> 1;
		r = (r-1) >> 1;
	}
	return res;
}
int get_x (int x, int y, int x1, int y1) {
	int l = x + n-1;
	int r = x1 + n-1;
	int ans = 0;
	while (l <= r) {
		if (l&1)   ans += get_y(l,y,y1);	
		if (!(r&1))ans += get_y(r,y,y1);
		l = (l+1) >> 1;
		r = (r-1) >> 1;
	}
	return ans;
}
void update (int x, int y, int key) {
	x += n-1;
	y += m-1;
	t[x][y] += key;
	while (x > 1) {
		int yy = y;
		while (yy > 1) {
			yy >>= 1;
			t[x][yy] = t[x][yy*2]+t[x][yy*2+1];			
		}
		x >>= 1;
	}
}

int main ()
{
	freopen ("rsq.in", "r", stdin);
	freopen ("rsq.out", "w", stdout);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	build();
	int x, y, x1, y1;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> x1 >> y1;
		cout << get_x(x,y,x1,y1) << endl;
	}

	return 0;
}
    
