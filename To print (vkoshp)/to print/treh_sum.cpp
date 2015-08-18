E:\olymp\algo\data structure\fenwick_tree\treh_sum.cpp
#include <cstdio>
#include <iostream>
using namespace std;
int a[128][128][128], n, c, d, x, y, z, x1, y1, z1, x2, y2, z2;

void add(int x, int y, int z, int d)
{
	for (int i = x; i < 128; i |= i + 1)
		for (int j = y; j < 128; j |= j + 1)
			for (int k = z; k < 128; k |= k + 1)
				a[i][j][k] += d;
}

int getsum(int x, int y, int z)
{
	int res = 0;
	for (int i = x; i >= 0; i &= i + 1, i--)
		for (int j = y; j >= 0; j &= j + 1, j--)
			for (int k = z; k >= 0; k &= k + 1, k--)
				res += a[i][j][k];
	return res;
}

int main()
{
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);
	cin >> n;
	while (cin >> c)
	{
		if (c & 1)
		{
			cin >> x >> y >> z >> d;
			add(x, y, z, d);
		}
		else
		{
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			x1--, y1--, z1--;
			cout <<	(getsum(x2, y2, z2) - getsum(x2, y2, z1) - getsum(x1, y2, z2) + getsum(x1, y2, z1)) -
				(getsum(x2, y1, z2) - getsum(x2, y1, z1) - getsum(x1, y1, z2) + getsum(x1, y1, z1)) << endl;
		}
	}
}
