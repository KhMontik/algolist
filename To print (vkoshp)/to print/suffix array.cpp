#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

const int N = 100000;

int m, p[N], seg[2][N];
string s;

void digital(int k, int n)
{
	int i, t[N], c[N], v[N];
	memset(c, 0, sizeof(c));
	memset(v, 0, sizeof(v));
	memset(t, 0, sizeof(t));

	for (i = 0; i < n; i++)
	{
		c[seg[k][i]]++;
	}

	for (i = 0; i < N; i++)
	{
		v[i+1] = c[i];
        c[i+1] += c[i];
	}

	for (i = 0; i < n; i++)
	{
		t[v[seg[k][p[i]]]++] = p[i];
	}

	for (i = 0; i < n; i++)
	{
		p[i] = t[i];
	}
}

void suffix_array()
{
	int i, x, k = 1, n = s.length(), c[n];

	for (i = 0; i < n; i++)
	{
		c[i] = s[i] - 33;
		p[i] = i;
	}

	while (k < n)
	{
		for (i = 0; i < n; i++)
		{
			seg[0][i] = c[i];
			seg[1][i] = c[(i + k) % n];
		}
		digital(1, n);
		digital(0, n);
		x = 0;
		for (i = 0; i < n; i++)
		{
			if (i && (seg[0][p[i]] != seg[0][p[i-1]] || seg[1][p[i]] != seg[1][p[i-1]])) x++;
			c[p[i]] = x;
		}
		k <<= 1;
	}
	printf("%d\n", p[0]);
}

int main()
{
	freopen("shifts.in", "r", stdin);
	freopen("shifts.out", "w", stdout);
	scanf("%d\n", &m);
	while (m--)
	{
		getline(cin,s);
		suffix_array(); // make suffix array for string "s"
	}
}
