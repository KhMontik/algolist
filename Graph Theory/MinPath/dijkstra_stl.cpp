/*
Dijkstra with priority_queue O(ElogV)
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
priority_queue < pair <long long, int> > q;

void dijkstra (int v) {
   for (int i = 0; i < n; i++) d[i] = inf;
   d[v] = 0;
   q.push ( make_pair (0, v) );
   while (!q.empty()) {
      int w = q.top().first;
      int x = q.top().second;
      q.pop();
      if (d[x] < w)continue;
      for (int i = 0; i < a[x].size(); i++) {
         int to = a[x][i].first;
         long long w = a[x][i].second;
         if (d[to] > d[x] + w){
            d[to] = d[x] + w;
            q.push (make_pair (d[to], to));
         }
      }
   }  
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

