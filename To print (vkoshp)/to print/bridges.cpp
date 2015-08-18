#include <cmath>
#include <vector>
#include <stdio.h>
#define pb push_back
#define mp make_pair
using namespace std;

const int N = 20001;
vector< pair<int,int> > g[N];
int n, m, i, k, v, u, cnt, l[N], d[N];
bool bridge[N*10];

void dfs(int v, int pr) {
	d[v] = ++k;
	l[v] = n;
	for (vector< pair<int,int> >::iterator u = g[v].begin(); u != g[v].end(); u++)
	if (!d[u->first]) {
		dfs(u->first, v);
		l[v] = min(l[v], l[u->first]);
		if (d[v] < l[u->first]) bridge[u->second] = 1;
	} else
	if (pr != u->first)
		l[v] = min(l[v], d[u->first]);
}

int main() {
	freopen("bridges.in", "r", stdin);
	freopen("bridges.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &v, &u);
		g[v].pb(mp(u,i));
		g[u].pb(mp(v,i));
	}
	for (i = 1; i <= n; i++)
		if (!d[i]) dfs(i, i);
	for (i = 1; i <= m; i++)
		cnt += bridge[i];
	printf("%d\n", cnt);
	for (i = 1; i <= m; i++)
		if (bridge[i]) printf("%d\n", i);
}
