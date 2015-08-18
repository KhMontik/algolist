/*
Solution of problem contest (LKSH 2011 August A')
2-SAT Algortihm O(E)
Khamitbekov Madi
*/
#pragma comment (linker, '/STACK:64000000')
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 200507;
const int M = 200500;
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
int p[N];
int main ()
{
   freopen ("contest.in", "r", stdin);
   freopen ("contest.out", "w", stdout);
   int m, x, y, in;
   cin >> n >> m;
   in = n;
   n += n;
   tn = n;
   for (int i = 0; i < in; i++) {
      scanf ("%d %d", &x, &y); 
      x--, y--;
      p[x] = y;
      p[y] = x;
   }
   for (int i = 0; i < m; i++) {
      scanf ("%d %d", &x, &y); x--, y--;
      a[x].push_back (p[y]);
      a[y].push_back (p[x]);
      g[p[y]].push_back (x);
      g[p[x]].push_back (y);
   }
   for (int i = 0; i < n; i++)
      if (!c[i]) tops (i);
   for (int i = 0; i < n; i++) c[i] = 0;
   for (int i = 0; i < n; i++) 
      if (!c[top[i]]) dfs (top[i]), cc++;
   for (int i = 0; i < n; i++) {
      if (c[i] == c[p[i]]) {
         cout << -1;
         return 0;
      }
   }
   for (int i = 0; i < n; i++)
      if (c[i] > c[p[i]])  cout << i+1 << " ";
   return 0;
}
