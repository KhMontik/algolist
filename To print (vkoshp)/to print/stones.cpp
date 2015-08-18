E:\olymp\algo\games\stones\stones.cpp
#include <stdio.h>
#include <cstdlib>
#include <iostream>
using namespace std;

bool d[101];
int i, j, n;

int main()
{
	freopen("stones.in", "r", stdin);
	freopen("stones.out", "w", stdout);
	cin >> n;
	d[0] = 0;
	for (i = 1; i <= n; i++)
	{
		j = i % 3;
		switch (j)
		{
			case 0 : d[i] = (!d[i-1]) | (!d[max(i-2,0)]); break;
			case 1 : d[i] = (!d[i-1]) | (!d[max(i-3,0)]); break;
			case 2 : d[i] = (!d[i-1]) | (!d[max(i-2,0)]) | (!d[max(i-3,0)]); break;
		}
	}
	if (d[n])
	{
		cout << 1;
	}
	else
	{
		cout << 2;
	}
}
