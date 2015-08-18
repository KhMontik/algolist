#include <iostream>

using namespace std;

int a[7000000], i;
int main ()
{
	freopen ("antiqs.in", "r", stdin);
	freopen ("test.in", "w", stdout);

	int n;

	cin >> n;
	cout << n << endl;

	for (i = 1; i <= n; i++)	a[i] = i;

	for (i = 3; i <= n; i++) 	swap (a[(i+1)/2], a[i]);

	for (i = 1; i <= n; i++)	cout << a[i] << " ";
	return 0;
}
