/*
Finding point with max window intersection O(NlogN)
Scanline + RMQ
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100500;
const int nn = 262144*2;

struct scanline {
   int type, l, h, x;
   bool operator < (const scanline &a) const {
      return (x < a.x || (x == a.x && type > a.type));
   }    
} a[N];
struct node {
   int add, mx, id;
} t[4*nn+7], cur;

int n = 0;

node make (node a, node b) {
   return (a.mx > b.mx ? a : b);
}

void push (int v) {
   t[v].mx += t[v].add;
   if (v < nn) {
      t[v+v].add += t[v].add;
      t[v+v+1].add += t[v].add;
   }
   t[v].add = 0;
}

void upd (int l, int r, int x, int v = 1, int tl = 0, int tr = nn-1) {
   push (v);
   if (tl >= l && tr <= r) {
      t[v].add += x;
      push(v);
      return;
   }
   if (l > tr || tl > r) return; 
   int tm = (tl+tr) >> 1;
   upd (l, r, x, v+v, tl, tm);
   upd (l, r, x, v+v+1, tm+1, tr);
   t[v] = make (t[v+v], t[v+v+1]);
}
node get (int l, int r, int v = 1, int tl = 0, int tr = nn-1) {
   push(v);
   if (tl >= l && tr <= r) return t[v];
   if (l > tr || tl > r) return {0,-1131231,-1};
   int tm = (tl+tr) >> 1;
   return make (get(l,r,v+v,tl,tm), get(l,r,v+v+1,tm+1,tr));
}
int main ()
{
   freopen ("windows.in", "r", stdin);
   freopen ("windows.out", "w", stdout);
   
   int add = 200000;
   int k, x, y, x1, y1;
   cin >> k;
   for (int i = nn; i < nn+nn; i++) t[i].id = i-nn;
   for (int i = nn-1; i > 0; i--) t[i] = make(t[i+i], t[i+i+1]);
   for (int i = 0; i < k; i++) {
      scanf ("%d%d%d%d", &x,&y,&x1,&y1);
      a[n++] = {1, y+add, y1+add, x};
      a[n++] = {-1,y+add, y1+add,x1}; 
   }
   sort (a, a+n);
   int mx = 0, ansx = 0, ansy = 0;
   for (int i = 0; i < n; i++) {
   //   printf ("windows (%d-%d, %d) type %d\n", a[i].l, a[i].h, a[i].x, a[i].type);
      if (a[i].type == 1) {
       //  printf ("updating from %d to %d\n", a[i].l, a[i].h);
         upd (a[i].l, a[i].h, 1);
      //   for (int c = 0; c < 5; c++) printf ("%d ", get(c,c).mx);
    //     printf ("\n");
      }
      else {
         cur = get (a[i].l, a[i].h);
         upd (a[i].l, a[i].h, -1);
        // printf ("get max between [%d;%d] == %d, (%d,%d)\n", a[i].l, a[i].h,cur.mx,a[i].x,cur.id);
         if (cur.mx > mx) {
            mx = cur.mx;
            ansx = a[i].x;
            ansy = cur.id-add;
         }
      }
   }   
   cout << mx << endl << ansx << " " << ansy;
   return 0;
}

