/*
Solution of Problem about 2 horses 
BFS Algorithm O(E)
Khamitbekov Madi
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define sq(x) ((x)*(x))

int d[9][9][9][9];

struct A{
   int x, y, x1, y1;
   A (int a, int b, int c, int d) {
      x = a, y = b, x1 = c, y1 = d;
   }
};

queue <A> q;

bool ok (int x, int y, int x1, int y1) {
   return (x >= 0 && y >= 0 && x1 >= 0 && y1 >= 0 && x < 8 && y < 8 && x1 < 8 && y1 < 8);
}

int dd[8][2] = {-2,1,-2,-1,-1,2,-1,-2,1,-2,1,2,2,1,2,-1};
int main ()
{
   freopen ("twohorse.in", "r", stdin);
   freopen ("twohorse.out", "w", stdout);
   char qq, w, e, r;
   cin >> qq >> w >> e >> r;
   int x = qq-'a', y = w-'1';
   int x1 = e-'a', y1 = r-'1';
   memset (d, -1, sizeof(d));
   d[x][y][x1][y1] = 0;
   q.push (A(x,y,x1,y1));
   while (!q.empty()) {
      x = q.front().x;
      y = q.front().y;
      x1 = q.front().x1;
      y1 = q.front().y1;
      //cout << x << " " << y << " " << x1 << " " << y1 << endl;
      q.pop();
      for (int i = 0; i < 8; i++)
         for (int j = 0; j < 8; j++) {
            int xx = dd[i][0] + x;
            int yy = dd[i][1] + y;
            int xx1 = dd[j][0] + x1;
            int yy1 = dd[j][1] + y1;
            if (!ok(xx,yy,xx1,yy1)) continue;
            if (d[xx][yy][xx1][yy1] == -1) d[xx][yy][xx1][yy1] = d[x][y][x1][y1] + 1, q.push ( A (xx,yy,xx1,yy1));
         }             
   }   
   int res = 1000;
   for (int i = 0; i < 8; i++)
      for (int j = 0; j < 8; j++)
         if (d[i][j][i][j] != -1) res = min (res, d[i][j][i][j]);
   if (res == 1000) cout << -1;
   else        cout << res; 
   return 0;
}

