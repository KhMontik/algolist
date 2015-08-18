/*
Simple problem of Games sum
Grandi function
*/
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int N = 150;
int n, m, s;

int d[N][N];

int calc (int n, int m) {
   if (d[n][m] != -1) return d[n][m];
   bool u[N]={0};
   memset (u,0,sizeof(u));
   for (int i = 1; i < n; i++)  u[calc(i,m)^calc(n-i,m)] = 1;
   for (int i = 1; i < m; i++)  u[calc(n,i)^calc(n,m-i)] = 1;
   for (int i = 0; ;i++)
      if (!u[i]) {d[n][m] = i;break;}
   return d[n][m];   
}

int main ()
{
   freopen ("choco.in", "r", stdin);
   freopen ("choco.out", "w", stdout);
   
   cin >> n >> m >> s; memset (d,-1,sizeof(d));
   for (int i = 1; i <= s; i++) d[1][i] = 0, d[i][1] = 0;
   printf (calc(n,m) ? "1" : "2");
   
   return 0;
}

