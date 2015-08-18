#include <cmath>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
using namespace std;

#define Fill(a, b) memset((a), (b), sizeof((a)))
typedef long long ll;
const ll inf = (ll)1e18;
const ll N = 510;
const ll M = 10010;

ll t[2 * M], nx[2 * M], f[2 * M], c[2 * M], s[N], pr[N], ind[N], q[N], n, m, v, u, w, l, r, p, mn, flow;
bool o[N];

void edge(ll v, ll u, ll w)
{
	t[l] = u;
	nx[l] = s[v];
	f[l] = 0;
	c[l] = w;
	s[v] = l++;
}

int main()
{
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);

	Fill(t, -1);
	Fill(s, -1);
	Fill(nx, -1);

	cin >> n >> m;

	while (m--)
	{
		cin >> v >> u >> w;
		edge(v,u,w);
		edge(u,v,0);
	}

	while (1)
	{
		Fill(o, 0);
		Fill(q, 0);
		Fill(pr, 0);
		Fill(ind, 0);
		q[0] = 1;
		l = 0;
		r = 1;
		o[1] = 1;
		while (l < r)
		{
			v = q[l++];
			p = s[v];
			while (p != -1)
			{
				u = t[p];
				if (!o[u] && (c[p] - f[p] > 0))
				{
					q[r++] = u;
					o[u] = 1;
					pr[u] = v;
					ind[u] = p;
				}
				p = nx[p];
			}
		}
		if (!o[n]) break;

		mn = inf;

		v = n;
		while (pr[v])
		{
			p = ind[v];
			mn = min(mn, c[p] - f[p]);
			v = pr[v];
		}

		flow += mn;

		v = n;
		while (pr[v])
		{
			p = ind[v];
			f[p] += mn;
			f[p ^ 1] -= mn;
			v = pr[v];
		}
	}

	cout << flow;
}
