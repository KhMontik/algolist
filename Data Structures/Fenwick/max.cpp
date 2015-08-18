// Solution by Khamitbekov Madi
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#define inf (100000000)

using namespace std;

vector <int> t;
vector <int> a;
int n;

#define nx(x) ((x) | (x+1))
#define pr(x) ((x) & (x+1))

int getmin (int r) {                     	
	int res = -inf;                 	
	for (; r >= 0; r = pr(r)-1) 
		res = max (res, t[r]);
	return res;
}
void update (int i, int val) {
	for (; i < n;  i = nx(i))
		t[i] = max (t[i], val);
}

void make_tree (vector <int> a) {
	t.resize (a.size());
	n = a.size();
	for (int i = 0; i < t.size(); i++) t[i] = -inf;
	for (int i = 0; i < a.size(); i++) update (i, a[i]);
}

int main ()
{
	freopen ("max.in", "r", stdin);
	freopen ("max.out", "w", stdout);

	int i, nn, m;

	scanf ("%d", &nn);	
	a.resize(nn);
	for (i = 0; i < nn; i++)    scanf ("%d", &a[i]);

	make_tree (a);

	scanf ("%d\n", &m);

	for (i = 0; i < m; i++) {
		int x, y;
		scanf ("%d", &x);
		x--;
		printf ("%d\n", getmin (x));
	}

	return 0;
}
