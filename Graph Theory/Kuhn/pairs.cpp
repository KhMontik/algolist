/*
Simple Kuhn Algorithm O(VE)
Finding Maximal Matching
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

const int N = 300;
vector <int> a[N];
bool u[N];
int p[N];
int n, m;
bool dfs (int x) {
   if (u[x]) return 0;
   u[x] = 1;
   for (int i = 0; i < a[x].size(); i++) {
      int j = a[x][i];
      if (p[j] == -1 || dfs (p[j])) {
         p[j] = x;
         return 1;
      }
   }
   return 0;
}
int main ()
{
   freopen ("pairs.in", "r", stdin);
   freopen ("pairs.out", "w", stdout);
   
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      int x;
      while (cin >> x) {
         if (x == 0)break;
         x--;
         a[i].push_back (x);
      }
   }
   memset (p, -1, sizeof(p));
   for (int i = 0; i < n; i++) {
      memset (u,0,sizeof(u));
      dfs (i);
   }
   int c = 0;
   for (int i = 0; i < m; i++)
      if (p[i] != -1) c++;
   cout << c << endl;
   for (int i = 0; i < m; i++)
      if (p[i] != -1) cout << p[i]+1 << " " << i+1 << endl;
   return 0;
}

