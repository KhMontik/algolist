#include <algorithm>
#include <iostream>
#include <string.h>
#include <utility>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>   
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

#define abs(x) ((x) > 0 ? (x) : -(x))
#define all(v) (v).begin(), (v).end()
#define sq(x) ((x)*(x))
#define len length()
#define pb push_back
#define mp make_pair
#define inf 7777777
#define sz size()
#define s second
#define mod 1743
#define f first
 
int a[511101], n;

int kth_min (int l, int r, int k) {
	int i = l, j = r, x = a[(l+r)>>1];
	do {
		while (i <= r && a[i] < x) i++;
		while (l <= j && a[j] > x) j--;
		if (i <= j) {
			swap (a[i], a[j]);
			i++, j--; 
		}
	}while (i <= j);	
	if (k <= j) return kth_min (l, j, k);
	if (i <= k) return kth_min (i, r, k);
	return a[k];
}
int f (int x) {
	return (132*(sq(x%mod)%mod*x%mod)%mod + (77 * sq(x%mod)%mod)%mod + (1345*(x%mod)%mod) + 1577)%mod;
}

int main ()
{
	freopen ("kth.in", "r", stdin);
	freopen ("kth.out", "w", stdout);

	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)	a[i] = f(i+1);
	cout << kth_min (0, n-1, k-1);


	return 0;
}
    
