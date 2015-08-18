/*
Finding Cut Points of Graph O(E)
Khamitbekov Madi
*/
#pragma comment (linker, '/STACK:64000000')
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 20007;

vector <int> a[N], id[N];
int tin[N], fup[N];
bool u[N]={0};
int n;
int c = 1;
int ans[N], anss = 0;
void dfs (int x, int pr = -1) {
   u[x] = 1;
   int t = 0;
   tin[x] = fup[x] = c++;
   for (int i = 0; i < a[x].size(); i++) {
      int j = a[x][i];
      if (j == pr) continue;
      if (u[j]) fup[x] = min(fup[x], tin[j]);
      else {
         t++;
         dfs (j,x);
         fup[x] = min (fup[x], fup[j]);
         if (fup[j] >= tin[x] && pr != -1) ans[x] = 1;
      } 
   }
   if (pr == -1 && t > 1) ans[x] = 1;
}
int main ()
{
   freopen ("points.in", "r", stdin);
   freopen ("points.out", "w", stdout);
   int m , x, y;
   cin >> n >> m;  
   for (int i = 0; i < m; i++) {
      scanf ("%d %d", &x, &y), a[x-1].push_back(y-1), a[y-1].push_back(x-1);
      id[x-1].push_back (i), id[y-1].push_back(i); 
   }
   for (int i = 0; i < n; i++)
      if (!u[i]) dfs (i);
   for (int i = 0; i < n; i++)
      if (ans[i]) anss++;
   printf ("%d\n", anss);
   for (int i = 0; i < n; i++) 
      if (ans[i])  printf ("%d\n", i+1);  
   return 0;
}
