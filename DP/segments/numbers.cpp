#include <iostream>
#include <cstdio>

using namespace std;

const int N = 177;
#define inf 1LL<<60
int n;
int a[N];
long long d[N][N];

long long calc (int l, int r) {
   if (r-l <= 1) return 0;
   if (d[l][r] != inf) return d[l][r];
   for (int i = l+1; i < r; i++) {
      long long res = calc (l,i) + calc (i,r) + (a[l]+a[r])*a[i];
      if (d[l][r] == inf || d[l][r] > res) d[l][r] = res;
   }
   return d[l][r];
}

int main ()
{ 
   freopen ("numbers.in", "r", stdin);
   freopen ("numbers.out", "w", stdout);
   
   cin >> n;
   for (int i = 0; i < n; i++)   
      for (int j = 0; j < n; j++) d[i][j] = inf;
   for (int i = 0; i < n; i++) cin >> a[i];
   cout << calc (0,n-1);
   return 0;
}

