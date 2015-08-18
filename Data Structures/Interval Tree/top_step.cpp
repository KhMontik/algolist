/*
Finding maximal 10101.... segment length O(1)
Updating element O(logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 262144;

struct node {
   int ans;
   int suf0, suf1;
   int pre0, pre1;
}a[4*N];
int n;

void upd (int i) {
   i += N-1;
   if (a[i].suf0) a[i].suf1 = a[i].pre1 = 1, a[i].suf0 = a[i].pre0 = 0;
   else           a[i].suf0 = a[i].pre0 = 1, a[i].suf1 = a[i].pre1 = 0;
   int sz = 1;
   i >>= 1;
   while (i) {
      a[i].pre0 = a[i+i].pre0;
      a[i].pre1 = a[i+i].pre1;
      a[i].suf0 = a[i+i+1].suf0;
      a[i].suf1 = a[i+i+1].suf1;
      a[i].ans = max (a[i+i].suf0+a[i+i+1].pre1, a[i+i].suf1+a[i+i+1].pre0);
      if (a[i+i].pre0 == sz) {
         if (a[i+i].pre0&1) a[i].pre0 = a[i+i].pre0 + a[i+i+1].pre1;
         else               a[i].pre0 = a[i+i].pre0 + a[i+i+1].pre0;
      }
      if (a[i+i].pre1 == sz) {
         if (a[i+i].pre1&1) a[i].pre1 = a[i+i].pre1 + a[i+i+1].pre0;
         else               a[i].pre1 = a[i+i].pre1 + a[i+i+1].pre1;
      }
      if (a[i+i+1].suf0 == sz) {
         if (a[i+i+1].suf0&1) a[i].suf0 = a[i+i].suf1 + a[i+i+1].suf0;
         else                 a[i].suf0 = a[i+i].suf0 + a[i+i+1].suf0;
      }
      if (a[i+i+1].suf1 == sz) {
         if (a[i+i+1].suf1&1) a[i].suf1 = a[i+i].suf0 + a[i+i+1].suf1;
         else                 a[i].suf1 = a[i+i].suf1 + a[i+i+1].suf1;
      }
      a[i].ans = max (a[i].ans, a[i+i].ans);
      a[i].ans = max (a[i].ans, a[i+i+1].ans);
      a[i].ans = max (a[i].ans, a[i].suf0);  
      a[i].ans = max (a[i].ans, a[i].suf1);
      a[i].ans = max (a[i].ans, a[i].pre0);
      a[i].ans = max (a[i].ans, a[i].pre1);
   //   printf ("i = %d, ans = %d, pre0 = %d, pre1 = %d, suf0 = %d, suf1 = %d, sz = %d\n", i, a[i].ans, a[i].pre0, a[i].pre1, a[i].suf0, a[i].suf1, sz);
      i >>= 1; sz += sz;
   }
}

int main ()
{
   freopen ("step.in", "r", stdin);
   freopen ("step.out", "w", stdout);
   
   int k;
   cin >> n >> k;
   int lvl = 1;
   for (int i = N; i < N+n; i++) a[i].ans = a[i].suf0 = a[i].pre0 = 1;
   for (int i = N-1; i > 0; i--) {
      a[i].suf0 = a[i+i+1].suf0, a[i].suf1 = a[i+i+1].suf1; 
      a[i].pre0 = a[i+i].pre0, a[i].pre1 = a[i+i].pre1;
      a[i].ans = max (a[i+i].ans, a[i+i+1].ans);
   }     
   int x;
   for (int i = 0; i < k; i++) {
      scanf ("%d", &x);
      upd(x);
      printf ("%d\n", a[1].ans);
   }   
   return 0;
}

