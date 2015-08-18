// Solution by Khamitbekov Madi
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define sz size()
#define pb push_back

using namespace std;

int d[999], p[999], n;
bool u[999];
queue <int> q;
vector <int> a[999];

void bfs (int v) {
	int i, x;
	u[v] = 1;
	q.push (v);

	while (!q.empty()) {
		x = q.front();
		q.pop ();

		for (i = 0; i < a[x].sz; i++)	{
			if (!u[a[x][i]]) {
				q.push (a[x][i]);
				u[a[x][i]] = 1;
				p[a[x][i]] = x;
				d[a[x][i]] = d[x] + 1;
			}
		}	
	}
}
void PrintPath (int x)
{
	if (p[x] != -1)	PrintPath (p[x]);
	printf ("%d ", x+1);	 

}

int main ()
{
	freopen ("bfs.in", "r", stdin);
	freopen ("bfs.out", "w", stdout);

	int i, j, s, t, m, x, y;

	scanf ("%d %d", &n, &m);
	  
	fill (p, p+n+1, -1);

	for (i = 0; i < m; i++) { 
		scanf ("%d %d", &x, &y);
		a[x-1].pb (y-1);
		a[y-1].pb (x-1);
	}
	scanf ("%d %d", &s, &t);
	s--;t--;
	
	bfs (s);
	printf ("%d\n", d[t]);
	PrintPath (t);

	return 0;
}
