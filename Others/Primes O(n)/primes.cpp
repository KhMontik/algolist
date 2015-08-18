#include <iostream>

using namespace std;

const int MAXN = 100000000;

int lsp[MAXN+7];
int pr[MAXN+7];

int main ()
{
	freopen ("primes.in", "r", stdin);
	freopen ("primes.out", "w", stdout);

	int n;
	cin >> n;
	int pc = 0;
	pr[pc++] = 2;
	lsp[2] = pc;
	for (int i = 3; i <= n; i += 2) {
		if (!lsp[i]) {
			pr[pc++] = i;
	//		cout << i << " ";
			lsp[i] = pc;
		}
		for (int j = 0; j < lsp[i]; j++) {
			int t = pr[j]*i;
			if (t <= n)lsp[t] = j+1;
			else break;
		}
	}
	cout << pc;


	return 0;
}
