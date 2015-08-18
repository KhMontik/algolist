// Solution by Khamitbekov Madi
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> a, t;
int n;

#define nx(x) ((x) | (x+1))
#define pr(x) ((x) & (x+1))

int sum (int r) {
	int res = 0;
	for (; r >= 0; r = pr(r)-1)res += t[r];
	return res;
}
void update (int i, int val) {
	for (; i < n; i = nx(i)) t[i] += val;
}

void make_tree (vector <int> a) {
	t.resize (a.size());
	n = a.size();
	for (int i = 0; i < n; i++) t[i] = 0;
	for (int i = 0; i < n; i++) update (i, a[i]);
}

int main ()
{
	freopen ("sum.in", "r", stdin);
	freopen ("sum.out", "w", stdout);

	int n, m, i, x, l, r;

	scanf ("%d", &n);

	a.resize(n);

	for (i = 0; i < n; i++) scanf ("%d", &a[i]);
	make_tree (a);
	scanf ("%d", &m);
	for (i = 0; i < m; i++) {
		scanf ("%d %d", &l, &r);
		l--, r--;
		printf ("%d\n", sum(r) - (l > 0 ? sum(l-1) : 0));
	}

	return 0;
}



