/*
Finding max-min on segment O(logN)
Update 1 element O(logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 131072;
const int mod1 = 12345;
const int mod2 = 23456;

int f(int n) {
   long long res = n, r = n;
   res = res%mod1;
   res = res*(n%mod1);
   res %= mod1;
   r %= mod2;
   r = r*(n%mod2);  r %= mod2;
   r = r*(n%mod2);  r %= mod2;
   res += r;
   return int(res);
}

int mx[2*N+7], mn[2*N+7];

void upd (int i, int x) {
   i += N-1;
   mn[i] = mx[i] = x;
   i >>= 1;
   while (i) {
      mx[i] = max(mx[i+i], mx[i+i+1]);
      mn[i] = min(mn[i+i], mn[i+i+1]);
      i >>= 1;
   }
}
int get (int l, int r) {
   l += N-1;
   r += N-1;
   int mxx = -N, mnn = N;
   while (l <= r) {
      if (l&1)     mxx = max(mxx, mx[l]), mnn = min(mnn, mn[l]), l++;
      if (r%2 == 0)mxx = max(mxx, mx[r]), mnn = min(mnn, mn[r]), r--;
      l >>= 1;
      r >>= 1;
   }
   return mxx-mnn;
}
int main ()
{
   freopen ("rvq.in", "r", stdin);
   freopen ("rvq.out", "w", stdout);
   
   int k, x, y;
   for (int i = N; i < N+N; i++) {
      mn[i] = mx[i] = f(i-N+1);
   }
   int ans1=-N, ans2=N;
   for (int i = N-1; i > 0; i--) mn[i] = min (mn[i+i], mn[i+i+1]), mx[i] = max(mx[i+i], mx[i+i+1]);
   cin >> k;
   for (int i = 0; i < k; i++) {
      scanf ("%d%d", &x, &y);
      if (x < 0) upd (-x,y);
      else       printf ("%d\n", get(x,y));
   }
   return 0;
}

