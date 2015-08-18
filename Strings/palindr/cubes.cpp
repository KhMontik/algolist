#include <iostream>
#include <cstdio>

using namespace std;

const int N = 100500;
int n, m;
int a[2*N];
int d[2*N];

int main ()
{
   freopen ("cubes.in", "r", stdin);
   freopen ("cubes.out", "w", stdout);
   
   cin >> n >> m;
   int nn = n;
   for (int i = 0, j = nn-1; i < n; i++, j--)   scanf ("%d", a+i);
   a[nn] = -1;
   int l = 0, r = -1;
   for (int i = 0; i < nn; i++) {
      if (i > r)  d[i] = 0;
      else        d[i] = min(d[l+r-i+1], r-i+1)+1;
      while (i+d[i]-1 < nn && i-d[i] >= 0 && a[i+d[i]-1] == a[i-d[i]]) d[i]++;
      if (d[i])d[i]--;
      if (i == d[i]) printf ("%d ", nn-i);
      if (i+d[i]-1 > r) l = i-d[i], r = i+d[i]-1;
   }
   
   return 0;
}

