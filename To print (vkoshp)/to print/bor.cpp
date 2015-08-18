#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
#define N 10000

map<char, int> q[N];
bool leaf[N];
int sz;

void add(char *s)
{
	int l = strlen(s);
	int v = 0;
	for (int i = 0; i < l; i++)
	if (q[v][s[i]]) v = q[v][s[i]]; else
		q[v][s[i]] = ++sz, v = sz;
	leaf[v] = true;
}

bool found(char *s)
{
	int l = strlen(s);
	int v = 0;
	for (int i = 0; i < l; i++)
		if (q[v][s[i]])
			v = q[v][s[i]];
		else
			return false;
	return leaf[v];
}

int main()
{
	char s[300];
	int n, m, i;
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d%d\n", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf("%s\n", s);
		add(s);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%s\n", s);
		if (found(s))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
