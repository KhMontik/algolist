#include <cmath>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

double r, x;
int i, j, k, n;
vector<double> a[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		a[i].push_back(0);
		for (j = 0; j <= n; j++)
		{
			cin >> x;
			a[i].push_back(x);
		}
	}
	for (k = 1; k <= n; k++)
	{
		if (!a[k][k])
		{
			for (i = k+1; i <= n; i++)
			if (a[i][k])
			{
				swap(a[k], a[i]);
				break;
			}
		}
		r = a[k][k];
		for (j = k; j <= n+1; j++)
			a[k][j] /= r;
		for (i = 1; i <= n; i++) if (i != k)
		{
            r = -a[i][k];
			for (j = k; j <= n+1; j++)
				a[i][j] = r * a[k][j] + a[i][j];
        }
	}
	for (i = 1; i <= n; i++)
		cout << floor(a[i][n+1] + 0.5) << " ";
}
