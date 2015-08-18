/*
Finding k-th grandi function
Finding first move of solution
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

const int N = 100007;

vector <int> a[N], id[N];
int d[N];
int dfs (int x, int pr = -1) {
   for (int i = 0; i < a[x].size(); i++) 
      if (pr != a[x][i])
      d[x] ^= (dfs(a[x][i], x)+1);      
   return d[x];
}
void find (int x, int k, int pr = -1) {
   for (int i = 0; i < a[x].size(); i++) {
      if (a[x][i] == pr) continue;
      int xr = d[x]^(d[a[x][i]]+1)^k;
      if (d[a[x][i]]+1 > xr) {
         if (xr == 0) {
            cout << id[x][i];
            exit(0);
         }
         find(a[x][i], xr-1,x);
      }
   }
}

int main ()
{
   freopen ("woodcut.in", "r", stdin);
   freopen ("woodcut.out", "w", stdout);
   
   int n, root, x, y;   
   cin >> n >> root;
   for (int i = 0; i < n-1; i++) {
      scanf ("%d %d", &x, &y), x--, y--, a[x].push_back (y), a[y].push_back(x);   
      id[x].push_back (i+1);
      id[y].push_back (i+1);
   }
   if (!dfs(root-1)) cout << 2;
   else {
      cout << 1 << endl;
      find (root-1,0);      
   }
   return 0;
}

