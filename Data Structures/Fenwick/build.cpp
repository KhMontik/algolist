#include <iostream>
#include <cstdio>

using namespace std;

#define nx(x) ((x)|((x)+1))
#define pr(x) ((x)&((x)+1))

const int N = 100500;

int t[N];
int s[N];
int n, k;
void upd (int i, int x) {
   for (; i < n; i = nx(i)) t[i] += x;
}
int sum (int i) {
   int res = 0;
   for (; i >= 0; i = pr(i)-1) res += t[i];
   return res;
}
int sum (int l, int r) {
   return sum(r) - sum(l-1);
}
int main()
{   
   int type, x, y;
   int a[N];
   cin >> n >> k;
   for (int i = 0; i < n; i++) scanf ("%d", &a[i]), s[i] += a[i], s[i+1] += s[i];
   for (int i = 0; i < n; i++) t[i] = s[i]-s[pr(i)-1];
   for (int i = 0; i < k; i++) {
      scanf ("%d%d", &type, &x);
      if (type == -1) upd(x-1,-1);
      if (type == 1) upd (x-1, 1);
      if (type == 0) {
         scanf ("%d", &y);
         x--, y--;
         printf ("%d\n", sum(x,y));
      }
   }   
   return 0;
}

