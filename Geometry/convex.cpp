/*
Graham Algorithm finding convex hull O(NlogN)
Khamitbekov Madi
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

#define sq(x) ((x)*(x))

struct pt{
   int x, y;
   int operator * (pt a) {
      return x*a.y-y*a.x;
   }
   pt operator - (pt a) {
      pt r;
      r.x = x-a.x;
      r.y = y-a.y;
      return r;
   } 
   bool operator < (const pt &a) const {
      return (x < a.x || (x == a.x && y < a.y));
   }
   bool operator == (const pt &a) const {
      return (x == a.x && y == a.y);
   }
};
bool cmp (pt a, pt b) {
   return (a*b > 0 || (a*b == 0 && sq(a.x)+sq(a.y) < sq(b.x)+sq(b.y)));
}

int main ()
{
   freopen ("convex.in", "r", stdin);
   freopen ("convex.out", "w", stdout);
   
   int n;
   pt a[20006], base;
   int id = -1;
   cin >> n;
   for (int i = 0; i < n; i++)   {
      cin >> a[i].x >> a[i].y;
      if ((id == -1 || a[i].x > a[id].x || (a[i].x == a[id].x && a[i].y > a[id].y))) id = i;
   }   
   base = a[id];
   swap (a[id], a[0]);
   for (int i = 0; i < n; i++) a[i] = a[i] - base;
   sort (a,a+n,&cmp);
   n = unique (a,a+n)-a;
   pt ans[20006];
   int c = 0;
   ans[c++] = a[0];
   for (int i = 1; i < n;) {
      if (c < 2 || ((ans[c-1]-ans[c-2])*(a[i]-ans[c-2])) > 0) ans[c++] = a[i], i++;
      else     c--;
   }
   for (int i = 0; i < c; i++) ans[i].x += base.x, ans[i].y += base.y;
   sort (ans,ans+c,&cmp);
   cout << c << endl;
   for (int i = 0; i < c; i++)   cout << ans[i].x << " " << ans[i].y << endl;
   return 0;
}

