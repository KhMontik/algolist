#include <iostream>

using namespace std;

int s[1100], n, q, a[1110];

bool check () {
	int S = a[0];
	for (int i = 1; i < n; i++) 
		S += (s[i-1] == 1 ? a[i] : -a[i]);
	
	if (S == q)	return 1;
	return 0;
}

void print () {
	for (int i = 0; i < n; i++) // cout << s[i];
//	cout << endl;
		cout << a[i] << (i != n-1 ?  ((s[i] == 1) ? "+" : "-") : "="); 
	cout << q << endl;

	exit(0);
}

void rec (int x) {
	if (x == n-1) {if (check()) print();}
	else {
		s[x] = 2;rec(x+1);
		s[x] = 1;rec(x+1);
	}	
}

int main ()
{
	freopen ("expr.in", "r", stdin);
	freopen ("expr.out", "w", stdout);

	int i;

	cin >> n >> q;

	for (i = 0; i < n; i++)	cin >> a[i];

	rec (0);

	cout << "No solution";
	return 0;
}