#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = int(1e5+7);

struct car {
	int t, p, i;
	void make (int x, int y, int j) {
		t = x;
		p = y;
		i = j;
	}
	bool operator < (const car &x) const {
		return t < x.t;
	}
} a[2*maxn];

int p[2*maxn], f[maxn], sz, n;

void add (int x, int val) {
	for (; x <= n; x = x|(x+1)) f[x] += val;
}
int sum (int x) {
	int res = 0;
	for (; x > 0; x = (x&(x+1))-1) res += f[x];
	return res;
}
int KthMin (int k) {
	int l = -1, r = n, m;
	while (r - l > 1) {
		m = (l+r)/2;
		if (sum(m) >= k) r = m;
		else		 l = m;
	}
	return r;
}

void addTree (int v) {
	int k = sum (p[v]-1)+1;
	if (k > sz) k = 1;
	sz--;
	k = KthMin (k);
	p[v] = k;
	add (p[v], -1);
}

int main ()
{
	freopen ("parking.in", "r", stdin);
	freopen ("parking.out", "w", stdout);

	int m, N = 0;

	cin >> n >> m;
	sz = n;

	for (int i = 0; i < m; i++) {
		int ti, to, pl;
		cin >> ti >> to >> p[i];
                a[N++].make (ti, p[i], i);
                a[N++].make (to, -1, i);			
	}
	sort (a, a+N);
	for (int i = 1; i <= n; i++)	add (i, 1);

	for (int i = 0; i < N; i++) {
		if (a[i].p != -1) {
			addTree (a[i].i);
			
		}else {
			add (p[a[i].i], 1);
			sz++;
		}
	}
	for (int i = 0; i < m; i++)	cout << p[i] << '\n';

	return 0;
}