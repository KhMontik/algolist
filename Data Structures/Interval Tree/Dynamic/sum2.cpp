/*
Sum on segment     0...10^9
Adding new element 0...10^9
RMQ with zipping vertexes O(logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 7777777;
const int NN = 1<<30;

struct node {
   int l, r;
   long long sum;
} t[N];
int sz = 2;

void add (int x, int v = 1, int tl = 0, int tr = NN-1) {
   if (tl == tr) {
      t[v].sum = x;
      return;
   }
   int tm = (tl+tr) >> 1;
   if (x <= tm) {
      if (!t[v].l) t[v].l = sz++;
      add (x, t[v].l, tl, tm);
   }
   else  {
      if (!t[v].r) t[v].r = sz++;
      add (x, t[v].r,tm+1,tr);
   }
   t[v].sum = t[t[v].l].sum + t[t[v].r].sum;
}
long long get (int l, int r, int v = 1, int tl = 0, int tr = NN-1) {
   if (l > tr || tl > r || !v) return 0;
   if (tl >= l && tr <= r) return t[v].sum;
   int tm = (tl+tr) >> 1;
   return get(l,r,t[v].l,tl,tm) + get(l,r,t[v].r,tm+1,tr);
}
#define mod 1000000000
int main ()
{
   freopen ("sum2.in", "r", stdin);
   freopen ("sum2.out", "w", stdout);
   
   int k, x, y;
   char s[20];
   long long ans = 0;
   cin >> k;
   for (int i = 0; i < k; i++) {
      scanf ("%s", s);
      if (s[0] == '+') scanf ("%d", &x), add((x+ans)%mod), ans = 0;
      else             scanf ("%d%d", &x,&y), ans = get(x,y), printf("%lld\n", ans), ans %= mod;
   }
   
   return 0;
}

