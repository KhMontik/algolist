E:\olymp\algo\dynamic\by profile\nice\nice_dn.cpp
#include <iostream>
using namespace std;

int calc(int,int);
long long ans=0;
int n, m, deg, i, j, k, x, y, can[64][64], d[32][32];

int calc(int x, int y)
{
	for (k = 0; k < n-1; k++)
		if (((x >> k   & 1 > 0) +
		     (y >> k   & 1 > 0) +
		     (x >> k+1 & 1 > 0) +
		     (y >> k+1 & 1 > 0)) % 4 == 0) return 0;
	return 1;
}

int main()
{
	freopen("nice.in", "r", stdin);
   	freopen("nice.out", "w", stdout);

	cin >> n >> m;

	if (n > m) swap(n, m); 

	deg = 1 << n;

	for (i = 0; i < deg; i++)
		for (j = 0; j < deg; j++)
			can[i][j] = calc(i, j);

	for (i = 0; i < deg; i++)
		d[0][i] = 1;

	for (i = 1; i < m; i++)
		for (x = 0; x < deg; x++)
			for (y = 0; y < deg; y++)
				d[i][y] += (can[x][y] * d[i-1][x]);

	for (i = 0; i < deg; i++)
		ans += d[m-1][i];

  	cout << ans;
}