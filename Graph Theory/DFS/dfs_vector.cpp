// Solution by Khamitbekov Madi
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define sz size()
#define pb push_back

using namespace std;

int n;
vector <int> a[999];
bool u[999];

void dfs (int v) {
	u[v] = 1;
	for (int i = 0; i < a[v].sz; i++) 
		if (!u[a[v][i]]) dfs (a[v][i]);
}

int main ()
{
	freopen ("dfs.in", "r", stdin);
	freopen ("dfs.out", "w", stdout);
	
	int i, j, k = 0, m, x, y;

	scanf ("%d %d", &n, &m);

	for (i = 0; i < m; i++) {
		scanf ("%d %d", &x, &y);
		a[x-1].pb (y-1);
		a[y-1].pb (x-1);
	}
	for (i = 0; i < n; i++)
		if (!u[i]) {
			dfs (i);
			k++;
		}

	cout << k;

	
	return 0;
}

