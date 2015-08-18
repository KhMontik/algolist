E:\olymp\algo\data structure\treap\kthmax\kthmax_dn_decard_tree.cpp
#include <cstdio>
#include <cstdlib>
#define N 100001

struct decart_tree
{
	int l[N], r[N], s[N], x[N], y[N], root, n;

	decart_tree()
	{
		root = n = l[0] = r[0] = s[0] = x[0] = y[0] = 0;
	}

	void cnt(int v)
	{
		s[v] = s[l[v]] + s[r[v]] + 1;
	}

	void split(int v, int u)
	{
		if (!v)
		{
			cnt(u);
			return;
		}
		if (x[v] > x[u])
		{
			split(l[v], u);
			l[v] = r[u];
			cnt(v);
			r[u] = v;
			cnt(u);
		}
		else
		{
			split(r[v], u);
			r[v] = l[u];
			cnt(v);
			l[u] = v;
			cnt(u);
		}
	}

	int add(int v, int u)
	{
		if (!root)
		{
			cnt(u);
			return u;
		}
		if (y[v] > y[u])
		{
			if (x[v] > x[u])
			{
				l[v] = add(l[v], u);
				cnt(v);
				return v;
			}
			else
			{
				r[v] = add(r[v], u);
				cnt(v);
				return v;
			}
		}
		else
		{
			split(v, u);
			return u;
		}
	}

	int merge(int v, int u)
	{
		if (!v || !u) return v+u;
		if (y[v] > y[u])
		{
			r[v] = merge(r[v], u);
			cnt(v);
			return v;
		}
		else
		{
			l[u] = merge(v, l[u]);
			cnt(u);
			return u;
		}
	}

	int del(int v, int k)
	{
		if (x[v] == k)
			return merge(l[v], r[v]);
		if (x[v] > k)
		{
			l[v] = del(l[v], k);
			cnt(v);
			return v;
		}
		else
		{
			r[v] = del(r[v], k);
			cnt(v);
			return v;
		}
	}

	int kthmax(int v, int k)
	{
		int next = s[r[v]] + 1;
		if (next == k) return x[v]; else
		if (next > k) return kthmax(r[v], k); else
			     return kthmax(l[v], k - next);
	}

	void add(int k)
	{
		l[++n] = r[n] = s[n] = 0;
		x[n] = k; y[n] = rand();
		root = add(root, n);
	}

	void del(int k)
	{
		root = del(root, k);
	}

	void kth(int k)
	{
		printf("%d\n", kthmax(root, k));
	}
} tr;

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int c, m, k;
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d%d", &c, &k);
		switch (c)
		{
			case  0 : tr.kth(k); break;
			case  1 : tr.add(k); break;
			case -1 : tr.del(k); break;
		}
	}
}
