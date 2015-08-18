/*
Bellman-Ford Algorithm  O(VE)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int N = 300000;
#define inf 1000000000
int p[N], f[N], t[N], w[N];
long long d[N];

int main ()
{
   freopen ("circle.in", "r", stdin);
   freopen ("circle.out", "w", stdout);
   
   int n;
   cin >> n;
   int m = 0, x;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
         cin >> x;
         f[m] = i, t[m] = j, w[m] = x; m++;
      }
   for (int i = 0; i < n; i++) d[i] = inf, p[i] = -1;
   d[0] = 0;
   for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
         if (d[f[j]] != inf && d[f[j]]+w[j] < d[t[j]]) d[t[j]] = d[f[j]] + w[j], p[t[j]] = f[j];
   // d[i] = min_distance from 0 to i
   /******Negative Cycle Searching********/
   int start = -1;
   for (int j = 0; j < m; j++)
      if (d[f[j]]+w[j] < d[t[j]])       start = f[j];
   if (start == -1) cout << "NO\n";
   else {
      int ans [N], c = 0;
      bool u[N]={0};
      for (int i = p[start]; i != -1 && !u[i]; i = p[i]) {
         ans[c++] = i+1;
         u[i] = 1;
         if (i == start) break;
      }
      cout << "YES\n";
      reverse (ans, ans+c);
      cout << c+1 << endl;
      for (int i = 0; i < c; i++)   cout << ans[i] << " ";
      cout << start+1 << " ";
   }
   
   return 0;
}

