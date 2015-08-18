/*
MaxMatching with minimal weight
MinCostMaxFlow Algorithm using Dijkstra O(V^3)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

#define inf 1000000000
const int N = 500;
int c[N][N], f[N][N], a[N][N];
long long e[N], d[N];
int p[N];
bool u[N];
int n, s, t;

int main ()
{
   freopen ("matrix.in", "r", stdin);
   freopen ("matrix.out", "w", stdout);
   
   int nn;
   cin >> nn;
   for (int i = 0; i < nn; i++)
      for (int j = 0; j < nn; j++)
         cin >> a[i][j+nn], a[nn+j][i] = -a[i][j+nn], c[i][j+nn] = 1;
   n = nn+nn+2;
   s = n-2;
   t = n-1;
   for (int i = 0; i < nn; i++) c[s][i] = c[i+nn][t] = 1;
   for (int i = 0; i < n; i++) d[i] = inf;
   d[s] = 0;
   long long res = 0;
   for (int it = 0; it < n; it++) {
      for (int i = 0; i < n; i++) d[i] = inf;
      memset (u,0,sizeof(u));
      memset (p,-1,sizeof(p));
      d[s] = 0;
      int x = s;
      u[s] = 1;
      do{
         for (int i = 0; i < n; i++){
            long long w = d[x] + a[x][i] + e[x]-e[i];
            if (c[x][i]-f[x][i] > 0 && d[i] > w)
               d[i] = w, p[i] = x;
         }
         u[x] = 1;
         x = -1;
         for (int i = 0; i < n; i++)
            if (!u[i] && (d[i] < d[x] || x == -1))x = i;
      }while (x != -1);
      if (p[t] == -1) break;
      for (int i = 0; i < n; i++) e[i] += d[i];
      for (int i = t; i != s; i = p[i])
         f[p[i]][i]++, f[i][p[i]]--;
   }
   for (int i = 0; i < nn; i++)
      for (int j = 0; j < nn; j++)
         if (f[i][j+nn] == 1 ) res += a[i][j+nn]; 
   cout << res << endl;
   for (int i = 0; i < nn; i++)
      for (int j = 0; j < nn; j++)
         if (f[i][j+nn] == 1)
            printf ("%d %d\n", i+1,j+1);   
   
   return 0;
}

