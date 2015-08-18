#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

const int N = 100500;
#define pb push_back

vector <int> g[N], a[N], q[N], id[N];
bool bad[5*N];
int tin[N], fup[N], col[N];
int q1[N], q2[N];

int n, m, root, c = 1, sz = 1;
bool u[N];

void dfs (int x, int pr = -1) {   // bridges
	u[x] = 1;
	tin[x] = fup[x] = c++;
	for (int i = 0; i < a[x].size(); i++) {
		int j = a[x][i];
		if (j == pr) continue;
		if (u[j])    fup[x] = min (fup[x], tin[j]);
		else {
			dfs (j,x);
			fup[x] = min(fup[x], fup[j]);
			if (tin[x] < fup[j]) bad[id[x][i]] = 1;
		}
	}
}
void color (int x) {
	col[x] = sz;
	for (int i = 0; i < a[x].size(); i++) {
		int j = a[x][i];
		if (!bad[id[x][i]] && !col[j]) color(j);
	}
}

int p[N], r[N]={0}, anc[N], lca[N], d[N];				//DSU
int fs (int x) {
	if (p[x] != x) p[x] = fs (p[x]);
	return p[x];
}
void un (int x, int y, int z) {
	//printf ("union(%d,%d), ancestor = %d\n", x,y,z);
	if (r[x] > r[y]) p[y] = x;
	else		 p[x] = y;
	if (r[x] == r[y])r[y]++;
	anc[fs(x)] = z;
}
void dfs_dsu (int x, int lvl = 0) {
	//cout << x << " ";
	p[x] = anc[x] = x;
	u[x] = 1;
	d[x] = lvl;
	for (int i = 0; i < g[x].size(); i++) {
		int j = g[x][i];
		if (!u[j]) dfs_dsu(j,lvl+1), un(fs(x),fs(j),x);
	}
	
	for (int i = 0; i < q[x].size(); i++) {
		int id = q[x][i];
		int y = q1[id];
		if (y == x) y = q2[id];
		if (u[y])/*cout << " q " << x << " " << y << " = " << anc[fs(y)] << endl, */lca[id] = anc[fs(y)]; 
	}
	//cout << " out\n";
}
int main()
{
	freopen ("magic.in", "r", stdin);
	freopen ("magic.out", "w", stdout);
	
	int x, y;
	cin >> n >> m >> root;root--;
	for (int i = 0; i < m; i++) {
		scanf ("%d%d", &x, &y), x--, y--;
		a[x].pb(y), a[y].pb(x);
		id[x].pb(i), id[y].pb(i);
	}
	/****************************/
	dfs (root);
	for (int i = 0; i < n; i++) {
		if (!col[i]) color(i), sz++;
		u[i] = 0;
	}
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < a[i].size(); j++) 
			if (bad[id[i][j]]) g[col[i]].pb (col[a[i][j]]);
	/****************************/
	
	int k;
	cin >> k;
	for (int i = 0;i < k; i++) {
		scanf ("%d%d",&x,&y);q1[i] = col[x-1];q2[i] = col[y-1];
		q[q1[i]].pb(i);
		q[q2[i]].pb(i);
		if (q1[i] == q2[i]) lca[i] = q1[i];
	}
	dfs_dsu(col[root]);
	for (int i = 0; i < k; i++) {
		printf ("%d\n", d[lca[i]]);
	//	printf ("lca[%d;%d] == %d, ans = %d\n", q1[i],q2[i],lca[i],d[lca[i]]);
	}
	return 0;
}

