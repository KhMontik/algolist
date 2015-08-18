/*
Finding max element and its index O(logN)
With function += x on segment O(logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

struct node {
   int add, mx, id;
} t[3*20000+7], cur, tmp;

int nn;

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
   assert(t[v].add == 0);
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

   char tmp[123];
   int x, l, r;
   cin >> nn;
   for (int i = nn; i < nn+nn; i++)   cin >> t[i].mx, t[i].id = i-nn;
   for (int i = nn-1; i >= 0; i--) t[i] = make (t[i+i],t[i+i+1]);
   for (;scanf("%s", tmp) > 0;) {
      if (tmp[0] == 'u') scanf ("%d%d%d", &l,&r,&x), upd(l-1,r-1,x);
      else               scanf ("%d%d", &l, &r), printf ("max[%d;%d] == %d, and its id = %d\n", l, r, get(l-1,r-1).mx, get(l-1,r-1).id+1);
      for (int i = 1; i < nn+nn; i++) {
         printf ("%d'th node: mx = %d, add = %d, id = %d\n", i, t[i].mx, t[i].add, t[i].id+1);
      }
   }
   return 0;
}
