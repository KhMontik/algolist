#include <iostream>
#include <fstream>

using namespace std;

int n, a[2000000];

void add (int x) {
	a[n++] = x; 	
}
void heap_up () {
	int i = n-1;
	while (i > 0) swap (a[i], a[(i-1)/2]), i = (i-1)/2;
}


int main ()
{
	freopen ("heapsort.in", "r", stdin);
	freopen ("heapsort.out", "w", stdout);

	int N;
	cin >> N;

	add (1);
        for (int i = 2; i <= N; i++) {
		heap_up ();
		add (i);
		swap (a[0], a[n-1]);
	}

	for (int i = 0; i < n; i++)	cout << a[i] << " ";
	return 0;
}
