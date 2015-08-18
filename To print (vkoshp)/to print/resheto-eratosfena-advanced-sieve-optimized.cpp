#include <cstdio>
#include <cmath>

using namespace std;

const int MAXN = 100000000;

int leastPrime[MAXN + 1];
int primes[MAXN];

int advancedSieve(int n) {
	int primesCount = 0;
	primes[primesCount++] = 2;
	for (int i = 3; i <= n; i += 2) {
		if (!leastPrime[i]) {
			primes[primesCount++] = i;
			leastPrime[i] = primesCount;
		}
		for (int j = 1; j < leastPrime[i]; ++j) {
			int t = primes[j] * i;
			if (t <= n) leastPrime[t] = j + 1;
			else break;
		}
	}
	return primesCount;
}

int main() {
	int n; scanf("%d", &n);
	printf("%d\n", advancedSieve(n));
	return 0;
}
