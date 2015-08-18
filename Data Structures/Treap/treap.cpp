/*
Treap as RSQ. Finding sum on segment o(logN)
Adding element O(logN)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <ctime>
#include <cstdlib>

using namespace std;

struct node {
   node* l;
   node* r;
   int key;
   int prior;
   long long sum;   
};
typedef node* pnode;

pnode root, L, R, _x, M;
long long sum (pnode a) {return a ? a -> sum : 0;};

void upd (pnode a) {
   if (!a) return;
   a -> sum = a -> key + sum(a -> l) + sum(a -> r); 
}
void split (pnode v, int key, pnode& l, pnode& r) {
   if (!v) {
      l = r = 0;
      return;
   }
   if (v -> key < key) {
      l = v;
      split (v -> r, key, v -> r, r);
   }else {
      r = v;
      split (v -> l, key, l, v -> l);
   }
   upd(l); upd(r);
}
pnode merge (pnode a, pnode b) {
   if (!a) return b;
   if (!b) return a;
   pnode root;
   if (a -> prior < b -> prior) {
      root = a;
      a -> r = merge (a -> r, b);
   }else {
      root = b;
      b -> l = merge (a, b -> l);
   }
   upd(root);
   return root;
}
void out (pnode a) {
   if (!a) return;
   out(a -> l);
   printf ("%d %lld\n", a -> key, a -> sum);
   out(a -> r);
}
bool _find (pnode v, int x) {
   if (!v) return 0;
   split (v, x+1, L, R);
   split (L, x, L, M);
   bool ret = (M);
   L = merge (L, M);
   v = merge(L, R);
   return ret;
}
void add (int x) {
   if (_find (root,x)) return;
   _x = new node;   
   _x -> key = x;
   _x -> sum = x;
   _x -> prior = rand();
   if (!root) {
      root = new node;
      root = _x;
      return;
   }
   split(root, x, L, R);
   L = merge(L, _x);   
   root = merge (L, R);
} 
#define mod 1000000000
int main ()
{
   freopen ("sum2.in", "r", stdin);
   freopen ("sum2.out", "w", stdout);
   char tmp[20];
   int k, x, y;
   srand (time (0));
   long long pl = 0;
   pnode a, b;
   L = new node;
   R = new node;
   a = new node;
   b = new node;M = new node;
   cin >> k;
   for (int i = 0; i < k; i++) {
      scanf ("%s", tmp);
      if (tmp[0] == '+') {
         scanf ("%d", &x), add ((x+pl)%mod);
         pl = 0;
//         out(root);
//         cout << "---------added " << x << "---------------\n";
      }
      else  {
         scanf ("%d%d\n", &x, &y);
         split(root, y+1, L, R);
  //       cout << "-------splitted by " << y+1 << "----------\n";out(L);
         split(L, x, a, b);
         if (!b) pl = 0;
         else    pl = b -> sum;
//         cout << "-------splitted by " << x << "----------\n";out(b);
         printf ("%lld\n", pl);
         L = merge (a,b);
         root = merge (L, R);
//         cout << "-------normally ----------\n";out(root);
      }
   }
   
   return 0;
}

