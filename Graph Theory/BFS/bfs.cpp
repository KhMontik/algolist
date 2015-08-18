// Solution by Khamitbekov Madi
#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[999][999], d[999], p[999], n;
bool u[999];
queue <int> q;

void bfs (int v) {
	int i, x;

	u[v] = 1;
	q.push (v);
	while (!q.empty()) {
		x = q.front();
		q.pop ();

		for (i = 0; i < n; i++)	{
			if (a[x][i] > 0 && !u[i]) {
				q.push (i);
				u[i] = 1;
				p[i] = x;
				d[i] = d[x] + 1;
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

	int i, j, s, t;

	scanf ("%d", &n);

	fill (p, p+n+1, -1);

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++)
			scanf ("%d", &a[i][j]);
	scanf ("%d %d", &s, &t);
	s--;t--;
	
	bfs (s);
	printf ("%d\n", d[t]);
	PrintPath (t);

	return 0;
}
