/*
Simple example of games on tree O(N)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>

using namespace std;

const int N = 200007;

int d[N], c[N];
vector <int> a[N];
int n;

int dfs (int x, int lvl = 0) {
   if (lvl%2 == 0) d[x] = c[x];
   else            d[x] = 1000000007;
   for (int i = 0; i < a[x].size(); i++) {
      int j = a[x][i];
      if (lvl%2 == 0) d[x] = max (d[x], dfs(j,lvl+1));
      else            d[x] = min (d[x], dfs(j,lvl+1));
   }
   if (d[x] == 1000000007) d[x] = c[x];
   return d[x];
}
int main ()
{
   freopen ("chocorev.in", "r", stdin);
   freopen ("chocorev.out", "w", stdout);

   cin >> n;
   for (int i = 0; i < n; i++) {
      int x;
      scanf ("%d%d", &x, &c[i]);x--;
      a[x].push_back (i);
   }
   cout << dfs(0);
   return 0;
}

