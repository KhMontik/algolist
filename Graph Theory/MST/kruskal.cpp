// Solution by Khamitbekov Madi
#include <iostream>

using namespace std;

struct Graph {
	int from, to, weight;
	bool operator < (const Graph &x) const {
		return (weight < x.weight);
	}
} a[70000];

int h[1000], p[1000]; // SNM

void Union (int x, int y) {
	if (h[x] > h[y]) p[y] = x;
	else		 p[x] = y;
	if (h[x] == h[y])h[y]++;
}
int find_set (int x) {
	if (x != p[x]) p[x] = find_set (p[x]);
	return p[x];
}


int main ()
{
	freopen ("kruskal.in", "r", stdin);
	freopen ("kruskal.out", "w", stdout);

	int n, i, j, m;
	int s = 0;

	cin >> n >> m;

	for (i = 0; i < n; i++) p[i] = i, h[i] = 0;     //SNM

	for (i = 0; i < m; i++) 	cin >> a[i].from >> a[i].to >> a[i].weight, a[i].from--, a[i].to--;

	sort (a, a+m);

	for (i = 0; i < m; i++) {
		int x = find_set (a[i].from); // SNM
		int y = find_set (a[i].to); // SNM
			if (x != y) {
				Union (x, y);
				cout<<a[i].from+1<<" "<<a[i].to+1<<" " << a[i].weight << endl;
				s += a[i].weight;
			}		
	}
	cout << s;


	return 0;
}
