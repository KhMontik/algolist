/*
Solution of classic problem "Domino"
Euler Tour Algorithm O(E)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>

using namespace std;

const int N = 1007;
const int M = 1000500;
int a[N][N];
int dg[N];
int n;
int r[M];
int sz = 0;

void euler (int x) {
   for (int i = 0; i < n; i++) {
      if (a[x][i]) {
         a[x][i]--, a[i][x]--, dg[x]--, dg[i]--;
         euler(i);
      }
   }
   r[sz++] = x+1;
}
int main ()
{
   freopen ("domino.in", "r", stdin);
   freopen ("domino.out", "w", stdout);
   int k, x, st = -1, t;
   cin >> n;
   for (int i = 0; i < n; i++) {
      cin >> dg[i];
      for (int j = 0; j < dg[i]; j++) {
         cin >> x >> t;
         x--;
         a[i][x]++;
         st = x;
      }
   }
   int odd = 0;
   for (int i = 0; i < n; i++)
      if (dg[i]%2 == 1) odd++, st = i;
   if (odd > 2) {
      cout << -1;
      return 0;
   }
   euler (st);
   for (int i = 0; i < n; i++)
      if (dg[i]) {
         cout << -1;
         return 0;
      }
   cout << sz-1 << endl;
   for (int i = 0; i < sz; i++)
      cout << r[i] << " ";
   return 0;
}

