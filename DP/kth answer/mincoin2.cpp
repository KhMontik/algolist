#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstdlib>

using namespace std;

const int N = 2000;
#define maxK 2000000001
int n, w, k, ww;
int d[N][N];
unsigned long long c[N][N];
int a[N];
int cc = 0;
void out (int i, int w, int k) {
   if (i == n) {
      assert (cc == d[0][ww]);      
      exit(0);
   }
   if (d[i+1][w] < d[i+1][w-a[i]]+1 || w-a[i] < 0) out (i+1,w,k);
   else if (d[i+1][w] > d[i+1][w-a[i]]+1) printf ("%d ", i+1), cc++, out(i+1,w-a[i],k);
   else {
      if (k <= c[i+1][w-a[i]]) printf ("%d ", i+1), cc++, out (i+1,w-a[i],k);
      else                     out(i+1,w,k-c[i+1][w-a[i]]);
   }
}

int main ()
{
   freopen ("mincoin2.in", "r", stdin);
   freopen ("mincoin2.out", "w", stdout);
   cin >> n >> w >> k;ww = w;
   for (int i = 0; i < n; i++)   cin >> a[i];
   c[n][0] = 1;
   for (int i = 1; i <= w; i++) d[n][i] = maxK;
   for (int i = n-1; i >= 0; i--)
      for (int j = w; j >= 0; j--) {
         if (j-a[i] >= 0){
            if (d[i+1][j] > d[i+1][j-a[i]]+1)
               d[i][j] = d[i+1][j-a[i]]+1,c[i][j] = c[i+1][j-a[i]];
            else if (d[i+1][j] == d[i+1][j-a[i]]+1) {
               d[i][j] = d[i+1][j], c[i][j] = c[i+1][j]+c[i+1][j-a[i]];
               if (c[i][j] > maxK) c[i][j] = maxK;
            }
         }
         if (j-a[i] < 0 || d[i+1][j] < d[i+1][j-a[i]]+1) {
            d[i][j] = d[i+1][j];
            c[i][j] = c[i+1][j];
         } 
      }
   if (d[0][w] >= maxK) cout << -1;
   else {
      cout << d[0][w] << endl;
      out(0,w,k);
   }
   return 0;
}
