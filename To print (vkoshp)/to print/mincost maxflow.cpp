#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

const int N = 210;
const int M = 8010;
const int inf = 1<<30;

long long Time;
int l, i, j, n, m, k, p, path[N], phi[N], start[N], end[M], weight[M], next[M], ind[M], capacity[M], flow[M], v[M / 4], u[M / 4], w[M / 4];

void ford_bellman()
{
	int i, j;
	phi[1] = 0;
	for (i = 2; i <= n; i++)
	{
		phi[i] = inf;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (phi[v[j]] != inf)
			{
				phi[u[j]] = min(phi[u[j]], phi[v[j]] + w[j]);
			}
			if (phi[u[j]] != inf)
			{
				phi[v[j]] = min(phi[v[j]], phi[u[j]] + w[j]);
			}			
		}
	}
}

void edge(int v, int u, int w, int c, int p)
{
	end[l] = u;
	weight[l] = w;
	next[l] = start[v];
	ind[l] = p;
	capacity[l] = c;
	flow[l] = 0;
	start[v] = l++;
}

bool push_flow()
{
	int i = 1, j, k, p, dist[n+1], prev[n+1], edge[n+1], Flow;
	bool was[n+1];
	memset(was, 0, sizeof(was));
	
	for (k = 0; k <= n; k++)
	{
		dist[k] = inf;
	}
	dist[1] = 0;
	prev[1] = 0;

	for (k = 1; k < n; k++) // dijkstra
	{
		p = start[i];
		was[i] = 1;
		while (p != -1)
		{
			j = end[p];
			if (!was[j] && capacity[p] - flow[p] > 0 && dist[i] + (weight[p] + phi[i] - phi[j]) < dist[j])
			{
				dist[j] = dist[i] + (weight[p] + phi[i] - phi[j]);
				prev[j] = i;
				edge[j] = p;
			}
			p = next[p];
		}

		i = 0;
		for (j = 1; j <= n; j++)
		{
			if (!was[j] && dist[j] < dist[i])
			{
				i = j;
			}
		}

		//if (i == n) break;
		if (!i) return false;
	}

	for (i = 1; i <= n; i++) // update potentials
	{
//		if (dist[i] != inf)
//		{
			phi[i] += dist[i];
//		}
	}

	Flow = inf;

	j = n;
	while (prev[j])
	{
		p = edge[j];
		Flow = min(Flow, capacity[p] - flow[p]);
		j = prev[j];
	}

	j = n;
	while (prev[j])
	{
		p = edge[j];
		Time += weight[p];
		flow[p] += Flow;
		flow[p ^ 1] -= Flow;
		j = prev[j];
	}

	return true;
}

int main()
{
	freopen("brides.in", "r", stdin);
	freopen("brides.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &k);

	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &v[i], &u[i], &w[i]);
	}

	ford_bellman();

	memset(start, -1, sizeof(start));
	memset(next, -1, sizeof(next));

	for (i = 0; i < m; i++)
	{
		edge(v[i], u[i], w[i], 1, i+1);
		edge(u[i], v[i], -w[i], 0, 0);
		edge(u[i], v[i], w[i], 1, i+1);
		edge(v[i], u[i], -w[i], 0, 0);
	}

	for (i = 0; i < k; i++)
	{
		if (!push_flow())
		{
			printf("-1");
			exit(0);
		}
	}
/*
	for (i = 1; i <= l; i++)
	{
		if (flow[i] > 0)
		{
			Time += weight[i];
		}
	}
*/
	printf("%.5lf\n", 1.0 * Time / k);

	while (k--)
	{
		i = 1;
		l = 0;
		while (i != n)
		{
			p = start[i];
			while (p != -1)
			{
				if (flow[p] > 0)
				{
					flow[p] = 0;
					path[l++] = ind[p];
					i = end[p];
					break;
				}
				p = next[p];
			}
		}
		printf("%d ", l);
		for (i = 0; i < l; i++)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}

	return 0;
}
