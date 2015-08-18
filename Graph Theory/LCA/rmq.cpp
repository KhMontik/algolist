#pragma comment (linker, "/STACK:64000000")

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

#define pb push_back
#define sz size()
#define ADD 262144


const int N = 1000777;

int n, m;
int root;
int tin[N], tout[N], fup[N];
vector <int> a[N], id[N], bg[N];
bool u[N] = {0};
int c = 0;
int f[5*N], t[5*N], br[5*N]={0}, d[N]={0}, col[N];
int lvl = 0;
int cols = 1;

void dfs (int x, int p = -1) {
	u[x] = 1;
	fup[x] = tin[x] = c++;
	for (int i = 0; i < a[x].sz; i++) {
		int j = a[x][i];
		if (j == p) continue;
		if (u[j]) fup[x] = min (fup[x], tin[j]);	
		else {
			dfs(j,x);
			d[x] += d[j];
			fup[x] = min(fup[x], fup[j]);
			if (fup[j] > tin[x]) 	br[id[x][i]] = 1;
		}
	}
	tout[x] = c++;
}

int rmq[N+N+1];
int tmp[N+N+1];
int rmqs = 0, tmps = 0;
int tr[4*ADD+1] = {0};
int tid[4*ADD+1]  ={0};
int pos[N+N+1];

void calc(int x, int level = 0) {
	u[x] = 1;
	rmq[rmqs++] = x;
	pos[x] = rmqs-1;
	tmp[tmps++] = level;
	d[x] = level;
	for (int i = 0; i < bg[x].sz; i++)
		if (!u[bg[x][i]]) calc (bg[x][i],level+1), 	rmq[rmqs++] = x,	tmp[tmps++] = level;

}
void paint (int x) {
	col[x] = cols;
	for (int i = 0; i < a[x].sz; i++)
		if (!col[a[x][i]] && !br[id[x][i]]) paint(a[x][i]);
}

#define inf 1000000000

int get (int l, int r) {
	if (l > r) swap (l,r);
	l += ADD;
	r += ADD;
	int mn = inf, id = -1;
	while (l <= r) {
		if (l & 1) {
			if (id == -1|| mn > tr[l]) id = tid[l], mn = tr[l];
		}
		if (!(r&1)) {
			if (id == -1 || mn > tr[r]) id = tid[r], mn = tr[r];
		}
		l = (l+1) >> 1;
		r = (r-1) >> 1; 
	}
	return rmq[id];
}
int lca (int a, int b) {
//	cout << a << " " << b << " = ";
  //      cout << get (pos[a],pos[b]) << " -> ";
	return get (pos[a],pos[b]);
}

int main ()
{
	freopen ("magic.in", "r", stdin);
	freopen ("magic.out", "w", stdout);

	int x, y;
	cin >> n >> m;
	while ((1<<lvl) < n) lvl++;
	cin >> root;
	root--;
	for (int i = 0; i < m; i++) {
		scanf ("%d %d\n", &x, &y);
		x--, y--;
		f[i] = x, t[i] = y;
		a[x].pb (y), a[y].pb (x);
		id[x].pb (i), id[y].pb (i);	
	}
	dfs (root);
	for (int i = 0; i < n; i++) col[i] = 0;
	for (int i = 0; i < n; i++)
		if (!col[i]) paint(i), cols++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].sz; j++) {
			if (!br[id[i][j]])continue;
			bg[col[i]].pb (col[a[i][j]]);
		}
	}
	for (int i = 0; i < n; i++) u[i] = 0, d[i] = 0;
	calc(col[root]);
//	for (int i = 0; i < n; i++)
//		cout << i+1 << " " << col[i] << " " << d[col[i]] << endl;
//	for (int i = 0; i < rmqs; i++)	cout << rmq[i] << " "; cout << endl;
//	for (int i = 0; i < rmqs; i++)	cout << tmp[i] << " ";
	for (int i = 0; i < ADD+ADD; i++)  tr[i] = inf;
	for (int i = ADD; i < ADD+tmps; i++) tr[i] = tmp[i-ADD],tid[i] = i-ADD;
	for (int i = ADD-1; i >= 1; i--)    {
	         if (tr[i<<1] < tr[(i<<1)+1]) tr[i] = tr[i<<1], tid[i] = tid[i<<1];
	         else 			      tr[i] = tr[(i<<1)+1], tid[i] = tid[(i<<1)+1];
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		scanf ("%d %d\n", &x, &y);
		printf ("%d\n", d[lca(col[x-1],col[y-1])]);
	}

	return 0;
}
