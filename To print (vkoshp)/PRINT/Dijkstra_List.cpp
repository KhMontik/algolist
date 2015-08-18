// Solution by Khamitbekov Madi
#include <iostream>
#include <cstdio>
#include <vector>
#define pb push_back

using namespace std;

int n, d[999];
bool u[999];
vector <int> a[999];
vector <int> w[999];

void Dijkstra (int v) {
	int i, x;

	fill (u, u+n+1, 0);
	fill (d, d+n+1, 999);
	
	d[v] = 0;
	x = -1;

	do {
		if (x != -1) {
			for (i = 0; i < a[x].size(); i++)  
				if (!u[a[x][i]]) d[a[x][i]] = min (d[a[x][i]] , d[x] + w[x][i]);
		}
		u[x] = 1;
		x = -1;
		for (i = 0; i < n; i++) 
			if ((x == -1 || d[x] > d[i]) && !u[i]) x = i;
	}while (x != -1);
}

int main ()
{
	freopen ("Dijkstra.in", "r", stdin);
	freopen ("Dijkstra.out", "w", stdout);

	int i, j, s, t, m;
	int x, y, z;

	scanf ("%d %d %d %d", &n, &s, &t, &m);

	for (j = 0; j < m; j++)	{
		scanf ("%d %d %d", &x, &y, &z);
		a[x-1].pb (y-1);
		w[x-1].pb (z);	
	}

	s--;t--;
	Dijkstra (s);

	printf ("%d", d[t]);
	return 0;
}
