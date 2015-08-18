/*
Fenwick-Sum 3D O(log^3N)
Khamitbekov Madi
*/
#include <iostream>
#include <cstdio>

using namespace std;

#define nx(x) ((x)|((x)+1))
#define pr(x) ((x)&((x)+1))

const int N = 130;

long long t[N][N][N];
int n;

void upd (int x, int y, int z, int add) {
   for (int i = x; i < n; i = nx(i))
      for (int j = y; j < n; j = nx(j))
         for (int k = z; k < n; k = nx(k))
            t[i][j][k] += add;
}
long long sum (int x, int y, int z) {
   long long res = 0;
   for (int i = x; i >= 0; i = pr(i)-1)
      for (int j = y; j >= 0; j = pr(j)-1)
         for (int k = z; k >= 0; k = pr(k)-1)
             res += t[i][j][k];
   return res;
}
long long sum (int x, int y, int z, int x1, int y1, int z1) {
   long long res = sum(x1,y1,z1);
   x--, y--, z--;
   res -= sum(x,y1,z1);
   res -= sum(x1,y,z1);
   res -= sum(x1,y1,z);
   res += sum(x,y,z1);
   res += sum(x,y1,z);
   res += sum(x1,y,z);
   res -= sum(x,y,z);
   return res;
}

int main ()
{
   freopen ("stars.in", "r", stdin);
   freopen ("stars.out", "w", stdout);
   int x, y, z, add, x1, y1, z1, type;
   cin >> n;
   while (scanf ("%d", &type) > 0) {
      if (type == 1) {
         scanf ("%d %d %d %d", &x,&y,&z,&add);
         upd(x,y,z,add);
      }
      if (type == 2) {
         scanf ("%d%d%d%d%d%d", &x,&y,&z,&x1,&y1,&z1);
         printf ("%lld\n", sum(x,y,z,x1,y1,z1));
      }
      if (type == 3) break;
   }
   
   return 0;
}

