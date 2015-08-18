#include <iostream>

using namespace std;

int a[2000000];
int main ()
{
	freopen ("test.in", "r", stdin);
	freopen ("ans", "w", stdout);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)	scanf ("%d", &a[i]);
//	make_heap (a, a+n);
//	sort_heap (a, a+n);                               
        sort (a,a+n);
	for (int i = 0; i < n; i++)	cout << a[i] << " ";  
	return 0;
}
