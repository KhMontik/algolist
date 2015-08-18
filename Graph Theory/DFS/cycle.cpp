/*
Finding Simple Cycle of Graph O(E)
Khamitbekov Madi
*/
#pragma comment (linker, '/STACK:64000000')
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int const N = 20007;

vector <int> a[N];
int u[N]={0};
int n;
void dfs (int x) {
   u[x] = 1;
   for (int i = 0; i < a[x].size(); i++) {
      int j = a[x][i];
      if (u[j] == 1){
         cout << "YES";
         exit(0);
      }
      if (!u[j]) dfs(j);
   }
   u[x] = 2;
}
int main ()
{
   freopen ("cycle.in", "r", stdin);
   freopen ("cycle.out", "w", stdout);
   int m, x, y;
   cin >> n >> m;  
   for (int i = 0; i < m; i++) 
      scanf ("%d %d", &x, &y), a[x-1].push_back(y-1), a[y-1].push_back(x-1);
   for (int i = 0; i < n; i++)
      if (!u[i]) dfs (i);
   cout << "NO";
   return 0;
}
