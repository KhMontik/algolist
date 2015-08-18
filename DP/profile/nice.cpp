#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define one(x,i) ((x)&(1<<i))

const int N = 50;
const int M = 1<<10;

int n, m, mm;
long long d[N][M];

void rec (int x, int j, int mask, int nx) {
   if (j == m) {
      d[x][mask] += d[x-1][nx];
      return;
   }
   if (j && one(mask,j) && one(mask,j-1) && one(nx,j-1)) rec (x,j+1,mask,nx);
   else if (j && !one(mask,j) && !one(mask,j-1) && !one(nx,j-1)) rec (x,j+1,mask,nx|(1<<j));
   else {
      rec (x,j+1,mask,nx);
      rec (x,j+1,mask,nx|(1<<j));
   }
}

int main ()
{
 // freopen ("nice2.in", "r", stdin);
  //freopen ("nice2.out", "w", stdout);
   
   cin >> n >> m;
   //if (n < m) swap (n,m);
   mm = 1<<m;
   for (int i = 0; i < mm; i++) d[0][i] = 1;
   for (int i = 1; i < n; i++)
      for (int j = 0; j < mm; j++)
         rec (i,0,j,0);
   long long res = 0;
   for (int i = 0; i < mm; i++) res += d[n-1][i];
   cout << res;
   return 0;
}

