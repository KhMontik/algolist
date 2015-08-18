#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

#define pb push_back

const int N = 260;

vector<int> g[N];
int i, j, n, m, cnt, r[N];
bool w[N];

bool dfs(int i)
{
	if (w[i]) return 0;
	w[i] = 1;

	for (int j = 0; j < g[i].size(); j++)
	if (!r[g[i][j]] || dfs(r[g[i][j]]))
	{
		r[g[i][j]] = i;
		return 1;
	}
	return 0;
}

int main()
{
	freopen("pairs.in", "r", stdin);
	freopen("pairs.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		while (j)
		{
			g[i].pb(j);
			scanf("%d", &j);
		}
	}

	for (i = 1; i <= n; i++)
	{
		if (dfs(i)) cnt++;
		memset(w, 0, sizeof(w));
	}

	printf("%d\n", cnt);
	for (i = 1; i <= m; i++)
	if (r[i]) printf("%d %d\n", r[i], i);
}
