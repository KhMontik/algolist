/*
Simple Dijkstra Algorithm O(V^2)
Khamitbekov Madi
*/
#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string.h>

using namespace std;

#define inf (1LL<<60)
const int N = 235347;

int n;
vector < pair <int, int> > a[N];
long long d[N];
bool u[N];

void dijkstra (int v) {
   for (int i = 0; i < n; i++) d[i] = inf, u[i] = 0;
   d[v] = 0;
   u[v] = 1;
   do {
      for (int i = 0; i < a[v].size(); i++) {
         int to = a[v][i].second;
         int w = a[v][i].first;
         if (d[to] > d[v] + w) d[to] = d[v] + w;
      }
      u[v] = 1;
      v = -1;
      for (int i = 0; i < n; i++)
         if (!u[i] && (v == -1 || d[v] > d[i])) v = i;
   }while (v != -1);
}

int main ()
{
   int x, y, z, m;
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      scanf ("%d%d%d", &x,&y,&z);
      x--, y--;
      a[x].push_back ( make_pair (z,y) );
   }
   int s = 0; // source
   dijkstra(s);
   int t = n-1; // final vertex
   cout << d[t];
   return 0;
}

