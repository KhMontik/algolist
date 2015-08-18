E:\olymp\algo\games\choco\choco.cpp
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <iostream>
using namespace std;

int n, m, s, i, j, k, g[101][101];
bool mex[101];

int main()
{
	freopen("choco.in", "r", stdin);
	freopen("choco.out", "w", stdout);
	cin >> n >> m >> s;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			g[i][j] = 0;
			if ((i == 1 && j <= s) || (j == 1 && i <= s))
			{
				continue;
			}
			memset(mex, 0, sizeof(mex));
			for (k = 1; k <= i / 2; k++)
			{
				mex[g[k][j] ^ g[i-k][j]] = 1;
			}
			for (k = 1; k <= j / 2; k++)
			{
				mex[g[i][k] ^ g[i][j-k]] = 1;
			}
			while (mex[g[i][j]]) g[i][j]++;
		}
	}

	if (g[n][m])
		cout << 1;
	else
		cout << 2;
}
