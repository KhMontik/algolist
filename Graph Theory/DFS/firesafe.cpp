/*
Condense of Graph, finding base of graph O(E)
Khamitbekov Madi
*/
#pragma comment (linker, '/STACK:64000000')
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 3007;
const int M = 100500;
vector <int> a[N], g[N];
int c[N]={0};
int n;
int top[N], tn;
void tops (int x) {
   c[x] = 1;
   for (int i = 0; i < a[x].size(); i++) 
      if (!c[a[x][i]]) tops (a[x][i]);
   top[--tn] = x;
}
int cc = 1;
void dfs (int x) {
   c[x] = cc;
   for (int i = 0; i < g[x].size(); i++) 
      if (!c[g[x][i]]) dfs (g[x][i]);
}
int dg[N];
int main ()
{
   freopen ("firesafe.in", "r", stdin);
   freopen ("firesafe.out", "w", stdout);
   int m , x, y;
   cin >> n >> m;
   tn = n;  
   for (int i = 0; i < m; i++) 
      scanf ("%d %d", &x, &y), a[x-1].push_back(y-1), g[y-1].push_back(x-1);
   for (int i = 0; i < n; i++)
      if (!c[i]) tops (i);
   for (int i = 0; i < n; i++) c[i] = 0;
   for (int i = 0; i < n; i++) 
      if (!c[top[i]]) dfs (top[i]), cc++; 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < a[i].size(); j++) {
         int x = a[i][j];
         if (c[i] != c[x]) dg[c[i]]++;
      }
   }
   int ans = 0;
   for (int i = 1; i < cc; i++)
      if (!dg[i]) ans++;
   cout << ans << endl;
   for (int i = 0; i < n; i++)
      if (!dg[c[i]])    cout << i+1 << " ", dg[c[i]] = 1;
   return 0;
}
