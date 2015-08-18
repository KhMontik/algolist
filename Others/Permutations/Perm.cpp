#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, a[100];

void print ()
{
	for (int i = 0; i < n; i++)	cout << a[i] << " ";
	cout << endl;
}

void perm (int m)
{
	if (m == n)	print();
	else {
		for (int i = m; i < n; i++) {
			swap (a[m], a[i]);
			perm (m+1);
			swap (a[m], a[i]);
		}
	}
}

int main ()
{
	freopen ("perm.in", "r", stdin);
	freopen ("perm.out", "w", stdout);

	cin >> n;

	for (int i = 0; i < n; i++) scanf ("%d", &a[i]);

	sort (a, a+n);

	perm (0);

	return 0;
}
