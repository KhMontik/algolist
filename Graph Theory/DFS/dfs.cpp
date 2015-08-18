// Solution by Khamitbekov Madi
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[999][999], n;
bool u[999];

void dfs (int v) {
	u[v] = 1;
	for (int i = 0; i < n; i++) 
		if (!u[i] && a[v][i] > 0) dfs (i);
}

int main ()
{
	freopen ("dfs.in", "r", stdin);
	freopen ("dfs.out", "w", stdout);
	
	int i, j, k = 0;

	scanf ("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> a[i][j];
	for (i = 0; i < n; i++)
		if (!u[i]) {
			dfs (i);
			k++;
		}

	cout << k;

	
	return 0;
}

