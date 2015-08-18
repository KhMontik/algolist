/*
Finding solution to n linear expressions
Gauss Method O(N^3)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
#define abs(x) ((x)>0?(x):-(x))
vector < vector < long double > > a;

int main ()
{
   freopen ("gauss.in", "r", stdin);
   freopen ("gauss.out", "w", stdout);
   int n;
   cin >> n;
   a.resize(n);
   for (int i = 0; i < n; i++)    a[i].resize(n+1);
   
   for (int i = 0; i < n; i++)
      for (int j = 0; j <= n; j++)  cin >> a[i][j];
   for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = i+1; j < n; j++)
         if (abs(a[j][i]) > abs(a[k][i])) k = j;
      swap (a[k], a[i]);
      for (int j = i+1; j <= n; j++) a[i][j] /= a[i][i];
      for (int j = 0; j < n; j++)
         if (j != i) {
            for (int k = i+1; k <= n; k++) a[j][k] -= a[i][k]*a[j][i];
         }
   }
   cout << fixed;
   cout.precision(20);
   for (int i = 0; i < n; i++)   cout << a[i][n] << " ";
   
   return 0;
}

