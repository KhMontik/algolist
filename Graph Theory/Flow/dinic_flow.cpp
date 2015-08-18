/*
Simple MaxFlow Problem
Dinic Algorithm O(V^2E)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

const int N = 600;
long long c[N][N], f[N][N];
vector <int> a[N];
bool u[N];
int p[N];
int d[N];
int n, m;
int q[N*1000];
int l, r;
bool bfs (int s, int t) {
   memset (d,-1,sizeof(d));
   memset (p,-1,sizeof(p));
   d[s] = 0;
   l = r = 0;
   q[r++] = s;
   while (l < r) {
      int x = q[l];
      l++;
      for (int j = 0; j < a[x].size(); j++) {
         int i = a[x][j];
         if (c[x][i]-f[x][i] > 0 && d[i] == -1) {
            d[i] = d[x] + 1;
            p[i] = x;
            q[r++] = i;
         }
      }
   }
   return p[t] != -1;
}
int tmp[N];
#define inf 1000000007
long long dfs (int x, long long flow) {
   //cout << "here x = " << x +1 << " and flow " << flow << endl;
   if (flow <= 0) return 0;
   if (x == n-1) return flow;
   //u[x] = 1;
   for (int &j = tmp[x]; j < a[x].size(); j++) {
      int i = a[x][j];
      if (d[x] == d[i]-1) {
    //     cout << " go to " << i+1 << " with " << min(c[x][i]-f[x][i],flow) << endl; 
         long long push = dfs (i, min(c[x][i]-f[x][i],flow));
      //   cout << push << endl;
         if (push) {
            f[x][i] += push;
            f[i][x] -= push;
            return push;
         } 
      }
   }
   return 0;
}
long long MaxFlow (int s, int t) {
   long long flow = 0;
   while (bfs (0,n-1)) {
   //   cout << n  <<" = n\";
     // for (int i = 0; i < n; i++)   cout << i << " = " << d[i] << " \n";
      //cout << endl;
      memset (tmp, 0, sizeof(tmp));
      while (long long push = dfs (0,inf)) flow += push;
      //cout << flow << endl;
   }
   return flow;
}
int main ()
{
   freopen ("flow.in", "r", stdin);
   freopen ("flow.out", "w", stdout);
   
   int x, y, w;
   cin >> n >> m;
   for (int i = 0; i < m; i++) {
      scanf ("%d%d%d", &x,&y,&w);
      x--, y--;
      a[x].push_back (y);
      c[x][y] += w;
   }
   cout << MaxFlow (0,n-1);
   
   return 0;
}

