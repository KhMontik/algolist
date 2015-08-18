/*
MinCost-k-Flow, problem "brides"
Ford-Bellman algorithm for searching min_path O(KVE)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

const int N = 300;
const int M = 20011;

struct edge {
   int a, b, f, c, w;
}e[M];
int n, m = 0;
vector <int> a[N];
int d[N], p[N];
bool u[M];
int ans[M];
void dfs (int x, int c = 0) {
   if (x == n-1) {
      printf ("%d ", c);
      for (int i = 0; i < c; i++)   printf ("%d ", ans[i]);
      printf ("\n");
      return;
   }
   for (int i = 0; i < m; i+=2)
      if (e[i].a == x) {
         if (e[i].c > 0 && e[i].f > 0 && !u[i]) {
            u[i] = 1, ans[c++] = i/4+1, dfs (e[i].b,c);
            break;
         }
      }  
}
int main ()
{
   freopen ("brides.in", "r", stdin);
   freopen ("brides.out", "w", stdout);
   
   int k, mm;
   int x, y, z;
   cin >> n >> mm >> k;
   for (int i = 0; i < mm; i++) {
      scanf ("%d %d %d", &x, &y, &z);
      x--, y--;
      e[m++] = edge {x,y,0,1,z};
      e[m++] = edge {y,x,0,0,-z};
      e[m++] = edge {y,x,0,1,z};
      e[m++] = edge {x,y,0,0,-z};
   }
   double ans = 0;
   for (int it = 0; it < k; it++) {
        memset (d,-1,sizeof(d));
        memset (p,-1,sizeof(p));
        d[0] = 0;
        for (int i = 0; i < n; i++)
          for (int j = 0; j < m; j++) 
            if (d[e[j].a] != -1 && e[j].c-e[j].f > 0)
               if (d[e[j].b] == -1 || d[e[j].b] > d[e[j].a]+e[j].w)
                  d[e[j].b] = d[e[j].a] + e[j].w, p[e[j].b] = j;
        if (p[n-1] == -1) {
            cout << -1;
            return 0;
        }
	for (int i = p[n-1]; i != -1; i = p[e[i].a]) {
            e[i].f++;
            e[i^1].f--;
            ans += e[i].w;   
        }            
   }
   ans /= k*1.0;
   printf ("%.5f\n", ans);
   for (int i = 0; i < k; i++) dfs (0);
   return 0;
}

